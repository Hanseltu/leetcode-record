#include<stdio.h>


char* countAndSay(int n) {
    static char buf1[10240];
    static char buf2[10240];
    
    char *next = buf2, *cur = buf1;
    
    for(int N=1; N<=n; N++) {
        if(N==1) {
            next[0]='1'; next[1]='\0';
        } else {
            int c=0, i=0;
            while(cur[i]) {
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
