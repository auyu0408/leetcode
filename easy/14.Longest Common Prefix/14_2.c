#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs,int strSize)
{
    if(strSize<=0) return"";
    char *tmp;
	int i=0,j=sizeof(strs[0]);
    tmp=strs[0];
	for(i=0;i<strSize;i++)
	{
		for(int k=0;k<j;k++)
		{
			if(tmp[k]!=strs[i][k])
			{
				tmp[k]='\0';
				j=k;
			}
		}
	}
	return tmp;
}
int main()
{
	int n;
	scanf("%d",&n);
	char **str=(char **)malloc(sizeof(char *)*n);
	for(int i=0;i<n;i++)
	{	
		str[i]=(char *)malloc(sizeof(char)*200);
		scanf("%s",str[i]);
	}
	char *ans;
	ans=longestCommonPrefix(str,n);
	printf("%s",ans);
	return 0;
}
