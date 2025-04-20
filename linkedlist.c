#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print(struct node* head)
{
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void append(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;
    new_node->link = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = new_node;
}

void insert_at_start(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

void insert(struct node** head, int data, int pos)
{
    struct node* temp = *head;
    struct node* prev = NULL;

    if (pos == 1) {
        insert_at_start(head, data);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;
    new_node->link = temp;
    prev->link = new_node;
}

void delete_at_head(struct node** head)
{
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    *head = temp->link;
    free(temp);
}

void delete_last(struct node** head)
{
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp->link == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
}

void delete_at_pos(struct node** head, int pos)
{
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        delete_at_head(head);
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

void delete_linked_list(struct node** head)
{
    struct node* current = *head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }

    *head = NULL;
}

void reverse(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
