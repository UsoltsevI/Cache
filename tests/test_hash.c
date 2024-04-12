// перенеси всю функцию main в отдельный файл /tests/test_hash.c и +
// и используй раздельную компиляцию для тестирования +
#include"../include/hash.h"

int main()
{
    printf("start ");

    table* tb = NULL;
    node* cur = NULL;

    printf("0 ");

    tb = create_table(10);

    printf("1 ");
// не коммить участки кода!!! +
// При необходимости используй #if 0 ...code... #endif +
    # if 0
     tb->list.head->value = 0;
     cur = tb->list.head;
     add_value(tb, cur);

     printf("2 ");

     for(int i = 1; i < 5; ++i) {
         cur = cur->next;
         cur->value = i;
         add_value(tb, cur);

         printf("%d ", i + 2);
     }

     print_table(tb);

     printf("8 ");

     delete_table(tb);

     printf("9 ");
     #endif

}
