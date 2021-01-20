#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * convert(char * s, int numRows){
    int size=numRows*2-2,len=strlen(s);
    int now=0,row=0,space=size-row;
    char *a=(char *)malloc(sizeof(char)*1000);
    if (numRows==1) size=1;
    for(int i=0;i<strlen(s);)
    {
        a[i]=s[now];
        if(row==numRows-1||row==0)
        {
            i++;
            now+=size;
        }
        else
        {
            if((space)>=strlen(s))
            {
                i++;
                row++;
                now=row;
                space=size-row;
                continue;
            }
            else
            {
                i++;
                a[i]=s[space];
                space+=size;
            }
            i++;
            now+=size;
        }
        if(now>=strlen(s))
        {
            row++;
            now=row;
            space=size-row;
        }
    }
    a[strlen(s)]='\0';
    return a;
}
int main()
{
    char s[1000],*ans;
    int num;
    scanf("%s",s);
    scanf("%d",&num);
    ans=convert(s,num);
    printf("%s",ans);
    return 0;
}