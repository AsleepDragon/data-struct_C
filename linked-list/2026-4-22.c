#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct NODE{
    int data;
    struct NODE *next,*prev;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("%s\n",strerror(errno));
        return NULL;
    }

    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

//Insert front
int insert_front(node* L,int new_data){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return 0;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Malloc failed\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->prev = L;
    new_node->next = L->next;
    if(L->next != NULL){
        L->next->prev = new_node;
    }
    L->next = new_node;
    return 1;
}

//Insert tail
int insert_tail(node* L,int new_data){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return 0;
    }

    //find the last node
    node* tail_node = L;
    while(tail_node->next != NULL){
        tail_node = tail_node->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Malloc failed!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->prev = tail_node;
    new_node->next = NULL;
    tail_node->next = new_node;
    return 1;
}

int Print_list(node* L){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return 0;
    }
    if(L->next == NULL){
        printf("Empty linked list!\n");
        return 0;
    }

    node* p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    return 1;
}

int list_len(node *L)
{
    if (L == NULL)
    {
        printf("Nonexistent linked list!\n");
        return -1;
    }

    int count = 0;
    node *count_nodes = L;
    while (count_nodes->next != NULL)
    {
        count++;
        count_nodes = count_nodes->next;
    }

    return count;
}

int insert_posion(node* L,int pos,int new_data){
    if(L == NULL){
        printf("Nonexsitent linked list!\n");
        return 0;
    }
    //Determine whether the 'pos' is valid
    int len = list_len(L);
    if(pos<1 || pos>len){
        if(pos == len+1){
            int ret = insert_tail(L,new_data);
            return ret=1?1:0;
        }
        printf("Invalid position!\n");
        return 0;
    }

    node* front_node = L;
    while(--pos){
        front_node = front_node->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Malloc failed!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = front_node->next;
    new_node->prev = front_node;
    if(front_node->next != NULL){
        front_node->next->prev = new_node;
    }
    front_node->next = new_node;

    return 1;
}

int main(){
    node* list = init_list();

    //Insert nodes
    insert_front(list,10);
    insert_front(list,20);
    insert_front(list,30);

    insert_tail(list,40);
    insert_tail(list,50);
    insert_tail(list,60);

    insert_posion(list,4,666);

    Print_list(list);
    
    return 0;
}