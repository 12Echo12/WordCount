#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *rfp;
    int charCnt = 0;/*文件字符计数器*/
    int wordCnt = 0;
    char option[4];
    char file[20];
    scanf("%s %s",option,file);
    rfp=fopen(file,"r");
    if(rfp==NULL)
    {
        printf("Can't open file %s.\n",file);
        exit(1);
    }
    char a;
    int flag = 0;
    while((a = fgetc(rfp))!=EOF)
    {
        charCnt++;
        if(a == ' '|| a == ',')
        flag = 0;
        else if(flag == 0){
        	flag = 1;
        	wordCnt++;
		}
    }
    fclose(rfp);/*关闭文件*/
    if(option[1] == 'c')
    printf("该文件中的字符个数为：%d\n",charCnt);
    else if(option[1] == 'w') 
    printf("该文件中的单词个数为：%d",wordCnt);
    return 0;
}

