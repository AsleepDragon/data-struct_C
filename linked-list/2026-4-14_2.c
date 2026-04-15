#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("Faild to initialize the list!\n");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;
    return head;
}

int insert_node(node* L,int new_data){
    if(L == NULL){
        printf("The list is nonexistent!\n");
        return 0;
    }

    node* tail_node = L;
    while(tail_node->next != NULL){
        tail_node = tail_node->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Faild to insert!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = tail_node->next;
    tail_node->next = new_node;
    return 1;
}

int Print_node(node* L){
    if(L == NULL){
        printf("The list is nonexistent!\n");
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

node* reverse_list(node* L){
    if(L == NULL){
        printf("Nonexistent list!\n");
        return NULL;
    }

    node *first = NULL;
    node *second = L->next;
    node *third;

    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    node* new_head = init_list();
    new_head->next = first;
    return new_head;
}

int main()
{
    node* list = init_list();

    insert_node(list,10);
    insert_node(list,20);
    insert_node(list,30);
    insert_node(list,40);
    insert_node(list,50);

    Print_node(list);

    node* reversed_list = reverse_list(list);

    Print_node(reversed_list);

    return 0;
}