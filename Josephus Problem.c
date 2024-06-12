#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL; // Declare 'start' globally

struct node *initializeNode(int n) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->info = n;
    temp->next = NULL;
    return temp;
}

void initializeCircle(int n) {
    struct node *prev = NULL;
    for (int i = 1; i <= n; i++) {
        struct node *temp = initializeNode(i);
        if (i == 1) {
            start = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }
    prev->next = start;
}

void Josephus(int n, int k) {
    struct node *temp = start;
    struct node *prev = NULL;
    if (temp == NULL) {
        printf("Please initialize the Circle first\n");
    } else if (temp->next == temp) {
        printf("The sole entity is Node 1\n");
    } else {
        while (temp->next != temp) {
            for (int i = 1; i < k; i++) {
                prev = temp;
                temp = temp->next;
            }
            printf("Node with %d is being popped\n", temp->info);
            prev->next = temp->next;
            struct node *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        printf("Node with %d is the sole survivor\n", temp->info);
    }
}

int main() {
    int n, k;
    printf("Enter the number of nodes in the circle\n");
    scanf("%d", &n);
    printf("Enter the value of k as in the kth node to be deleted\n");
    scanf("%d", &k);
    initializeCircle(n);
    Josephus(n, k);
    return 0;
}
