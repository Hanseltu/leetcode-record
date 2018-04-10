#include<stdio.h>
#include<string.h>
#include<stdlib.h>


    char* longestCommonPrefix(char** strs,int strsSize){
    int i = 0,j = 0,tempindex = 0;
    int index;
    if (strsSize < 1)
    {
        return "";
    }
    index = strlen(strs[0]);
    char* a;
    a = malloc(sizeof(char)*(index+1));
    strcpy(a,strs[0]);
    for (i = 1;i < strsSize;i++)
    {
        tempindex = 0;
        for(j = 0;j < index;j++)
        {
            if(a[j] == strs[i][j])
            {
                tempindex++;
            }
            else
            {
                a[j] = '\0'; /* cut down the string of a */
                break;
            }
        }
        if (tempindex == 0)
        {
            return "";
        }
        if (tempindex < index)
        {
            index = tempindex;
        }
    }
    return a;
}

int main(){
     char *str[4] = {"abc","abd","abs","ab"};
    char* temp = longestCommonPrefix(str,strlen(*str));
    for (int i = 0;i < strlen(temp); i++)
    {
        printf("%c \n",temp[i]);
    }
    return 0;
}