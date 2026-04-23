#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct STACK{
    int data[MAX];
    int top;
}Stack;

Stack* init_stack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Initialize failed!\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

int Push_stack(Stack* S,int new_data){
    if(S == NULL){
        printf("Nonexsitent stack!\n");
        return 0;
    }

    if(S->top >= MAX-1){
        printf("The stack is full!\n");
        return 0;
    }

    S->top++;
    S->data[S->top] = new_data;
    return 1;
}

int pop_stack(Stack* S,int* keep){
    if(S == NULL){
        printf("Nonexistent stack!\n");
        return 0;
    }
    if(S->top == -1){
        printf("Empty stack!\n");
        return 0;
    }

    *keep = S->data[S->top];
    S->top--;
    return 1;
}

int get_top(Stack* S){
    if(S == NULL){
        printf("Nonexistent stack!\n");
        return NULL;
    }
    if(S->top == -1){
        printf("Empty stack!\n");
        return NULL;
    }

    return S->data[S->top];
}

int main(){

    Stack* stack = init_stack();

    //压栈
    Push_stack(stack,10);
    Push_stack(stack,20);
    Push_stack(stack,30);

    //出栈
    // int keep;
    // pop_stack(stack,&keep);
    // printf("%d\n",keep);

    //获取栈顶元素
    int top_data = get_top(stack);
    printf("%d\n",top_data);

    free(stack);
    stack = NULL;

    return 0;

}