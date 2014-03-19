//////////////////////////////////////////////
//		Copmiler Construction (CS F363)		//
//			Programming Assignment 1		//
// 2011A7PS225H, 2011C6PS491H, 2011C6PS599H //
//////////////////////////////////////////////


#include<stdio.h>
int main(int argc,char *argv[])
{
	// Defining keywords
	char keys[19][10]={"if","else","repeat","while","function","for","in","next","break","TRUE","FALSE","NULL","Inf","NaN","NA","NA_integer_","NA_real_","NA_complex_","NA_character_"};
	char *operators[7][6]={
		{"+","-","*","%%"},
		{">",">=","<","<=","==","!="},
		{"!","|"},
		{"~"},
		{"$"},
		{":"}
	};
	char *type[30]={"TK_op_arithmetic","TK_op_relational","TK_op_logical","TK_op_modelf","TK_op_assignment","TK_op_indexing","TK_op_sequence"};
	// printf("%s\n",operators[0][0]);
	return 0;
}