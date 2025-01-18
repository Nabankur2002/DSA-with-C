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
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void evalPush(int x) {
    if (evalTop == MAX - 1) {
        printf("Evaluation stack overflow\n");
        return;
    }
    evalStack[++evalTop] = x;
}

int evalPop() {
    if (evalTop == -1) {
        printf("Evaluation stack underflow\n");
        return -1;
    }
    return evalStack[evalTop--];
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
        if (isalpha(infix[i])) {
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

int evaluatePostfix(char* postfix, int values[]) {
    int i = 0, a, b;
    while (postfix[i] != '\0') {
        if (isalpha(postfix[i])) {
            evalPush(values[postfix[i] - 'A']); 
        } else {
            b = evalPop();
            a = evalPop();
            switch (postfix[i]) {
                case '+':
                    evalPush(a + b);
                    break;
                case '-':
                    evalPush(a - b);
                    break;
                case '*':
                    evalPush(a * b);
                    break;
                case '/':
                    evalPush(a / b);
                    break;
            }
        }
        i++;
    }
    return evalPop();
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];
    int values[26]; 

    printf("Enter an infix expression (with variables): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    for (int i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i])) {
            if (values[infix[i] - 'A'] == 0) { 
                printf("Enter the value of %c: ", infix[i]);
                scanf("%d", &values[infix[i] - 'A']);
            }
        }
    }
    int result = evaluatePostfix(postfix, values);
    printf("Result of Evaluation: %d\n", result);

    return 0;
}