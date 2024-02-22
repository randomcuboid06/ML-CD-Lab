%{
#include<stdio.h>
%}
digit [0-9]+
word [A-Za-z]+
spsym [(){};,%\{\]]
arith [+-/*]
whitspc [ \t\n]
underscr [_]
%%
{whitspc}+ ;
\"[^\n\"]*\" {printf("\n %s is a literal", yytext);}
int |
include |
if |
else |
while |
do |
switch |
case |
default |
break |
continue |
scanf {printf("\n%s is a keyword", yytext);}
{spsym} {printf("\n %s is a special symbol", yytext);}
{arith} {printf("\n %s is a binary operator", yytext);}

= {printf("\n %s is a assignment operator", yytext);}
"++"|"--" {printf("\n %s is a unary operator", yytext);}
"&"|"|"|"^" {printf("\n %s is a bitwise operator", yytext);}
"<"|">"|"<="|">="|"=="|"!=" {printf("\n %s is a relational operator", yytext);}
{digit}+ {printf("\n %s is a integer constant", yytext);}
({digit}+)|({digit}*\.{digit}+) {printf("\n %s is a float constant", yytext);}
({word}({word}|{digit}|{underscr})*) {printf("\n %s is an identifier", yytext);}
%%
int main(int argc, char* argv[]){
	FILE *fp;
	fp = fopen("hello.c", "r");
	if(!fp){
		printf("Cannot open: %s", argv[1]);
		exit(1);
	}
	yyin = fp;
	yylex();
	return(0);
}
int yywrap(){
	return 1;
}
