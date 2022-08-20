#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int queue[CAPACITY], front=0, rear=0;
void push(int);
void pop();
void peek();
void traverse();
void main(){
    int ch, item;
    while(1){
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Traverse \n");
        printf("4. Exit \n");

        printf("Enter your choice : \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter a number: \n");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input \n"); 
        }
    }
}

int isEmpty(){
    if (front == rear){
        return 1;
    } else{
        return 0;
    }
}

int isFull(){
    if (rear == CAPACITY){
        return 1;
    } else{
        return 0;
    }
}

void push(int ele){
    if(isFull()){
        printf("Queue is full \n");
    } else{
        queue[rear] = ele;
        rear++;
    }
}

void pop(){
    int i;
    if(isEmpty()){
        printf("Queue is empty \n");
    } else{
        for (i=front; i<rear-1; i++){
            queue[i] = queue[i+1];
        }
        rear--;
        printf("Element poped successfully\n");
    }
}

void traverse(){
    int i;
    if (isEmpty()){
        printf("Queue is empty");
    } else{
        printf("Items in queue are : \n");
        for (i=front; i<rear; i++){
            printf("%d \n", queue[i]);
        }
    }
}
