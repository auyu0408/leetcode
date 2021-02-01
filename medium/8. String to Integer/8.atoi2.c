#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int judge(int x,int flag,char *tmp)
{
  
    if((-x)<=INT_MIN/10&&flag==1)
    {
        if(-x==INT_MIN/10)
        {
            if((*tmp)>='8') x=INT_MIN;
        }
        else x=INT_MIN;   
    }   
    else
    {
        if(x==INT_MAX/10)
        {
            if((*tmp)>='7') x=INT_MAX;
        }
        else x=INT_MAX;
    }
    return x;
}
int myAtoi(char * s){
    int x=0,count,flag=0,read=0;
    char *tmp=s,prev=0;
    while((*tmp)!='\0')
    {
        if((*tmp)==' ');
        else if((*tmp)=='-'||(*tmp)=='+'||((*tmp)>='0'&&(*tmp)<='9'))
        { 
            read=1;
            if((*tmp)=='-') flag=1;
            if((*tmp)>='0'&&(*tmp)<='9') x=x*10+(*tmp-'0');
            prev=*tmp,tmp++;
            while((*tmp)!='\0')
            {
                if((*tmp)>='0'&&(*tmp)<='9')
                {
                    if((-x)<=INT_MIN/10||x>=INT_MAX/10)
                    {
                        x=judge(x,flag,tmp);
                        if(x==INT_MAX||x==INT_MIN) break;
                    }
                     x=x*10+((*tmp)-'0');
                     prev=*tmp,tmp++;
                }
                else break;
            }  
            break;
        } 
        else break;
        prev=*tmp,tmp++;
    }
    if(flag)
    {
        if(x<=INT_MIN) x=INT_MIN;
        else x*=-1;
    }
    return x;
}
int main()
{
    char str[1000];
    gets(str);
    int ans;
    ans=myAtoi(str);
    printf("%d",ans);
    return 0;
}