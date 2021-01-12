#include<stdio.h>
#include<stdlib.h>
#define MAX 1005
#define P 911//importance of key
typedef struct NODE
{
    int index;
    struct NODE*next;
}node;
typedef struct Hash
{
    node *Node;
}hash;
void initial(hash adr[])
{
    for(int i=0;i<P;i++)
    {
        adr[i].Node=NULL;
    }
}
void hashing(hash adr[],int key,int idx)
{
    int rtmp=abs(key)%P;
    node* tptr=(node *)malloc(sizeof(node));
    tptr->index=idx;
    tptr->next=NULL;
    if(adr[rtmp].Node==NULL)
    {
        adr[rtmp].Node=tptr;
    }
    else{
        node* nptr=adr[rtmp].Node;
        while(nptr->next!=NULL)
        {
            nptr=nptr->next;
        }
        nptr->next=tptr;
    }
}
void free_hash(hash table[])
{
    for(int i=0;i<P;i++)
    {
        node* now=table[i].Node;
        while(now!=NULL)
        {
            node* prev=now;
            now=now->next;
            free(prev);
        }
        free(now);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *Value=(int *)malloc(sizeof(int)*(*returnSize));
    hash Table[P];
    initial(Table);
    for(int i=0;i<numsSize;i++)
    {
        hashing(Table,nums[i],i);
    }
    for(int i=0;i<numsSize;i++)
    {
        int keys=target-nums[i];
        node* nptr=Table[abs(keys)%P].Node;//negative integer also need to notice
        int flag=0;
        while(nptr!=NULL)
        {
            if(nums[nptr->index]==keys&&nptr->index!=i)
            {
                Value[0]=i;
                Value[1]=nptr->index;
                flag=1;
            }
            nptr=nptr->next;
        }
        if(flag) break;
    }
    free_hash(Table);
    return Value;
}
int main()
{
    int num[MAX],*size;
    int *value,len=0,tar,temp;
    size=(int *)malloc(sizeof(int));
    while(scanf("%d",&temp)!=EOF)
    {
        num[len]=temp;
        len++;
    }
    tar=num[len-1];
    value=twoSum(num,len-1,tar,size);
    printf("[%d,%d]",value[0],value[1]);
    return 0;
}