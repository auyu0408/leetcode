#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isPalindrome(int x){
    if (x<0) return false;
    char con[20];
    itoa(x,con,10);//non standard function
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