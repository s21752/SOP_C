#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* value;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    Node *start;
} SinglyLinkedList;

void addNode(SinglyLinkedList* list, void* nodeValue) {

    if (NULL == list->start) {

        list->start = malloc(sizeof(Node));
        list->start->value = nodeValue;
        list->start->next = NULL;

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
        lastNode = lastNode->next;
        lastNode->value = nodeValue;
        lastNode->next = NULL;
    }
}

void* getData(SinglyLinkedList* list, int index) {
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

SinglyLinkedList SinglyLinkedList_new() {
    SinglyLinkedList list;

    list.start = NULL;

    return list;
}

int main()
{
    SinglyLinkedList list = SinglyLinkedList_new();

    int value = 5;
    addNode(&list, &value);

    int value2 = 8;
    addNode(&list, &value2);

    int value3 = 14;
    addNode(&list, &value3);

    float value4 = 19.7f;
    addNode(&list, &value4);

    int* dataInt = getData(&list, 1);

    printf("data is: %d\n", *dataInt);

    float* dataFloat = getData(&list, 3);

    printf("data is: %.1f\n", *dataFloat);

    return 0;
}
