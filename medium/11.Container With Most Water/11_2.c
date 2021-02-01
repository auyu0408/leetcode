#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height,int heightSize){
	int max=0;
    int head=0,tail=heightSize-1;
    while(head!=tail)
    {
        int high=height[head]<height[tail]?height[head]:height[tail];//一開始最寬，如果希望面積更大，縮小寬時要增加長，只有若是更換長的長，那麼即使換到更大的長，面積仍受短邊長控制
        int area=(tail-head)*high;
        if(area>max) max=area;
        if(height[head]<height[tail]) head++;
        else tail--;
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

