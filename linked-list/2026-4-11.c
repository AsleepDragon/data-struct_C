#include <stdio.h>

 typedef struct book{
    char* ISBN;
    char* book_name;
    int book_price;
 }books;
int main()
{
    books book_data;
    book_data.ISBN = "767645";
    book_data.book_name = "数据结构";
    book_data.book_price = 35;

    printf("%s\n%s\n%d\n",book_data.ISBN,book_data.book_name,book_data.book_price);

    return 0;
}