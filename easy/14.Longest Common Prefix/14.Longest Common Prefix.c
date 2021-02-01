#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs,int strSize)
{
	if(strSize<=0) return "";//,,要注意資料是否真的需要比,0個的話也不用比
	char* ans=(char *)malloc(sizeof(char)*(strlen(str[0]+1)));
	strncpy(ans,strs[0],strlen(strs[0]));
	int len=strlen(strs[0]),i,j;
	for(i=0;i<len;i++)
	{
		char tmp=strs[0][i];
		for(j=0;j<strSize;j++)
		{
			if(i<strlen(strs[j]))//還要注意是不是會越界,重點！
			{
				if(tmp!=strs[j][i])
				break;
			}
			else break;
		}
		if(j==strSize) ans[i]=tmp;
		else break;
	}
	ans[i]='\0';
	return ans;
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
