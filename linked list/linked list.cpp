#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef struct linklist
{
    node_t* headptr;
} linklist_t;

linklist_t* create_linklist()
{
    linklist_t* new_list = (linklist_t*)malloc(sizeof(linklist_t));
    new_list->headptr = NULL;
    return new_list;
}

void append_to_linklist(linklist_t* list, node_t* new_node, int _data)
{
    if (list->headptr == NULL)
    {
        list->headptr = new_node;
        new_node->data = _data;
        new_node->next = NULL;
    }
    else
    {
        node_t* current = list->headptr;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = NULL;
        new_node->data = _data;
    }
}

void append(linklist_t* list, int _data) {
    node_t* node_1 = (node_t*)malloc(sizeof(node_t));
    append_to_linklist(list, node_1, _data);
}
void print_linklist(linklist_t* list)
{
    node_t* current = list->headptr;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    linklist_t* list = create_linklist();
    append(list, 3);
    append(list, 4);
    append(list, 5);
    append(list, 6);
    append(list, 7);

    print_linklist(list);
    return 0;
}
// result : 3->->4->5->6->7