#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int stack[CAPACITY], top=-1;

void push(int);
void pop();
void peek();
void traverse();
void main(){
    int ch, item;
    while(1){
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Traverse \n");
        printf("5. Exit \n");

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
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid input \n"); 
        }
    }
}

int isFull(){
    if (top == CAPACITY-1){
        return 1;
    } else{
        return 0;
    }
}

int isEmpty(){
    if (top == -1){
        return 1;
    } else{
        return 0;
    }
}

void push(int ele){
    if (isFull()){
        printf("Stack is full \n");
    } else{
        top++;
        stack[top] = ele;
        printf("Element pushed successfully \n");
    }    
}

void pop(){
    if (isEmpty()){
        printf("Stack is empty \n");
    } else{
        printf("Poped element is : %d \n", stack[top]);
        top--;
    }
}

void peek(){
    if (isEmpty()){
        printf("Stack is empty \n");
    } else{
        printf("Peek element is : %d \n", stack[top]);
    }
}

void traverse(){
    int i;
    if (isEmpty()){
        printf("Stack is empty \n");
    } else{
        printf("Elements in stack are : \n");
        for (i=0; i <= top; i++){
            printf("%d \n", stack[i]);
        }
    }
}
