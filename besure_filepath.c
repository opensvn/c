#include <stdio.h>
#include <string.h>
#incoude <unistd.h>

bool besure_path(const char *pathname)
{
    int len = strlen(pathname);

    char buffer[len + 1];
    memset(buffer, 0, sizeof(buffer));

    strcpy(buffer, pathname);

    for (int i = 0; i < len; ++i)
    {
        if (buffer[i] == '/')
        {
            buffer[i] = 0;

            if (access(buffer, F_OK) < 0)
            {
                if (mkdir(buffer, 0755) < 0)
                {
                    return false;
                }
            }

            buffer[i] = '/';
        }
    }

    return true;
}

void test_vla(const char *str)
{
    int len = strlen(str);

    char a[len + 1];
    memset(a, 0, sizeof(a));

    strcpy(a, str);

    printf("%s\n", a);
}

int main()
{
    test_vla("hello");
    test_vla("world!");
    test_vla("Amazing");
    return 0;
}