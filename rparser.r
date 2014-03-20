parser <- function( file, encoding = "unknown", text ){
	# go to a temporary file to deal with the text argument, 
	# functions and connections  (I know it is ugly)
	if( !missing( text ) ){
		file <- tempfile( );
		cat( text , file = file, sep = "\n" )
	} else if( inherits(file,"function") ){
		source <- attr( file, "source" )
		if( is.null(source ) ){
			source <- deparse( file )
		}
		file <- tempfile( )
		writeLines( source, file )
	} else if( inherits( file, "connection" ) ){
		sc <- summary( file )
		text <- readLines( file )
		file <- tempfile()
		writeLines( text, file )
	}
	
	# this is where the actual work takes place
	p <- .External( "do_parser", file = file, encoding = encoding )
	
	# formatting the results a bit
	data <- as.data.frame( t(attr(p,"data")) )
	colnames( data ) <- c( "line1", "col1", "byte1", 
		 	"line2", "col2", "byte2", "token", "id", "parent" )
	
	data[["top_level"]] <- .Call( "top_level", data$parent, PACKAGE = "parser" )
	
	# populate token.desc and terminal
	m <- match( data$token, grammar_symbols$token )
	data$token.desc <- as.character(grammar_symbols$desc)[ m ]
	data$terminal <- grammar_symbols$terminal[m]
	
	# go back to C to grab the actual tokens
	data$text     <- character( nrow(data) )
	toks <- getTokens( data= data[ data$terminal, , drop = FALSE], 
		encoding = encoding, file = file, 
		sort = FALSE )
	data$text[ match( toks$id, data$id) ] <- toks$text
	attr( p, "data" ) <- data
	attr( p, "file" ) <- file
	attr( p, "encoding") <- encoding
	oldClass( p ) <- "parser"
	p
}
getChilds <- function( x, i = 0, 
	parent = sapply( x[i], function(.) attr(.,"id" ) ) ){
	
	if(missing(parent) && ( missing(i) || is.null(i) || i==0 ) ){
		return( attr(x, "data")[,'id'] )
	}
	all.childs <- c()
	data    <- attr( x, "data" )
	parents <- abs( data[, "parent"] )
	id      <- data[, "id" ]
	childs  <- function( index ){
		kids <- id[ parents %in% index ]
		if( length(kids) ){
			all.childs <<- c( all.childs, kids )
			childs( kids )
		}
	}
	childs( parent )
	sort( all.childs )
}

getDirectChilds <- function( x, parent = 0, data = attr(x, "data") ){
	parents <- abs( data[, "parent"] )
	id      <- data[, "id" ]
	id[ parents %in% parent ]
}

isTerminal <- function(x, id = 0, data = attr(x, "data") ){
	terminal  <- data[["terminal"]]
	ids       <- data[["id"]]
	if( ! id %in% ids ){
		FALSE
	} else{
		terminal[ ids %in% id ]
	}
}
getTokens <- function( x, 
	data = attr( x, "data" )[ attr(x, "data")[["terminal"]], ], 
	encoding = attr( x, "encoding"), 
	file = attr( x, "file" ), 
	sort = TRUE ){
	
	if( sort ){
		data <- data[ do.call( order, data[, c("line1", "col1") ] ), ]
	} else{
		if( is.unsorted(data[["line1"]] ) ){
			stop( "data is not in increasing order of line1" )
		}
	}
	data.frame( id = data[, "id"], 
		text = .External( "do_getTokens", 
			file = file, 
			encoding = encoding, 
			line1 = data[, "line1" ], 
			col1  = data[, "byte1"  ], 
			line2 = data[, "line2" ], 
			col2  = data[, "byte2"  ],
            PACKAGE="parser"), 
		stringsAsFactors = FALSE
		)
	
}
NULL