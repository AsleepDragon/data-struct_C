#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL) return NULL;
    head->data = 0;
    head->next = NULL;
    return head;
}

int insert_node(node* L,int new_data){
    if(L == NULL) return 0;
    node* p = L;
    while(p->next != NULL) p = p->next;
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
    return 1;
}

node* find_middle_node(node* L){
    if(L == NULL) return NULL;
    node* fast = L->next;
    node* slow = L->next;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow->next = NULL;
    return slow;
}

node* reverse_list(node* L){
    if(L == NULL) return NULL;
    node* first = NULL;
    node* second = L;
    node* third;

    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    node* new_head = (node*)malloc(sizeof(node));
    if(new_head == NULL) return NULL;
    new_head->next = first;
    return new_head;
}

node* main_func(node* L){
    if(L == NULL)  return NULL;
    node *mid_node = find_middle_node(L);
    node* reversed_node = reverse_list(mid_node->next);
    mid_node->next = NULL;//截断

    node* front = L->next;
    node* front_save;
    node* back = reversed_node->next;
    node* back_save;

    while(back != NULL){
        front_save = front->next;
        back_save = back->next;

        front->next = back;
        back->next = front_save;

        front = front_save;
        back = back_save;
    }

    return L;
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

    // print_list(list);

    node* new_list = main_func(list);

    print_list(new_list);

    return 0;
}