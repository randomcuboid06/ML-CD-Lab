#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void isConstant(){
    printf("----------Checking if a string is a constant----------");
    char s[50];
    printf("\nEnter a string: ");
    gets(s);
    if(atoi(s)){
        printf("\nGiven string is a constant\n\n");
    }else{
        printf("\nGiven string is not a constant\n\n");
    }
}

void isComment(){
    printf("----------Checking if given string is a comment----------");
    char s[50];
    int flag = 0;
    printf("\nEnter a string: ");
    gets(s);
    if(s[0]=='/'){
        if(s[1]=='/'){
            flag=1;
        }else if(s[1]=='*'){
            int n = strlen(s) - 1;
            if(s[n]=='/' && s[n-1]=='*'){
                flag=1;
            }
        }
    }
    (flag==1)?printf("\nGiven string is a comment\n\n"):printf("\nGiven string is not a comment\n\n");
}

void isIdentifier(){
    printf("----------Checking is a string is an identifier----------");
    char s[50];
    printf("\nEnter input: ");
    gets(s);
    int flag = 0, i;
    if(isalpha(s[0]) || s[0] == '_'){
        for(i=0;  i<strlen(s); i++){
            if(isdigit(s[i]) || isalpha(s[i]) || s[i] == '_'){
                flag=1;
            }else{
                break;
            }
        }
    }
    (flag==1)?printf("\nValid\n\n"):printf("\nInvalid\n\n");
}

void isKeyword(){
    printf("----------Checking if a word is a keyword----------");
    int i, flag=0, m;
    char s[5][10] = {"if", "else", "goto", "continue", "return", "break"};
    char st[10];
    printf("\nEnter string: ");
    gets(st);
    for(i=0; i<5; i++){
        m = strcmp(st, s[i]);
        if(m==0){
            flag=1;
        }
    }
    (flag==0)?printf("It is not a valid keyword\n\n"):printf("\nIt is a valid keyword\n\n");
}

void isOperator(){
    printf("----------Checking is a char/string is an operator----------");
    char s[5];
    printf("\nEnter any operator: ");
    gets(s);
    switch(s[0]){
    case '>':
        s[1]=='='?printf("\nGreater than or equal to\n\n"):printf("\nGreater than\n\n"); break;
    case '<':
        s[1]=='='?printf("\Less than or equal to\n\n"):printf("\Less than\n\n"); break;
    case '=':
        s[1]=='='?printf("\nEqual to\n\n"):printf("\nAssignment\n\n"); break;
    case '&':
        s[1]=='&'?printf("\nLogical AND\n\n"):printf("\nBitwise AND\n\n"); break;
    case '|':
        s[1]=='|'?printf("\nLogical OR\n\n"):printf("\nBitwise OR\n\n"); break;
    case '+': printf("Addition\n\n"); break;
    case '-': printf("Subtraction\n\n"); break;
    case '*': printf("Multiplication\n\n"); break;
    case '/': printf("Division\n\n"); break;
    case '%': printf("Modulus\n\n"); break;
    default: printf("\nNot an operator\n\n");
    }
}

void main(){
    isConstant();
    isComment();
    isIdentifier();
    isKeyword();
    isOperator();
}
