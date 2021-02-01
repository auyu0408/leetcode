#include<stdio.h>
#include<math.h>
#include<string.h>

char table[5][15][5]={
    {},
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"","M","MM","MMM"}};
char * intToRoman(int num){
    char *ans=(char *)malloc(sizeof(char)*20);
    memset(ans,0,20);//記得初始化，要串接時才找的到尾巴
    int val;
    for(int i=4;i>0;i--)
    {
        val=num/pow(10,i-1);
        strcat(ans,table[i][val]);
        num%=(int)pow(10,i-1);
    }
    return ans;
}
int main()
{
    int x;
    scanf("%d",&x);
    char *num=intToRoman(x);
    puts(num);
    return 0;
}