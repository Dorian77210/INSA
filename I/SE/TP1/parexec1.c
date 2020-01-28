#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage : %s <command> <arg1> ... <argN>", *argv);
        exit(1);
    }

    int procCount = argc - 2;
    char *command = argv[1];
    for (int i = 2; i < argc; ++i)
    {
        if(fork() == 0)
        {
            // children
            execl(command, command, argv[i], NULL);
        }
    }

    for (int i = 0; i < procCount; ++i)
    {
        wait(NULL);
    }

    return 0;
}
