#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool ifKeyword(char word[]){
    if(
        !strcmp("auto",word) || !strcmp("double",word) || !strcmp("int",word) || !strcmp("struct",word) ||
        !strcmp("break",word) || !strcmp("else",word) || !strcmp("long",word) || !strcmp("switch",word) ||
        !strcmp("case",word) || !strcmp("enum",word) || !strcmp("register",word) || !strcmp("typedef",word) ||
        !strcmp("char",word) || !strcmp("extern",word) || !strcmp("return",word) || !strcmp("union",word) ||
        !strcmp("const",word) || !strcmp("float",word) || !strcmp("short",word) || !strcmp("unsigned",word) ||
        !strcmp("continue",word) || !strcmp("for",word) || !strcmp("signed",word) || !strcmp("void",word) ||
        !strcmp("default",word) || !strcmp("goto",word) || !strcmp("sizeof",word) || !strcmp("volatile",word) ||
        !strcmp("do",word) || !strcmp("if",word) || !strcmp("static",word) || !strcmp("while",word)
    ){
        return true;
    }
    return false;
}

bool ifOperator(char word[]){
    if(
        !strcmp("+",word) || !strcmp(">",word) || !strcmp("~",word) || !strcmp("%=",word) ||
        !strcmp("-",word) || !strcmp("<",word) || !strcmp("&",word) || !strcmp("<<=",word) ||
        !strcmp("*",word) || !strcmp(">=",word) || !strcmp("^",word) || !strcmp(">>=",word) ||
        !strcmp("/",word) || !strcmp("<=",word) || !strcmp("|",word) || !strcmp("&=",word) ||
        !strcmp("%",word) || !strcmp("&&",word) || !strcmp("=",word) || !strcmp("^=",word) ||
        !strcmp("++",word) || !strcmp("||",word) || !strcmp("+=",word) || !strcmp("|=",word) ||
        !strcmp("--",word) || !strcmp("!",word) || !strcmp("-=",word) || 
        !strcmp("==",word) || !strcmp("<<",word) || !strcmp("*=",word) || 
        !strcmp("!=",word) || !strcmp(">>",word) || !strcmp("/=",word)
    ){
        return true;
    }
    return false;
}

bool ifConstant(char word[]){
    
    for(int i=0;i<strlen(word);i++){
        if(word[i] == '.') continue;
        if(!isdigit(word[i])){
            return false;
        }
    }
    return true;
}

bool ifSpecialSymbol(char word[]){
    if(
        !strcmp("[",word) || !strcmp("]",word) || !strcmp("{",word) || !strcmp("}",word) ||
        !strcmp(",",word) || !strcmp(";",word) || !strcmp(":",word) || !strcmp("(",word) ||
        !strcmp(")",word)
    ){
        return true;
    }
    return false;
}

bool isLiteral(char word[]){
    int i = 0;
    int j = strlen(word) - 1;

    if(((int)word[i] == 34 && (int)word[i] == 34) || ((int)word[i] == 39 && (int)word[j] == 39)){
        return true;
    }
    return false;
}


int main()
{
	FILE *fp;
	int count = 1;
	char filename[80] = "file.txt";
	char c; 

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 0;
	}


	printf("Line %d \n",count);
    c = getc(fp);
	while(c != EOF){
        char word[50] = {0};
        int i = 0;
        while(c != ' '){   
            word[i] = c;
            i++;
            c = getc(fp);

			if(c == '\n'){
			count++;
			printf("\nLine %d",count);
		    }
        }

        if(ifKeyword(word) == true){
            printf("%s is a keyword\n",word);
        }
        else if(ifOperator(word) == true){
            printf("%s is a operator\n",word);
        }
        else if(ifConstant(word) == true){
            printf("%s is constant\n",word);
        }
        else if(ifSpecialSymbol(word) == true){
            printf("%s is special symbol\n",word);
        }
        else if(isLiteral(word) == true){
            printf("%s is a literal\n",word);
        }
        else{
            printf("%s is a identifier\n",word);
        }

        c = getc(fp);
    }

	fclose(fp);

	return 0;
}
