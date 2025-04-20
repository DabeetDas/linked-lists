#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    int data;
    struct node* link;
};

void print(struct node* head);
void append(struct node** head, int data);
void insert_at_start(struct node** head, int data);
void insert(struct node** head, int data, int pos);
void delete_at_head(struct node** head);
void delete_last(struct node** head);
void delete_at_pos(struct node** head, int pos);
void delete_linked_list(struct node** head);
void reverse(struct node** head);

#endif
