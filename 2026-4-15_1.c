#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义结点
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

//initialize list--creat a head node
node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("Initialization faild!\n");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;
    return head;
}

//insert nodes Function
int insert_node(node* L,int new_data){
    if(L == NULL){
        printf("Linked list doesn`t exist!\n");
        return 0;
    }

    //Get the tail of linked list
    node* tail_node = L;
    while(tail_node->next != NULL){
        tail_node = tail_node->next;
    }

    //creat a new node for insert
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Creat new node faild!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = tail_node->next;//tail_node->next == NULL
    tail_node->next = new_node;
    return 1;
}

//Function of show the linked list
int Print_list(node* L){
    if(L == NULL){
        printf("The linked list don`t exist!\n");
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
    //newline
    printf("\n");
    return 1;
}

node* Reverse_list(node* L){
    if(L == NULL){
        printf("The linked list don`t exist!\n");
        return NULL;
    }

    node* first = NULL;
    node* second = L->next;
    node* third;

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
    //初始化链表-创建头结点
    node* list = init_list();
    if(list == NULL){
        printf("Creat linked list faild!\n");
        return 0;
    }

    //insert nodes into linked list
    insert_node(list,10);
    insert_node(list,20);
    insert_node(list,30);
    insert_node(list,40);
    insert_node(list,50);

    //show the linked list
    Print_list(list);

    //reverse the linked list
    node *reversed_list = Reverse_list(list);

    //After reversed linked list
    Print_list(reversed_list);


    return 0;
}