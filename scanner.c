//////////////////////////////////////////////
//		Copmiler Construction (CS F363)		//
//			Programming Assignment 1		//
// 2011A7PS225H, 2011C6PS491H, 2011C6PS599H //
//////////////////////////////////////////////


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	//Defining keywords
	char *keys[21]={"if","else","repeat","while","function","for","in","next","break","TRUE","FALSE","NULL","Inf","NaN","NA","NA_integer_","NA_real_","NA_complex_","NA_character_","order","rev"};

	//Defining data types
	char *data_types[4]={"matrix","data.frame","list","factor"};

	char *gouping[4]={
		"(",")","{","}"
	};

	char *delimit={";"};

	//Defining operators
	char *operators[7][6]={
		{"+","-","*","%%"},
		{">",">=","<","<=","==","!="},
		{"!","|"},
		{"~"},
		{"->","<-"},
		{"$"},
		{":"}
	};

	//Defining type of operator
	char *type[30]={"TK_op_arithmetic","TK_op_relational","TK_op_logical","TK_op_modelf","TK_op_assignment","TK_op_indexing","TK_op_sequence"};

	int line_number=0;
	size_t len=0;
	ssize_t read;
	char *line=NULL;
	int flag=0;
	char *token;
	int i=0,j=0,k=0;

	printf("Names: Raghav Dave, S*aksham Sahai, Sidhant Panda\n");
	printf("Input: %s\n",argv[1]);
	printf("Line\tType\tLexeme\n");
	printf("----------------------\n");

	FILE *source;
	source=fopen(argv[1],"r");

	while ((read = getline(&line, &len, source)) != -1)
	{
		
	}
	
	// printf("%d\n",line_number );
  	fclose(source);
	return 0;
}