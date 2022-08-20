#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*);
void add();
void sub();
void mul();
void divv();
void main()
{
    int ch, num1, num2, i, j, mmat[4][4], mmax;
    char str[100];

    while(1)
    {
        printf("1. String reverse \n");
        printf("2. Perform calculation \n");
        printf("3. Find largest element in matrix \n");
        printf("4. Exit \n");

        printf("Enter your choice:  \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter a string: \n");
                scanf("%s", &str);
                reverse(str);
                break;
        
            case 2:
                printf("Enter a number:\n");
                scanf("%d", &num1);
                printf("Enter another number:\n");
                scanf("%d", &num2);
                add(num1, num2);
                sub(num1, num2);
                mul(num1, num2);
                divv(num1, num2);
                break;
        
            case 3:
                printf("Enter the elements of the matrix \n");
                for (i = 0; i < 4; i++)
                    for(j = 0; j < 4; j++)
                        scanf("%d", &mmat[i][j]);
                mmax = mmat[0][0];
                for (i = 0; i < 4; i++)
                    for(j = 0; j < 4; j++)
                        if (mmat[i][j] > mmax)
                            mmax = mmat[i][j];
                printf("Largest element in the matrix is %d \n", mmax);
                break;
        
            case 4:
                exit(0);

            default:
                printf("Invalid input \n");
        }
    }
}

void reverse(char* ele){
    strrev(ele);
    printf("Reverse of the string is %s \n", ele);
}

void add(int a, int b){
    int c = a + b;
    printf("Addition of two number is %d \n", c);
}

void sub(int a, int b){
    int c = a - b;
    printf("Subtraction of two number is %d \n", c);
}

void mul(int a, int b){
    int c = a * b;
    printf("Multiplication of two number is %d \n", c);
}

void divv(int a, int b){
    int c = a / b;
    printf("Division of two number is %d \n", c);
}