#include<stdio.h>

int romanToInt(char * s)
{
    char *tmp=s,*prev=s;
    int x=0;
    while((*tmp)!='\0')
    {
        if((*tmp)=='M') 
        {
            if((*prev)=='C') x+=800;
            else x+=1000;
        }
        else if((*tmp)=='D')
        {
            if((*prev)=='C') x+=300;
            else x+=500;
        }
        else if((*tmp)=='C')
        {
            if((*prev)=='X') x+=80;
            else x+=100;
        }
        else if((*tmp)=='L')
        {
            if((*prev)=='X') x+=30;
            else x+=50;
        }
        else if((*tmp)=='X')
        {
            if((*prev)=='I') x+=8;
            else x+=10;
        }
        else if((*tmp)=='V')
        {
            if((*prev)=='I') x+=3;
            else x+=5;
        }
        else x+=1;
        prev=tmp,tmp++;
    }
    return x;
}
int main()
{
    char s[20];
    scanf("%s",&s);
    int ans;
    ans=romanToInt(s);
    printf("%d",ans);
    return 0;
}