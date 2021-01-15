#include<stdio.h>
#include<string.h>

int lengthOfLongestSubstring(char * s){
    int check[128]={0},count,max,l;
    l=(int)strlen(s);
    char *i,*j;
    count=max=0;
    i=j=s;
    while(j!=s+l)
    {
        int tmp=*(j);
        if(check[tmp]==0)
        {
            check[tmp]=1;
            j++;
            count++;
        }
        else
        {
            memset(check,0,sizeof(check));
            i++;
            count=0;
            j=i;
        }
        if(count>max) max=count;
    }
    return max;
}
int main()
{
    char s[20]="";//自己改大小
    int ans;
    ans=lengthOfLongestSubstring(s);
    printf("%d",ans);
    return 0;
}