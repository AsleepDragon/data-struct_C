#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//double linked list
typedef struct NODE{
    int data;
    struct NODE *prev,*next;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL) return NULL;
    head->prev =NULL;
    head->data = 0;
    head->next = NULL;
    return head;
}

//Head insertion 
int insert_head(node* L,int new_data){
    if(L == NULL) return 0;
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) return 0;

    new_node->data = new_data;
    new_node->prev = L;
    new_node->next = L->next;

    //若当前链表不为空
    if(L->next != NULL){
        L->next->prev = new_node;
    }
    L->next = new_node;

    return 1;
}

node* get_tail(node* L){
    if(L == NULL) return NULL;

    node* tail = L;
    while(tail->next != NULL){
        tail = tail->next;
    }

    return tail;
}

int insert_tail(node* L , int new_data){
    if(L == NULL) return 0;
    node* tail = get_tail(L);

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) return 0;
    
    new_node->data = new_data;
    new_node->prev = tail;
    new_node->next = NULL;
    tail->next = new_node;

    return 1;
}

int linked_list_length(node* L){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return -1;
    }

    node* count_node = L;
    int count = 0;
    while(count_node->next != NULL){
        count_node = count_node->next;
        count++;
    }
    return count;
}

//在double linked list中，指定位置插入结点既可找前驱结点也可找后继结点
int insert_node(node* L,int pos,int new_data){
    if(L == NULL) return 0;

    int len = linked_list_length(L);

    if(pos<1 || pos>len){
        if(pos == len+1){
            //尾插
            int ret = insert_tail(L,new_data);
            return (ret=1?1:0);
        }
        printf("Invaild position!\n");
        return 0;
    }

    node* front_node = L;
    while(--pos){
        front_node = front_node->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) return 0;

    new_node->data = new_data;
    new_node->prev = front_node;
    new_node->next = front_node->next;
    front_node->next->prev = new_node;
    front_node->next = new_node;
    return 1;
    
}

int del_node(node* L,int pos){
    if(L == NULL) return 0;
    if(pos<1 || pos>linked_list_length(L)){
        printf("Invalid position!\n");
        return 0;
    }

    node* front_node = L;
    while(--pos){
        front_node = front_node->next;
    }

    node* tmp = front_node->next;
    front_node->next = front_node->next->next;
    front_node->next->prev = front_node;
    free(tmp);
    return 1;
}

int Print_list(node* L){
    if(L == NULL) return 0;
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

int main()
{
    node* list = init_list();

    insert_head(list,10);
    insert_head(list,20);
    insert_head(list,30);

    insert_tail(list,40);
    insert_tail(list,50);
    insert_tail(list,60);

    //指定位置插入
    insert_node(list,4,666);

    del_node(list,5);

    Print_list(list);

    return 0;
}