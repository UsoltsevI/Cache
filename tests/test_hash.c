// перенеси всю функцию main в отдельный файл /tests/test_hash.c и +
// и используй раздельную компиляцию для тестирования +
#include <stdio.h>
#include"../include/hash.h"

int main()
{
    printf("start ");

    TMap* tb = NULL;
    THashContent ptr = NULL;

    printf("0\n");

    tb = create_table(10);

     printf("1\n");

     for(int i = 1; i < 5; ++i) {
         add_value(tb, NULL, i);

         printf("%d\n", i + 1);
     }
    ptr = search_cell(tb, 3);

    printf("6\n");
    print_hash_table(tb);

    printf("7\n");

    ptr = delete_cell(tb, 3);

    ptr = search_cell(tb, 3);

    printf("8\n");
    delete_table(tb);

    printf("9\n");
  //   #endif

}
