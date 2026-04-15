//单链表应用
// 用单链表保存n个整数，结点的结构为[data][link]，且|data|<= n(n为正整数)。现要求设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的节点，仅保留第一次出现的节点而删除其余绝对值相等的结点

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义结点
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
        printf("Nonexistent list!\n");
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
    new_node->next = NULL;
    tail_node->next = new_node;
    return 1;
}

int Print_list(node* L){
    if(L == NULL){
        printf("Nonexistent list!\n");
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

int len_list(node* L){
    if (L == NULL)
    {
        printf("Nonexistent list!\n");
        return -1;
    }

    node* p = L->next;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

int Func_main(node* L){
    if(L == NULL){
        printf("Nonexistent list!\n");
        return 0;
    }

    int ret = len_list(L);
    int* arr = (int*)malloc((ret+1)*sizeof(int));
    if(arr == NULL){
        printf("Faild to malloc!\n");
        return 0;
    }

    memset(arr, 0, (ret+1)*sizeof(int));

    node* p = L;
    while(p->next != NULL){
        if (*(arr + abs(p->next->data)) == 0){
            *(arr + abs(p->next->data)) = 1;

            //Don`t forget move the pointer
            p = p->next;
        }
        else{

            node* tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
    }
    free(arr);
    return 1;
}

int main()
{
    //initialize list
    node* list = init_list();

    //insert nodes into list
    insert_node(list,3);
    insert_node(list,5);
    insert_node(list,7);
    insert_node(list,-2);
    insert_node(list,-5);
    insert_node(list,-7);
    insert_node(list,1);

    Func_main(list);


    Print_list(list);

    // printf("%d\n", len_list(list));
    return 0;
}