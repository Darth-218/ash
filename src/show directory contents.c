#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include "getCF.c"

// show dir1 dir2

void print(DIR *d);

int main(int argc, char **argv)
{
    DIR *d;

    if (argc == 1)
    {
        getCurrentDirectory();
        d = opendir(".");
        print(d);
    }

    for (int arg = 1; arg < argc; arg++)
    {
        d = opendir(argv[arg]);
        print(d);
    }
}

void print(DIR *d)
{
    struct dirent *dir;

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

    else
    {
        perror("Error opening directory");
    }
}