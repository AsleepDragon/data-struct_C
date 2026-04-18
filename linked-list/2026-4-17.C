#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("Initialize faild!\n");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;
    return head;
}

node* insert_nodes(node* L,int new_data){
    if(L == NULL){
        printf("Nonexistent linked list!\n");
        return NULL;
    }
    node* tail_node = L;
    while(tail_node->next != NULL){
        tail_node = tail_node->next;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Allocate memory for new_node falid!\n");
        return NULL;
    }

    new_node->data = new_data;
    new_node->next = NULL;
    tail_node->next = new_node;
    return new_node;

}

int Print_list(node* L){
    if (L == NULL)
    {
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
    printf("\n");
    return 1;
}

int IsCycle(node* L){
    if(L == NULL){
        printf("Empty linked list!\n");
        return -1;
    }

    node* fast = L;
    node* slow = L;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            // pirntf("The linked list is circular!\n");
            return 1;
        }
    }
    return 0;
}

node* Cycle_start(node* L){
    if (L == NULL)
    {
        printf("Empty linked list!\n");
        return NULL;
    }

    node* fast = L;
    node* slow = L;
    while(fast != NULL && fast->next!= NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }

    //注意：此时fast == slow
    int count = 1;
    while(fast->next != slow){
        fast = fast->next;
        count++;
    }
    //The count is cycle nodes numbers

    node* p1 = L;
    node* p2 = L;
    for(int i = 0;i<count;i++){
        p1 = p1->next;
    }
    while(p1 != p2){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main()
{
    node* list = init_list();

    insert_nodes(list,10);
    insert_nodes(list,20);
    insert_nodes(list,30);
    node* node_4 = insert_nodes(list,40);
    insert_nodes(list,50);
    insert_nodes(list,60);
    insert_nodes(list,70);
    insert_nodes(list,80);
    node* node_9 = insert_nodes(list,90);
    node_9->next = node_4;

    int ret = IsCycle(list);
    if(ret == 1) printf("YES!\n");
    else if(ret == 0) printf("NO!\n");
    else printf("ERROR!\n");

    node* start_node = Cycle_start(list);
    printf("%d\n",start_node->data);

    // Print_list(list);

    return 0;
}