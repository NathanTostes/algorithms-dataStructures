#include <stdio.h>

struct Node
{
    char *string;
    struct Node* nextNode;
};

struct LinkedList
{
    struct Node* firstNode;
};

void addValueInLinkedList(struct LinkedList* linkedList, char string[]) 
{
    struct Node newNode = {string, NULL};
    struct Node* listNode = linkedList->firstNode;
    while(listNode != NULL)
    {
        listNode = listNode->nextNode;
    }
    listNode = &newNode;
}

void iterateLinkedList(struct LinkedList* linkedList)
{
    struct Node* node = linkedList->firstNode;
    while(node != NULL)
    {
        printf("%s\n--------\n", node->string);
        node = node->nextNode;
    }
}

void main()
{
    struct Node node1 = {"Nathan", NULL};
    struct LinkedList linkedList = {&node1};
    iterateLinkedList(&linkedList);
}
