#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char string[32];
    struct Node * next;   
} Node;

typedef struct LinkedList
{
    Node * head;
} LinkedList;

void addElementInList(LinkedList *linkedList, char string[]) 
{
    Node * newNode = NULL;
    newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->string, string);
    newNode->next = linkedList->head;
    linkedList->head = newNode;
}

void printAllListElements(LinkedList linkedList) {
    Node * currentNode = linkedList.head;
    while(currentNode->next != NULL) {
        printf("%s\n", currentNode->string);
        currentNode = currentNode->next;
    }
}

void main() 
{
    LinkedList linkedList;
    linkedList.head = NULL;
    linkedList.head = malloc(sizeof(Node));

    addElementInList(&linkedList, "Nathan");
    addElementInList(&linkedList, "Marcos");
    addElementInList(&linkedList, "João");
    addElementInList(&linkedList, "Luis");
    printAllListElements(linkedList);
}
