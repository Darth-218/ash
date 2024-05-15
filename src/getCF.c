#include <stdio.h>
#include <unistd.h>

void getCurrentDirectory()
{
    char cwd[100];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        getcwd(cwd, sizeof(cwd));
    else
        perror("getcwd() error");
}