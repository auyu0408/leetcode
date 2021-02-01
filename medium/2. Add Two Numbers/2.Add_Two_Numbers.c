#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* newnode(int value){
    struct ListNode* newptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    newptr->val=value;
    newptr->next=NULL;
    return newptr;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry=0;
    struct ListNode *nowl1=l1;
    struct ListNode *nowl2=l2;
    struct ListNode *prevl1=l1;
    while(nowl1!=NULL||nowl2!=NULL)
    {
        if(nowl1==NULL) prevl1->next=nowl1=newnode(0);
        if(nowl2!=NULL) nowl1->val+=nowl2->val;
        nowl1->val+=carry;
        if((nowl1->val)>9)
        {
            (nowl1->val)-=10;
            carry=1;
        }
        else carry=0;
        prevl1=nowl1;
        if(nowl1!=NULL) nowl1=nowl1->next;
        if(nowl2!=NULL) nowl2=nowl2->next;
    }
    if(carry!=0) 
    {
        prevl1->next=newnode(carry);
    }
    return l1;
}//l1會被改掉
/*struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry=0;
    struct ListNode *nowl1=l1;
    struct ListNode *nowl2=l2;
    struct ListNode *head=NULL;
    struct ListNode *tail=NULL;
    struct ListNode *now=head;
    while(nowl1!=NULL||nowl2!=NULL)
    {
        now=newnode(0);
        if(nowl1!=NULL) now->val+=nowl1->val;
        if(nowl2!=NULL) now->val+=nowl2->val;
        now->val+=carry;
        if((now->val)>9)
        {
            (now->val)-=10;
            carry=1;
        }
        else carry=0;
        if(head==NULL) head=now;
        if(tail!=NULL) tail->next=now;
        tail=now;
        if(nowl1!=NULL) nowl1=nowl1->next;
        if(nowl2!=NULL) nowl2=nowl2->next;
    }
    if(carry!=0) 
    {
        now=newnode(1);
        tail->next=now;
    }
    return head;
}*///l1留著，空間消耗多
int main()
{
    int tmp;
    struct ListNode *l1=NULL;
    struct ListNode *l2=NULL;
    struct ListNode *l3=NULL;
    struct ListNode *tptr=l1;
    while((tmp=getchar())!='\n')
    {
        tmp=tmp-'0';
        tptr=newnode(tmp);
        tptr->next=l1;
        l1=tptr;
    }
    tptr=l2;
    while((tmp=getchar())!='\n')
    {
        tmp=tmp-'0';
        tptr=newnode(tmp);
        tptr->next=l2;
        l2=tptr;
    }
    l3=addTwoNumbers(l1,l2);
    tptr=l3;
    while(tptr!=NULL)
    {
        printf("%d",tptr->val);
        tptr=tptr->next;
    }
    return 0;
}