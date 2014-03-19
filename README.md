#Compiler for R programming language written in C
This repo is a small implementation of scanners and parsers written in C to analyze code in R programming language.

##Constants
NULL : Empty object  
NA : Not available  
Inf : Inifity  
NaN : Not-a-Number ( result of 0/0 or 1/0 etc)  
Logical constants are either TRUE or FALSE  

##Identifiers
Sequence of letters, digits, period ('.') and underscore
#####Identifiers can not start with a digit, underscore or a period followed by a digit

##Reserved Words
if
else
repeat
while
function
for
in
next
break
TRUE
FALSE
NULL
Inf
NaN
NA
NA_integer_
NA_real_
NA_complex_
NA_character_

##Operator Tokens
Arithmetic	+ - * / %% ^  
Relational > >= < <= == !=  
Logical ! & |  
Model Formulae ~  
Assignment -> <-  
List indexing $  
Sequence :  

##Grouping
Ordinary '('  ')'  
Braces '{'  '}' to delimit blocks of expressions

##Indexing
'['   ']'