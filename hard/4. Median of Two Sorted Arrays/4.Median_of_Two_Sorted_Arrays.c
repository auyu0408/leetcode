#include<stdio.h>
#include<stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size=nums1Size+nums2Size,count,now1,now2;
    count=now1=now2=0;
    int *merged=(int *)malloc((nums1Size+nums2Size)*sizeof(int));
    while(count<size)
    {
        if(now1<nums1Size&&now2<nums2Size)
        {
            if(nums1[now1]<nums2[now2])
            {
                merged[count]=nums1[now1++];
            }
            else
            {
                merged[count]=nums2[now2++];
            } 
        }
        else if(now1>=nums1Size)
        {
            merged[count]=nums2[now2++];
        }
        else
        {
            merged[count]=nums1[now1++];
        }
        count++;
    }
    if(size%2==0)
    {
        double i=merged[(size/2)-1],j=merged[size/2];
        return (i+j)/2;
    }
    else
    {
        return merged[size/2];
    }
}
int main()
{
    /*int nums1[10]={6,65,337,412,456,542,552,622,750,961};
    int nums2[15]={1,91,197,200,274,342,489,552,577,663,701,724,779,809,911};*/
    int nums1[2]={1,2};
    int nums2[2]={3,4};
    int size1=2,size2=2;
    double ans;
    ans=findMedianSortedArrays(nums1,size1,nums2,size2);
    printf("%f",ans);
    return 0;
}