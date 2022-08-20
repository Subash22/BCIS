#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int cqueue[CAPACITY], rear=-1, front=-1;
void push(int);
void pop();
void traverse();
void main(){
    int ch, item;
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Traverse \n");
    printf("4. Exit \n");
    printf("Enter your choice : \n");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            printf("Enter a number : \n");
            scanf("%d", &item);
            push(item);
        case 2:
            pop();
        case 3:
            traverse();
        case 4:
            exit(0);
        default:
            printf("Invalid input");
    }
}

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    } else{
        return 0;
    }
}

int isFull(){
    if((front == 0 && rear == CAPACITY-1) || front == rear+1){
        return 1;
    } else{
        return 0;
    }
}

void push(int ele){
    if(isFull()){
        printf("Queue is full");
    } else if(isEmpty()){
        front = rear = 0;
        cqueue[rear] = ele;
    } else if(rear == CAPACITY-1){
        rear = 0;
        cqueue[rear] = ele;
    } else{
        rear++;
        cqueue[rear] = ele;
    }
}

void pop(){
    if(isEmpty()){
        printf("Queue is empty");
    } else if(front == rear){
        front = rear = -1;
    } else if(front == CAPACITY-1){
        front = 0;
    } else{
        front++;
    }
    printf("Element poped successfully");
}

void traverse(){
    if(isEmpty()){
        printf("Queue is empty");
    } else{
        int i;
        printf("Queue elements are : \n");
        if (front > rear){
            for(i=front; i<CAPACITY; i++){
                printf("%d\n", cqueue[i]);
            }
            for(i=0; i<=rear; i++){
                printf("%d\n", cqueue[i]);
            }
        }
    }
}
