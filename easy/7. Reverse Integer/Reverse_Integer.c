#include<stdio.h>
#include<limits.h>//反轉若太大，return 0

int reverse(int x){
    if(x>INT_MAX||x<=INT_MIN) return 0;//本來就大於的也不行
    int y=0;
    while(x!=0)
    {
        if(y>(INT_MAX/10))//轉過去大於極限值
        return 0;
        if(y<(INT_MIN/10))
        return 0;
        y=y*10+(x%10);
        x=x/10;
    }
    return y;
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",reverse(x));
    return 0;
}