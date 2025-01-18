#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    else{
        top = top+1;
        stack[top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;
    while (infix[i] != '\0') {
        if (isalpha(infix[i])){
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

   
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    int values[26]; 

    printf("Enter an infix expression to convert into postfix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The Postfix Expression is: %s\n", postfix);

    return 0;
}