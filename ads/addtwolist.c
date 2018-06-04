/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdlib.h>
#include<math.h>
struct ListNode* ReverseList(struct ListNode* list){
    struct ListNode *index=list;
    struct ListNode *tail=malloc(sizeof(struct ListNode));
    struct ListNode *head=tail;
    head->next=NULL;

    while(index!=NULL){
        head->val=index->val;
        if(index->next==NULL){
            break;
        }
        else{
            index=index->next;
            head=malloc(sizeof(struct ListNode));
            head->next=tail;
            tail=head;
        }   
    }
    return head;
}

struct ListNode * Array2List(int *arry,int size)
{
    struct ListNode *list=(struct ListNode *) malloc(sizeof(struct ListNode));
    if(list==NULL){
        return NULL;
    }
    struct ListNode *index=list;
    for(int i=0;i<size;i++){
        index->val=arry[i];
        if(i==size-1){
            index->next=NULL;
        }
        else{
            index->next=(struct ListNode *) malloc(sizeof(struct ListNode));
            if(index->next==NULL){
                FreeList(list);
                return NULL;
            }
            index=index->next;
        }
    }
    return list;
}

int List2Int(struct ListNode* list){
    int i=0;
    int num=0;
    struct ListNode* cursor=list;
    for(;cursor!=NULL;cursor=cursor->next){
        i++;
    }
    for(cursor=list;cursor!=NULL;cursor=cursor->next){
        num+=cursor->val*pow(10,(i-1));
        i--;
    }
    return num;  
}

struct ListNode* Int2List(int num){
    //struct ListNode* tmp=malloc(sizeof(struct ListNode));
    int bits=1;
    for(;num/(pow(10,bits)!=0;bits++);
    int *ary=malloc(bits*sizeof(int));
    for(int k=bits-1,int m=0;k>=0;k--,m++){
        if(m==0){
            ary[m]=num/pow(10,k);
        }else{
            int n=0;
            int l=m;
            ary[m]=num/pow(10,k);
            while(n<m){
                ary[m]=ary[m]-ary[n]*pow(10,l)
                    n++;
                    l--;
            }
                
        }
    
    }
    return Array2List(ary,bits);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int n1=List2Int(l1);
    int n2=List2Int(l2);
    int sum=n1+n2;
    return ReverseList(Int2List(sum));
}
