#include "../include/list.h"

int main ()
{
    List* list =  create_list(5);
    list_dump(list);
    
    for (int i = 0; i < 8; i++)
    {
        add_to_list(list, i);
        list_dump(list);
    }

    // list
    // // Node* new_head = list.head;

    // move_to_head(list, 3);
    // list_dump(list);

    for (int i = 8; i < 15; i++)
    {
        add_to_list(list, i);
        list_dump(list);
    }
}