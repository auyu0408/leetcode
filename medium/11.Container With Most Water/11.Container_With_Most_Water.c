#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height,int heightSize){
	int max=0;
	for(int i=0;i<heightSize;i++)
	{
		for(int j=i+1;j<heightSize;j++)
		{
			int high=*(height+i)>*(height+j)?*(height+j):*(height+i);
			int area=high*(j-i);
			if(area>max) max=area;
		}
	}
	return max;
}
int main()
{
	int tmp,size=0;
	int* height=(int *)malloc(sizeof(int)*30000);
	while(scanf("%d",&tmp)!=EOF)
	{
		*(height+size)=tmp;
		size++;
	}
	printf("%d",maxArea(height,size));
	return 0;
}
