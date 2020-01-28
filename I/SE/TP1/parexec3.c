#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage : %s <command> <n> <arg1> ... <argN>", *argv);
        exit(1);
    }

    unsigned max_instances = (unsigned)strtoul(argv[2], NULL, 0);
    unsigned i, current_instances = 0;
    char *command = argv[1];
    int status;

    for (i = 3; i < argc; ++i)
    {
        if (current_instances < max_instances)
        {
            current_instances++;
            if (!fork())
            {
                execl(command, command, argv[i], NULL);
            }
        } else
        {
            wait(&status);
            if (WTERMSIG(status))
            {
                // the child was stopped due of signal
                printf("A signal has stopped a child, wait for others childs...\n");
                while (wait(NULL) != -1);
                return 1;
            }
            current_instances--;
            if (!fork())
            {
                execl(command, command, argv[i], NULL);
            }
            current_instances++;
        }
    }

    // wait the last childs
    while (wait(&status) != -1)
    {
        if (WTERMSIG(status))
        {
            // the child was stopped due of signal
            printf("A signal has stopped a child, wait for others childs...\n");
            while (wait(NULL) != -1);
            return 1;
        }
    }

    return 0;
}
