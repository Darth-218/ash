#include <stdio.h>
#include <unistd.h>

void getCurrentDirectory()
{
    char cwd[100];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current working directory: %s\n", cwd);

    else
        perror("getcwd() error");
}
