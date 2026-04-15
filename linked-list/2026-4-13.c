#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//定义结点
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

//初始化链表
node* init_list(){
    //动态开辟一个结点大小空间
    node *head = (node*)malloc(sizeof(node));
    if(head == NULL){
        printf("初始化失败！\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;//返回头节点
}

//插入结点-头插法
int insert_head(node* L,int new_data){
    //创建一个新结点
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("插入失败！\n");
        return 0;
    }
    new_node->data = new_data;
    new_node->next = L->next;
    L->next = new_node;

    return 1;
}

//获取尾结点地址
node* get_tail(node *L){
    //我们不希望改变源链表，所以创建临时变量get
    node *get = L;
    while(get->next != NULL){
        get = get->next;
    }
    return get;
}

//插入结点-尾插法
int insert_tail(node* L,int new_data){
    //获取尾结点地址
    node *tail = get_tail(L);
    //创建一个新结点
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("插入失败！\n");
        return 0;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    tail->next = new_node;

    return 1;
}

//插入结点-指定位置
int insert_pos(node *L,int pos,int new_data){
    if(pos < 1)
    {
        printf("位置非法！\n");
        return 0;
    }
    //找到指定位置（指定位置的前驱结点）
    node *pos_node = L;
    int i = 1;
    while(i++ <= pos-1){
        pos_node = pos_node->next;
        if(pos_node == NULL){
            printf("位置不存在！\n");
            return 0;
        }
    }
    //此时pos_node为将要被插入的前驱位置
    //因为前驱结点包含目标结点的后继结点

    //创建新结点
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("插入失败！\n");
        return 0;
    }
    new_node->data = new_data;
    new_node->next = pos_node->next;
    pos_node->next = new_node;
    return 1;
}

//删除结点
int del_Node(node *L,int pos){
    //找到指定位置（依旧为指定节点的前驱结点）
    node *pos_node = L;
    int i = 1;
    while(i++ <= pos-1){
        pos_node = pos_node->next;
        if(pos_node->next == NULL){
            printf("该结点不存在！\n");
            return 0;
        }
    }
    //此时pos_node为指定结点的前驱结点

    node *tmp = pos_node->next;
    pos_node->next = pos_node->next->next;
    free(tmp);
    return 1;
}

//打印结点
int Print(node* L){
    if(L->next == NULL){
        printf("链表为空！\n");
        return 0;
    }
    //创建中间变量指针,指向当前结点
    node *cur = L->next;

    while(cur != NULL){
        printf("%d ",cur->data);

        //调整指针
        cur = cur->next;
    }
    printf("\n");
    return 1;
}

//计算链表长度
int List_len(node *L){
    node *p = L->next;//从第一个结点位置开始，不包括首结点
    int count = 0;
    while(p != NULL){
        count++;
        //调整指针
        p = p->next;
    }
    return count;
}

//销毁链表（释放链表所占内存空间）（不包括首结点）
void destroy_list(node *L){
    //先指向第一个结点
    node *p = L->next;
    node *q;

    //p指针去遍历链表，q指针去释放空间
    while(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
}

int main()
{
    //初始化链表
    node *list = init_list();
    if(list == NULL)
    {
        printf("初始化链表失败！\n");
        return 1;
    }

    //插入结点-头插法
    insert_head(list,10);
    insert_head(list,20);

    //插入结点-尾插法
    insert_tail(list,30);
    insert_tail(list,40);

    //插入结点-指定位置
    insert_pos(list,3,666);

    //删除结点
    del_Node(list,4);

    //打印链表
    Print(list);

    //计算并打印列表长度（不包括首结点）
    int len = List_len(list);
    printf("%d\n",len);

    //销毁链表（释放链表所占内存）（不包括首结点）
    destroy_list(list);

    len = List_len(list);
    printf("%d\n", len);

    return 0;
}