#include <stdio.h>
#include <unistd.h>

int main()
{
    char cwd[100];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current working directory: %s\n", cwd);

    else
        perror("getcwd() error");
    return 0;
}