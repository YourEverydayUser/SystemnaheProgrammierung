#include <ctype.h>
#include <stdio.h>

int main()
{
    char s[] = "Example @ toupper #123";
    int i = 0;
    while(s[i]) {
      putchar (toupper(s[i]));
      i++;
    }
    return 0;
}
