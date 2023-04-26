#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = 0;
void E(),Edash(),T(),Tdash(),F(),advance(),error();

int main() {
    
    printf("Enter the string:");
    char str[50];
    scanf("%s",str);
    int n = strlen(str);
    E(str);
    if(i == (n)){
        printf("Accepted\n");
    }
    else{
        printf("Not Accepted\n");
    }
    return 0;
}

void advance(){
    i = i+1;
}

void error(){
    printf("Error");
    exit(0);
}

void F(char str[]){
    if(str[i] == '('){
        advance();
        E(str);
        if(str[i] == ')'){
            advance();
        }
        else{
            error();
            exit(0);
        }
        
    }
    
    if(str[i] == 'i'){
        advance();
    }
    else{
        error();
        exit(0);
    }
}

void Tdash(char str[]){
    if(str[i] == '*'){
        advance();
        F(str);
        Tdash(str);
    }
}

void Edash(char str[]){
    if(str[i] == '+'){
        advance();
        T(str);
        Edash(str);
    }
}

void T(char str[]){
    F(str);
    Tdash(str);
}

void E(char str[]){
    T(str);
    Edash(str);
}