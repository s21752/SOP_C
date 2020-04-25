#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* value;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct DoublyLinkedList {
    Node *start;
} DoublyLinkedList;

void addNode(DoublyLinkedList* list, void* nodeValue) {

    if (NULL == list->start) {

        list->start = malloc(sizeof(Node));
        list->start->value = nodeValue;
        list->start->next = NULL;
        list->start->previous = NULL;

    } else {

        Node* lastNode;
        lastNode = list->start;

        while (true) {
            if(lastNode->next == NULL) {

                break;
            } else {

                lastNode = lastNode->next;
            }
        }

        lastNode->next = malloc(sizeof(Node));
        lastNode->next->previous = lastNode;
        lastNode = lastNode->next;
        lastNode->value = nodeValue;
        lastNode->next = NULL;
    }
}

Node* getNode(DoublyLinkedList* list, int index) {
    int currentNodeIndex = 0;

    if(NULL == list->start) {
        printf("List is empty\n");
        return;
    } else {
        Node* lastNode = list->start;

        while(true) {
            if(currentNodeIndex == index) {
                return lastNode;
            } else {
                if(lastNode->next == NULL){
                    printf("Index bigger than last list index error\n");
                    return NULL;
                } else {
                    lastNode = lastNode->next;
                    currentNodeIndex++;
                }
            }
        }
    }
}

void* getData(DoublyLinkedList* list, int index) {
    int currentNodeIndex = 0;

    if(NULL == list->start) {
        printf("List is empty\n");
        return;
    } else {
        Node* lastNode = list->start;

        while(true) {
            if(currentNodeIndex == index) {
                return lastNode->value;
            } else {
                if(lastNode->next == NULL){
                    printf("Index bigger than last list index error\n");
                    return NULL;
                } else {
                    lastNode = lastNode->next;
                    currentNodeIndex++;
                }
            }
        }
    }
}

DoublyLinkedList DoublyLinkedList_new() {
    DoublyLinkedList list;

    list.start = NULL;

    return list;
}

int main()
{
    DoublyLinkedList list = DoublyLinkedList_new();

    int value = 5;
    addNode(&list, &value);

    int value2 = 8;
    addNode(&list, &value2);

    int value3 = 14;
    addNode(&list, &value3);

    int value4 = 19;
    addNode(&list, &value4);

    int* data = getData(&list, 2);

    printf("data is: %d\n", *data);

    Node* node = getNode(&list, 1);

    printf("current node data is: %d\n", *(int*) node->value);
    printf("previous node data is: %d\n", *(int*) node->previous->value);
    printf("next node data is: %d\n", *(int*) node->next->value);

    return 0;
}
