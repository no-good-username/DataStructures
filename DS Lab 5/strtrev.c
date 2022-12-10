#include <stdio.h>
#include <string.h>

void revstr(char *z, int start, int end)
{
    char ch;

    if (start >= end)
       return;

    ch = *(z+start);
    *(z+start) = *(z+end);
    *(z+end) = ch;

    revstr(z, ++start, --end);
}

int main()
{
    char str[100];

 printf("Enter The String: ");
    gets(str);

    revstr(str, 0, strlen(str)-1);

    printf("%s\n", str);

}
