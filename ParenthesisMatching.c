#include <stdio.h>
#define SIZE 100 // Increase the stack size to handle longer expressions
int top = -1;
char stack[SIZE];

void push(char ele) {
    if (top == SIZE - 1) {
        printf("Overflow\n");
    } else {
        stack[++top] = ele;
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        top--;
    }
}

char topele() {
    if (top == -1) {
        return '\0'; // Return a null character for an empty stack
    } else {
        return stack[top];
    }
}

int display() {
    if (top == -1) {
        return 1; // Stack is empty
    } else {
        return 0; // Stack is not empty
    }
}

int main() {
    char arr[100];
    printf("Enter your expression\n");
    scanf("%s", arr);
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[') {
            push(arr[i]);
        } else if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']') {
            char topChar = topele();
            if ((arr[i] == '}' && topChar == '{') ||
                (arr[i] == ')' && topChar == '(') ||
                (arr[i] == ']' && topChar == '[')) {
                pop();
            } else {
                printf("Invalid Expression\n");
                return 0; // Exit the program since it's already invalid
            }
        }
        i++;
    }

    if (display() == 1) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}
