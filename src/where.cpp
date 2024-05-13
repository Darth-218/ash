#include <stdio.h>
#include <unistd.h>

int main()
{
    char inp[100];
    scanf("%s", inp);
    char cwd[100];

    if (inp[0] == 'c' && inp[1] == 'd')
    {
        if (getcwd(cwd, sizeof(cwd)) != NULL)

        {

            printf("Current working directory: %s\n", cwd);
        }

        else

        {

            perror("getcwd() error");
        }
    }
    else
    {
        printf("Invalid command\n");
    }

    return 0;
}