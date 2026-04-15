#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* init_list(){
    node* head_node = (node*)malloc(sizeof(node));
    if(head_node == NULL) return NULL;

    head_node->data = 0;
    head_node->next = NULL;
    return head_node;
}

int insert_node(node* L,int new_data){
    if(L == NULL) return 0;

    node* p = L;
    while(p->next != NULL){
        p = p->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) return 0;

    new_node->data = new_data;
    new_node->next = NULL;
    p->next = new_node;
    return 1;
}

int print_list(node* L){
    if(L == NULL) return 0;
    if(L->next == NULL){
        printf("empty!\n");
        return 0;
    }

    node* p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int del_middle_node(node* L){
    if(L == NULL) return 0;

    node* fast = L->next;
    node* slow = L;
    //为什么slow开始要比fast落后一个node？
    //因为删除node要找到它的前驱node

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //此时slow指向所要删除node的前驱node

    node* tmp = slow->next;
    slow->next = tmp->next;
    free(tmp);
    return 1;
}

int main()
{
    node* list = init_list();

    insert_node(list,10);
    insert_node(list,20);
    insert_node(list,30);
    insert_node(list,40);
    insert_node(list,50);
    insert_node(list,60);
    insert_node(list,70);

    print_list(list);

    del_middle_node(list);

    print_list(list);

    return 0;
}