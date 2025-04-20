#include <stdio.h>
#include "linkedlist.h"

int main()
{
    struct node* head = NULL;

    for (int i = 0; i < 8; i++) {
        append(&head, i);
    }

    print(head);

    insert_at_start(&head, 67);
    print(head);

    insert(&head, 56, 1);
    print(head);

    delete_at_head(&head);
    print(head);

    delete_last(&head);
    print(head);

    delete_at_pos(&head, 3);
    print(head);

    reverse(&head);
    print(head);

    delete_linked_list(&head);
    print(head);

    return 0;
}
