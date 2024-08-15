#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinStackNode {
    int value;
    int min;
    struct MinStackNode *next;
} MinStackNode;

typedef struct {
    MinStackNode *head;
} MinStack;

MinStackNode* createNode(int value, int min) {
    MinStackNode *node = (MinStackNode *)malloc(sizeof(MinStackNode));
    node->value = value;
    node->min = min;
    node->next = NULL;
    return node;
}

MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->head = NULL;
    return stack;
}

void minStackPush(MinStack* stack, int val) {
    int currentMin = (stack->head == NULL) ? val : (val < stack->head->min ? val : stack->head->min);
    MinStackNode *node = createNode(val, currentMin);
    node->next = stack->head;
    stack->head = node;
}

void minStackPop(MinStack* stack) {
    if (stack->head != NULL) {
        MinStackNode *temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }
}

int minStackTop(MinStack* stack) {
    if (stack->head == NULL) {
        return -1;
    }
    return stack->head->value;
}

int minStackGetMin(MinStack* stack) {
    if (stack->head == NULL) {
        return -1;
    }
    return stack->head->min;
}

void minStackFree(MinStack* stack) {
    MinStackNode *current = stack->head;
    while (current != NULL) {
        MinStackNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}
