#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage : %s <command> <n> <arg1> ... <argN>", *argv);
        exit(1);
    }

    unsigned max_instances = (unsigned)strtoul(argv[2], NULL, 0);
    pid_t *current_procs = (pid_t*)malloc(max_instances * sizeof(pid_t));
    unsigned i, current_instances = 0;
    char *command = argv[1];
    int status;
    pid_t pid;

    for (i = 3; i < argc; ++i)
    {
        if (current_instances < max_instances)
        {
            pid = fork();
            if (pid == 0)
            {
                execl(command, command, argv[i], NULL);
            }

            current_procs[current_instances++] = pid;
        } else
        {
            wait(&status);
            if (WTERMSIG(status))
            {
                // the child was stopped due of signal
                printf("A signal has stopped a child, kill other childs\n");
                for (int j = 0; j < current_instances; j++)
                {
                    kill(current_procs[j], SIGTERM);
                }

                free(current_procs);
                return 1;
            }
            current_instances--;
            pid = fork();
            if (pid == 0)
            {
                execl(command, command, argv[i], NULL);
            }

            current_procs[current_instances++] = pid;
        }
    }

    // wait the last childs
    while (wait(&status) != -1)
    {
        printf("A signal has stopped a child, kill other childs\n");
        for (int j = 0; j < current_instances; j++)
        {
            kill(current_procs[j], SIGTERM);
        }
    }

    free(current_procs);

    return 0;
}
