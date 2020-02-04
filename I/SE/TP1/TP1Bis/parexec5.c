#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

#define PROGRAM_TIME 5

void handler(int sig)
{
    kill(0, SIGTERM);
}

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
    pid_t pid;

    signal(SIGALRM, handler);
    alarm(PROGRAM_TIME);

    for (i = 3; i < argc; ++i)
    {
        if (current_instances < max_instances)
        {
            pid = fork();
            if (pid == 0)
            {
                execl(command, command, argv[i], NULL);
            }

            current_instances++;
        } else
        {
            wait(&status);
            if (WTERMSIG(status))
            {
                // the child was stopped due of signal
                printf("A signal has stopped a child, kill other childs\n");
                for (int j = 0; j < current_instances; j++)
                {
                    kill(0, SIGTERM);
                }
            }
            current_instances--;
            pid = fork();
            if (pid == 0)
            {
                execl(command, command, argv[i], NULL);
            }

            current_instances++;
        }
    }

    // wait the last childs
    while (wait(&status) != -1)
    {
        printf("A signal has stopped a child, kill other childs\n");
        for (int j = 0; j < current_instances; j++)
        {
            kill(0, SIGTERM);
        }
    }

    return 0;
}
