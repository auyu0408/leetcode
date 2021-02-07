#include<stdlib.h>
#include<stdio.h>

int comparator(const void *a, const void *b)
{
    return *(const int*)a-*(const int*)b;
}
int** threeSum(int* nums, int size, int* returnSize,int **returnColumnSizes) 
{
    qsort((void *)nums, size, sizeof(int),comparator );
    if(size<3||nums[0]>0||nums[size-1]<0||nums[0]+nums[1]+nums[2]>0)
    {
        *returnSize=0;
        return NULL;
    }
    int count = 0,start=0,end=0;
    int **res = (int **)malloc(sizeof(int *)*100000);
	*returnColumnSizes=(int *)malloc(sizeof(int)*100000);
    for(int i = 0; i < size-2&&nums[i]<=0; i++)
    {

        start = i + 1;
        end = size - 1;
        while(start < end )
        {
            if(nums[start] + nums[end]+nums[i]>0)
                end--;
            else if( nums[start] + nums[end]+nums[i]<0)
                start++;
            else
            {
                res[count] = (int *) malloc(sizeof(int)*3);
                res[count][0] = nums[i];
                res[count][1] = nums[start];
                res[count][2] = nums[end];
				(*returnColumnSizes)[count]=3;
				count++;
				while(start +1 < end&& nums[start] == nums[start + 1])
                    start++;
                while(end-1>start&& nums[end] == nums[end -1])
                    end--;
                
                start++;
                end--;
            }
        }
        while(i + 1 < size-2 && nums[i] == nums[i + 1])
            i++;
    }
    *returnSize = count;
    return res;
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

