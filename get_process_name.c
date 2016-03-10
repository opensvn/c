#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

void get_process_name_by_pid(int pid, char *name)
{
    char buf[256] = {0};
    char path[256] = {0};

    sprintf(buf, "/proc/%d/exe", pid);
    readlink(buf, path, sizeof(path));

    char *filename = basename(path);
    strcpy(name, filename);

    printf("%s\n", dirname("world"));
}

int main()
{
    int pid = getpid();
    char name[256] = {0};
    get_process_name_by_pid(pid, name);
    printf("%s\n", name);
    return 0;
}