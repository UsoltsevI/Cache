# Cache project

## List functuons:
To create list:
```
struct list* create_list(size_t number_of_elements)
```
To move node to head:
```
void move_to_head(struct list* lst, struct node* nd)
```
To add value to list
```
struct node* add_value(struct node* nd)
```
To get head
```
struct node* get_head(struct list* list)
```
To delete list
```
void delete_list(struct list* list);
```