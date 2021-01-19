#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int myAtoi(char * s){
    int x=0,count,flag=0,read=0;
    char *tmp=s,prev=0;
    while((*tmp)!='\n')
    {
        if((*tmp)==' '&&read==0);
        else if(((*tmp)=='-'||(*tmp)=='+')&&read==0)
        {
            read=1;
            if((*tmp)=='-') flag=1;
            if(prev=='+'||prev=='-'||(prev>='0'&&prev<='9')) break;
        }
        else if((*tmp)>='0'&&(*tmp)<='9')
        {
            read=1;
            if((-x)<=INT_MIN/10&&flag==1)
            {
                if(-x==INT_MIN/10)
                {
                    if((*tmp)>='8')
                    {
                        x=INT_MIN;
                        break;
                    }
                }
                else
                {
                    x=INT_MIN;
                    break;
                }
                
                
            }
            else if(x>=INT_MAX/10&&flag==0)
            {
                if(x==INT_MAX/10)
                {
                   if((*tmp)>='7')
                   {
                        x=INT_MAX;
                        break;
                   } 
                }
                else
                {
                     x=INT_MAX;
                    break;
                }
            } 
            x=x*10+((*tmp)-'0');
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