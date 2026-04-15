//Circular linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("Initialize faild!\n");
        return NULL;
    }
    head->data = 0;
    head->next =NULL;
    return head;
}

node* insert_nodes(node* L,int new_data){
    if(L == NULL){
        printf("nonexistent linked list!\n");
        return NULL;
    }
    node* tail = L;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("insert faild!\n");
        return 0;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    tail->next = new_node;
    return new_node;
}

int Print_list(node* L){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return 0;
    }
    if(L->next == NULL){
        printf("empty linked list!\n");
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

int isCycle(node* L){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return 0;
    }
    node* fast = L;
    node* slow = L;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) return 1;
    }
    return 0;
}

int main(){

    node* list = init_list();

    insert_nodes(list,1);
    insert_nodes(list,2);
    insert_nodes(list,3);
    insert_nodes(list,4);
    node* cycle_node = insert_nodes(list,5);
    insert_nodes(list,6);
    insert_nodes(list,7);
    insert_nodes(list,8);
    node* tail_node = insert_nodes(list,9);
    tail_node->next = cycle_node;

    int judgement = isCycle(list);
    if(judgement == 1) printf("Is circular linked list!\n");
    else printf("Is NOT circular linked list!\n");

    // Print_list(list);WARNING!!!NOT SAFE!!!

    return 0;

}