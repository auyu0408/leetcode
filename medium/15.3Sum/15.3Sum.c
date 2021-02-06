#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int hashMap[100000]={0};
int** threeSum(int* nums,int numSize,int* returnSize,int** returnColumnSizes)
{
	qsort(nums,numSize,sizeof(int),cmp);
	if(nums==NULL||numSize<3||nums[0]>0||nums[numSize-1]<0||nums[0]+nums[1]+nums[2]>0)
	{
	    *returnSize=0;
	    return NULL;
	}
	int count=0;
	int **ans=NULL;
	for(int i=0;i<numSize;i++)
	{
		if(nums[i]>=0) hashMap[nums[i]]=1;
	}
	for(int i=0;i<numSize&&nums[i]<=0;i++)
	{
		for(int j=i+1;j<numSize-1;j++)
		{
		    	int flag=0;
		    	while(j<numSize-1&&nums[j]==nums[j+1])
			{
			    j++;
			    flag=1;
			}
			int target=nums[i]+nums[j];
			if(target>0) break;
			if((-target<=nums[numSize-1]&&hashMap[-target]&&nums[j]<-target)||(-target==nums[j]&&flag))
			{
				count++;
			    ans=(int **)realloc(ans,sizeof(int *)*count);
			    ans[count-1]=(int *)malloc(sizeof(int)*3);
			    ans[count-1][0]=nums[i];
			    ans[count-1][1]=nums[j];
			    ans[count-1][2]=-target;
			}
		}
		while(i<numSize-2&&nums[i]==nums[i+1])
		    i++;
	}
	*returnColumnSizes = (int*)malloc(sizeof(int)*(count)); 
    for(int i=0;i<count;i++)
    {
        (*returnColumnSizes)[i]=3;
    }
	*returnSize=count;
	return ans;
}
int main()
{
    int num[3000]={0},*size,**ColumnSizes;
    int **value,len=0,temp;
    size=(int *)malloc(sizeof(int));
	ColumnSizes=(int **)malloc(sizeof(int *));
    while(scanf("%d",&temp)!=EOF)
    {
        num[len]=temp;
        len++;
    }
    threeSum(num,len,size,ColumnSizes);
    return 0;
}
