//////////////////////////////////////////////
//		Copmiler Construction (CS F363)		//
//			Programming Assignment 1		//
// 2011A7PS225H, 2011C6PS491H, 2011C6PS599H //
//////////////////////////////////////////////


#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	//Defining keywords
	char *keys[19]={"if","else","repeat","while","function","for","in","next","break","TRUE","FALSE","NULL","Inf","NaN","NA","NA_integer_","NA_real_","NA_complex_","NA_character_"};

	//Defining data types
	char *data_types[4]={"matrix","data.frame","list","factor"};

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

	char ch;
	int line_number=0;

	FILE *source;
	source=fopen(argv[1],"r");

	/*
	Logic Here
	*/

  	fclose(source);
	return 0;
}