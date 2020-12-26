//
// Created by Yuval on 12/26/2020.
//
#include <stdio.h>

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H
typedef struct Node {
    int data;
    struct Node *next;

} Node;


typedef struct LinkedList {
    Node *head;
    int Len;

} LinkedList;


Node *get_to_end(LinkedList *list) {
    Node *current;
    current = list->head;
    while (current->next) {

        current = current->next;

    }
    return current;

}

Node *get_to_index(struct LinkedList *list, int index) {
    if (list->Len < index) {
        return NULL;
    }
    Node *current;
    current = list->head;
    for (int i = 0; i < index; i++) {
        current=current->next;

    }
    return current;
}

void add_to_start(LinkedList *list, int val) {
    list->Len++;
    Node *node = malloc(sizeof(Node));
    node->next = list->head;
    node->data = val;
    list->head = node;

}

void add_to_end(LinkedList *list, int val) {
    list->Len++;
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = val;
    if (!list->head) {
        list->head = node;
        return;
    }
    Node *last;
    last = (get_to_end(list));


    last->next = node;

}

void add_at_index(LinkedList *list, int index, int val){
    Node *new_node = malloc(sizeof(Node));
    new_node->data=val;
    if (index>list->Len){
        return;
    }
    if(index==0){
        new_node->next=list->head;
        list->head=new_node;
        return;
    }
    Node *old_node;
    old_node = get_to_index(list, index-1);
    new_node->next=old_node->next;
    old_node->next=new_node;
    list->Len++;


}

void remove_from_list(LinkedList *mylist, int index) {
    Node *current;
    if (index >= mylist->Len) {
        return;
    }

    current = mylist->head;
    if (index == 0) {
        mylist->head = current->next;
        free(current);
        return;

    }
    for (int i = 1; i < index; i++) {
        current = current->next;

    }
    current->next = current->next->next;
    free(current->next);


}

int get_len_list(LinkedList *mylist) {
    return mylist->Len;
}

void print_list(LinkedList *mylist) {
    Node *current;
    current = mylist->head;
    printf("[");
    while (current->next) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
    printf("]\n");
}

LinkedList merge(LinkedList *list1, LinkedList *list2) {
    Node *list1ptr;
    Node *list2ptr;

    list1ptr = list1->head;
    list2ptr = list2->head;

    LinkedList returnList;
    returnList.Len = 0;
    returnList.head = NULL;
    while (list1ptr != NULL && list2ptr != NULL) {
        if (list1ptr->data < list2ptr->data) {
            add_to_end(&returnList, list1ptr->data);
            list1ptr = list1ptr->next;
        } else {
            add_to_end(&returnList, list2ptr->data);
            list2ptr = list2ptr->next;
        }
    }

    while (list1ptr != NULL) {
        add_to_end(&returnList, list1ptr->data);
        list1ptr = list1ptr->next;
    }
    while (list2ptr != NULL) {
        add_to_end(&returnList, list2ptr->data);
        list2ptr = list2ptr->next;
    }
    return returnList;


}

#endif //UNTITLED_LINKEDLIST_H
