#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * convert(char * s, int numRows){
    int size=numRows==1?1:(numRows*2-2);
    int now=0,row=0,space=size-row;
    char *a=(char *)malloc(sizeof(char)*1000);//用malloc可以存在到程式結束
    for(int i=0;i<strlen(s);)
    {
        a[i]=s[now];
        if(row!=numRows-1&&row!=0)
        {
            i++;
            if((space)>=strlen(s))//若過大就重置
            {
                row++;
                now=row;
                space=size-row;
                continue;
            }
            else
            {
                a[i]=s[space];//非第一排或最後一排，會有斜上角要處理
                space+=size;//同一輪內斜上角差距是size-行數，每組斜上角間距也是size
            }
        }
        i++;
        now+=size;//每組間距是size
        if(now>=strlen(s))
        {
            row++;
            now=row;
            space=size-row;
        }
    }
    a[strlen(s)]='\0';//最後放入字串結尾(因為不知道是一個個輸出還是直接輸出字串)
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