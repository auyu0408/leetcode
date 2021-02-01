#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isPalindrome(int x){
    if (x<0) return false;
    char con[20];
    sprintf(con,"%d",x);//把想印的東西格式化成字串，所以想把數字轉字串就是想印數字
    int len=(int)strlen(con);
    for(int i=0;2*i<len;i++)
    {
        if(con[i]!=con[len-1-i]) return false;
    }
    return true;
}
int main()
{
    int x;
    bool ans;
    scanf("%d",&x);
    ans=isPalindrome(x);
    if(ans) printf("T");
    else printf("F");
}