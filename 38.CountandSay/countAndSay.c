#include<stdio.h>
#include<string.h>

//不是很懂
char* countAndSay(int n) {
    static char buf1[10240];
    static char buf2[10240];

    char *next = buf2, *cur = buf1;

    for(int N=1; N<=n; N++)
    {
        if(N==1)
        {
            next[0]='1'; next[1]='\0';
        }
        else
        {
            int c=0, i=0;
            while(cur[i])
            {
                int j;
                for(j=i+1; cur[j]==cur[i]; j++);
                next[c++] = '0'+j-i;
                next[c++] = cur[i];
                i=j;
            }
            next[c] = '\0';
        }
        char *tmp = cur;
        cur = next;
        next = tmp;
    }
    return cur;
}


int main(){
    const char* temp = countAndSay(5);
    for (int i = 0; i < (int)strlen(temp); i++)
        printf("%c \t",temp[i]);
    printf("\n");
    return 0;
}
