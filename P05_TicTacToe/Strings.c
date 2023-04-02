#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORDS 10
#define MAX_CHARS 20


int main()
{

    char words[MAX_WORDS][MAX_CHARS];
    int i, j, k, ind;
    char c;
    char holder[MAX_CHARS];
   
   /*One could also do the sorting in this loop*/
    for(i=0; i < MAX_WORDS; i++) {
        scanf("%s", words[i]);
        
        for(j=0; j < MAX_CHARS; j++) {
          words[i][j] = toupper(words[i][j]);
        }
        
        for(k=0; k < i; k++) {
          if(strcmp(words[k], words[i])==0) {
            strcpy(words[i], holder);
            i--;
          }
       }       
    }
    
    for(ind=i=0; i < MAX_WORDS; i++) {
        strcpy(holder, words[i]);
        for(j=i+1; j < MAX_WORDS; j++) {
            if(strcmp(holder, words[j]) > 0) {
                strcpy(holder, words[j]);
                ind = j;
            }
        }
        strcpy(words[ind], words[i]);
        strcpy(words[i], holder);
    }

    for(i=0; i < MAX_WORDS; i++) {
        printf("%s \n", words[i]);
    }

    return (0);
}
