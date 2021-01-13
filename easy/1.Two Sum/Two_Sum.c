#include<stdio.h>
#include<stdlib.h>
#define MAX 1005

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *Value;
    *returnSize=2;
    Value=(int *)malloc(sizeof(int)*(*returnSize));
    
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                Value[0]=i;
                Value[1]=j;
                break;
            } 
        }
    }
    return Value;
}
int main()
{
    int *num,*size;
    int *value,len=0,tar,temp;
    size=(int *)malloc(sizeof(int));
    num=(int *)malloc(sizeof(int)*MAX);
    while(scanf("%d",&temp)!=EOF)
    {
        *(num+len)=temp;
        len++;
    }
    tar=num[len-1];
    value=twoSum(num,len-1,tar,size);
    printf("[%d,%d]",value[0],value[1]);
    return 0;
}