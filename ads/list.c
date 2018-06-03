#include"list.h"

NodeList * Array2List(int *arry,int size)
{
    NodeList *list=(NodeList *) malloc(sizeof(NodeList));
    if(list==NULL){
        return NULL;
    }
    NodeList *index=list;
    for(int i=0;i<size;i++){
        index->val=arry[i];
        if(i==size-1){
            index->next=NULL;
        }
        else{
            index->next=(NodeList *) malloc(sizeof(NodeList));
            if(index->next==NULL){
                FreeList(list);
                return NULL;
            }
            index=index->next;
        }
    }
    return list;
}

int FreeList(NodeList *list)
{
    NodeList *tmp=list;
    while(tmp->next != NULL){
        tmp=list->next;
        free(list);
        list=tmp;
    }
    free(list);
    return 0;
}

NodeList *ReverseList(NodeList *list)
{
    NodeList *index=list;
    NodeList *tail=malloc(sizeof(NodeList));
    NodeList *head=tail;
    head->next=NULL;

    while(index!=NULL){
        head->val=index->val;
        if(index->next==NULL){
            break;
        }
        else{
            index=index->next;
            head=malloc(sizeof(NodeList));
            head->next=tail;
            tail=head;
        }   
    }
    return head;
}

int IsHasLoop(NodeList *list)
{

}


//test
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printf("size of a [%lu]\n",(sizeof a)/sizeof (int));
    NodeList *b=Array2List(a,(sizeof a)/sizeof (int));

    printf("test Array2List =========\n");
    NodeList *cusor=b;
    do{
        printf("node:[%x],val:[%d],next:[%x]\n",(unsigned int)cusor,cusor->val,(unsigned int)cusor->next);
        cusor=cusor->next;
    }while(cusor!=NULL);

    printf("test ReverseList =========\n");
    NodeList *c=ReverseList(b);
    cusor=c;
    do{
        printf("node:[%x],val:[%d],next:[%x]\n",(unsigned int)cusor,cusor->val,(unsigned int)cusor->next);
        cusor=cusor->next;
    }while(cusor!=NULL);

}
