#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *table[10][4]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}
void loop(char tmp[4],tmplen,int loc,int len,int *size)
{
	if(loc>=len)
	{
		ans=(char **)realloc(ans,sizeof(char *)*());
		ans[count-1]=(char *)malloc(sizeof(char)*(tmplen+1));
		for(int i=0;i<tmplen;i++)
		{
			ans[count-1][i]=tmp[i];
		}
		ans[tmplen]='\0';
		return;
	}
	else
	{
		for(int i=0;i<strlen(table[loc]);i++)
		{
			tmp[tmplen]=table[loc][i];
			loop(tmp,tmplen+1,loc+1,len);
		}
	}
}
char **ans=NULL;
char **letterCombinations(char * digits,int*returnSize)
{
	int len=strlen(digits),count;
	char tmp[4];
	loop(tmp,0,0,len,&count);	
	*returnSize=count;
	return ans;
}
int main()
{
	char str[5];
	scanf("%s",str);
	int *Size;
	char **ans;
	ans=letterCombinations(str,Size);
	return 0;
}
