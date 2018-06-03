#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NodeList;

NodeList * Array2List(int *arry,int size);
int FreeList(NodeList *list);
NodeList *ReverseList(NodeList *list);
int IsHasLoop(NodeList *list);
