#include <stdio.h>
#include <stdbool.h>
#include<ctype.h>

int SIZE = 100;
char opstck[100];
char postfix[100];
int top = -1;


void push(ele){
    if(top == SIZE - 1){
        printf("Overflow\n");
    }
    else{
        opstck[++top] = ele;
    }
}

bool isstckempty(){
    if(top == -1)return true;
    else{
        return false;
    }
}



void pop(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        top--;
    }
}

char topele(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        return opstck[top];
    }
}

int prior(char c){
    if(c == '(' || c == '#')return 1;
    if(c == '+' || c == '-')return 2;
    if(c == '*' || c == '/')return 3;
}

int main(){
    char infix[100];
    printf("Enter the infix string\n");
    scanf("%s",infix);
    int i = 0,j = 0;
    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')push(infix[i]);
        else if(infix[i] == ')'){
            while(topele() != '('){
                postfix[j++] = topele();
                pop();
            }
            pop();
        }
        else{
            while(!isstckempty() && prior(topele()) >= prior(infix[i])){
                postfix[j++] = topele();
                pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(isstckempty() != true){
        postfix[j++] = topele();
        pop();
    }
    printf("%s",postfix);
    
}


