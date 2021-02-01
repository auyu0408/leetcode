#include<stdio.h>
#include<stdlib.h>

double findobject(int *A,int m,int *B,int n)
{
    int i,j,imin=0,imax=m,jmin=0,jmax=n;
    double med;
    while(1)
    {
        i=(imin+imax)/2;
        j=(m+n+1)/2-i;
        if((j==0||i==m||B[j-1]<=A[i])&&(i==0||j==n||A[i-1]<=B[j])) break;//注意判斷順序，要先看是否會溢位
        else if(B[j-1]>A[i]&&j>0&&i<m)
        {
            imin=i+1;
            continue;
        }
        else
        {
            imax=i-1;
            continue;
        }
    }
    if((m+n)%2!=0)//均須注意溢位問題
    {
        if(i==0||j==0)
        {
            if(i==0) med=B[j-1];
            else med=A[i-1];
        }
        else med=A[i-1]>B[j-1]?A[i-1]:B[j-1];
    }
    else
    {
        double big,small;
        if(i==0||j==0)
        {
            if(i==0) big=B[j-1];
            else big=A[i-1];
        }
        else big=A[i-1]>B[j-1]?A[i-1]:B[j-1];
        if(i==m||j==n)
        {
            if(i==m) small=B[j];
            if(j==n) small=A[i];
        }
        else small=A[i]>B[j]?B[j]:A[i];
        med=(big+small)/2;
    }
    return med;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double medium;
    if(nums2Size>=nums1Size)
    {
        medium=findobject(nums1,nums1Size,nums2,nums2Size);
    }
    else
    {
        medium=findobject(nums2,nums2Size,nums1,nums1Size);
    }
    return medium;
}
int main()
{
    /*int nums1[10]={6,65,337,412,456,542,552,622,750,961};
    int nums2[15]={1,91,197,200,274,342,489,552,577,663,701,724,779,809,911};*/
    int nums1[2]={1,2};
    int nums2[0]={};
    int size1=2,size2=0;
    double ans;
    ans=findMedianSortedArrays(nums1,size1,nums2,size2);
    printf("%f",ans);
    return 0;
}