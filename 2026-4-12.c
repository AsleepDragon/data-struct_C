/*#region
// #include <stdio.h>

// typedef struct{
//     float real_part;
//     float image_part;
// }plural;

// void assign(plural* pl,float real,float image)
// {
//     pl->real_part = real;
//     pl->image_part = image;

// }

// int main()
// {
//     plural data_1;
//     float data_real = 3.0;
//     float data_image = 5.0;
//     assign(&data_1,data_real,data_image);

//     printf("%.2f+%.2fi\n",data_1.real_part,data_1.image_part);


//     return 0;
// }
#endregion*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//数据元素
typedef struct{
    char isbn[20];
    char name[20];
    int price;
}book;

//顺序表
typedef struct{
    book* elem;
    int length;
    int capacity;
}SQlist;

//初始化书架
int init_list(SQlist *L)
{
    L->elem = (book*)malloc(sizeof(book)*10);
    if(L->elem == NULL) return 0;//内存申请失败
    L->length = 0;
    L->capacity = 10;
    return 1;
}

//尾部插入
int push_back(SQlist* L,book new_book)
{
    if(L->length >= L->capacity)
    {
        printf("书架满了！\n");
        return 0;
    }
    L->elem[L->length] = new_book;
    L->length++;
    return 1;
}

//指定位置插入
int insert_at(SQlist* L,int index,book new_book)
{
    if(index < 0 || index > L->length)
        return 0;//位置非法
    if(L->length >= L->capacity)
        return 0;//书架满了

    //将插入位置后面的元素从最后一个元素开始向后移
    for(int i = L->length;i>index;i--)
    {
        L->elem[i] = L->elem[i-1];
    }
    L->elem[index] = new_book;
    L->length++;
    return 1;
}

//删除
int del_book(SQlist* L)
{
    if(L == NULL)
    {
        printf("书架已经空了！\n");
        return 0;
    }

    int n;
    printf("请选择删除的书：");
    scanf("%d", &n);
    int index = n - 1;

    if(index<0 || index>L->length-1)
    {
        printf("选择错误！\n");
        return 0;
    }
    for(int i = index;i+1<L->length;i++)
    {
        L->elem[i] = L->elem[i+1];
    }
    L->length--;
    printf("删除成功！\n");
    return 1;
}

//查找书
int search_book(SQlist* L)
{
    if(L == NULL || L->length == 0)
    {
        printf("书架为空！");
        return 0;
    }

    char book[20];
    printf("请输入查找书籍：\n");
    scanf("%s",book);
    for(int i = 0;i<L->length;i++)
    {
        if(strcmp(book,(L->elem)[i].name) == 0)
        {
            printf("找到了：\nISBN:%s | name:%s |price:%d\n",(L->elem)[i].isbn,(L->elem)[i].name,(L->elem)[i].price);
            return 1;
        }
    }
    printf("没找到！\n");
    return 0;
}

//打印书架
int print_book(SQlist* L)
{
    if(L == NULL)
    {
        printf("书架为空！\n");
        return 0;
    }
    for(int i = 0;i<L->length;i++)
    {
        printf("ISBN:%s | name:%s | price:%d￥", (L->elem)[i].isbn, (L->elem)[i].name, (L->elem)[i].price);
        printf("\n");
    }
}

int main()
{
    book books[10] = {{"72834", "数据结构", 35},
                      {"42343","计算机网络",30},
                      {"92348","C语言程序设计",50},
                      {"12363","高等数学",48},
                      {"98234","离散数学",55}};

    SQlist my_books;
    init_list(&my_books);

    push_back(&my_books,books[0]);
    push_back(&my_books,books[1]);
    push_back(&my_books,books[2]);
    push_back(&my_books,books[3]);
    push_back(&my_books,books[4]);

    print_book(&my_books);
    printf("\n");


    // del_book(&my_books);
    // print_book(&my_books);
    search_book(&my_books);


    free(my_books.elem);

    return 0;
}