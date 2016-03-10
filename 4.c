#include <stdio.h>

void reverse_printf(char *s)
{
    if (*s == 0)
        return;
    reverse_printf(s + 1);
    putchar(*s);
}

int main()
{
    char *s = "Emacs amazing!";

    printf("%s\n", s);
    reverse_printf(s);
    printf("\n");

    return 0;
}
