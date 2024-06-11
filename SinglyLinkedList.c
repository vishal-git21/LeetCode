#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
}Node;

struct node *head = NULL;

struct node *createNode(){
    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    return NewNode;
}

void initializeNode(struct node *temp){
    int val;
    printf("Enter the value of the node\n");
    scanf("%d",&val);
    temp->info = val;
    temp->next = NULL;
}

void insert_at_the_beginning(){
    struct node *temp = createNode();
    initializeNode(temp);
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void insert_at_the_end(){
    struct node *temp = createNode();
    initializeNode(temp);
    if(head == NULL){
        head = temp;
    }
    else{
        struct node *iter = createNode();
        iter = head;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = temp;
    }
}

void delete_at_the_beginning(){
    if(head == NULL){
        printf("No nodes to delete\n");
    }
    else{
        printf("%d\n",head->info);
        head = head->next;
    }
}

void delete_at_the_end(){
    if(head == NULL){
        printf("No nodes to delete\n");
    }
    else if(head->next == NULL){
        printf("%d\n",head->info);
        head = NULL;
    }
    else{
        struct node *iter = createNode();
        iter = head;
        struct node *prev = createNode();
        while(iter->next != NULL){
            prev = iter;
            iter = iter->next;
        }
        prev->next = NULL;
        printf("%d\n",iter->info);
        
    }
}

void display(){
    if(head == NULL){
        printf("No nodes to display\n");
    }
    else{
        struct node *iter = createNode();
        iter = head;
        while(iter != NULL){
            printf("%d ",iter->info);
            iter = iter->next;
        }
        printf("\n");
    }
}

int main(){
    int choice;
    int end = 0;
    while(end != 1){
        printf("Enter Action\n1:Insert at the beginning\n2:Insert at the end\n3:Delete at the beginning\n4:Delete at the end\n5:Display\n6:Break\n\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_at_the_beginning();
                break;
            case 2:
                insert_at_the_end();
                break;
            case 3:
                delete_at_the_beginning();
                break;
            case 4:
                delete_at_the_end();
                break;
            case 5:
                display();
                break;
            case 6:
                end = 1;
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    printf("Exiting the Program\n");
    return 0;
}