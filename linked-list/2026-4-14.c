//链表，查找倒数第K个结点
//双指针 （快慢指针）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义结点
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

//初始化链表（创建头结点）
node* init_list(){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("Faild to initialize!\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

//头部插入结点
int insert_head(node* L,int new_data){
    //创建新结点
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Faild to insert!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = L->next;
    L->next = new_node;
    return 1;
}

//尾部插入结点
int insert_tail(node* L,int new_data){
    //获取尾部位置
    node *get_tail = L->next;
    while(get_tail->next != NULL){
        get_tail = get_tail->next;
    }
    //此时get_tail为最后一个结点

    //创建新结点
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Faild to insert!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = NULL;
    get_tail->next = new_node;
    return 1;

}

//指定位置插入结点
int insert_pos(node* L,int pos,int new_data){
    //判断插入位置是否合法
    if(pos < 1){
        printf("Faild to insert!The position is invalid!\n");
        return 0;
    }

    //找到插入位置的前驱结点
    node* pos_node = L->next;
    int i = 1;
    while(i++ < pos-1){
        pos_node = pos_node->next;
    }
    //此时pos_node为插入位置的前驱结点

    //创建新结点
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Faild to insert!\n");
        return 0;
    }

    new_node->data = new_data;
    new_node->next = pos_node->next;
    pos_node->next = new_node;
    return 1;
}

//删除指定结点
int del_node(node* L,int pos){
    //判断删除结点位置是否有效-位置正负性判断
    if(pos < 1){
        printf("Faild to delete!The position is invalid!\n");
        return 0;
    }

    //找到删除结点的前驱结点
    node* pos_node = L->next;
    int i = 1;
    while(i++ < pos-1){
        pos_node = pos_node->next;
        
        //判断删除结点位置是否有效-位置溢出性判断
        if(pos_node->next == NULL){
            printf("Faild to delete!The position is invalid!\n");
            return 0;
        }
    }
    //此时pos_node为删除结点的前驱结点

    node* tmp = pos_node->next;
    pos_node->next = pos_node->next->next;
    free(tmp);
    return 1;
}

//打印链表
int Print_list(node* L){
    if(L == NULL){
        printf("Empty list!\n");
        return 0;
    }
    
    node *p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

//计算链表长度
int len_node(node* L){
    if(L == NULL){
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

//查找倒数第k个结点，并打印其数据域
//使用双指针（快慢指针）
int find_countdown(node* L,int k){
    //判断位置k的合法性
    if(k > len_node(L)){
        printf("Faild to find!The value of 'k' is invalid!\n");
        return 0;
    }

    //创建双指针fast,slow，指向第一个结点（非head）
    //先让fast走k步，随后fast与slow一起
    //当fast指向NULL时，slow刚好指向第k个结点
    node *fast = L->next;
    node *slow = L->next;
    int i = 0;
    while(i++ < k){
        fast = fast->next;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    printf("%d\n",slow->data);
    return 1;
}

int main()
{
    //初始化链表（创建头结点）
    node* list = init_list();
    if(list == NULL){
        printf("faild to initialize!\n");
        return 0;
    }

    //头部插入结点
    insert_head(list,10);
    insert_head(list,11);
    insert_head(list,12);

    //尾部插入结点
    insert_tail(list,20);
    insert_tail(list,21);
    insert_tail(list,22);

    //指定位置插入结点
    insert_pos(list,3,30);


    //指定位置删除结点
    // del_node(list,4);

    //打印链表
    Print_list(list);

    //找到倒数第K个结点
    //双指针（快慢指针）
    find_countdown(list,3);

    return 0;
}