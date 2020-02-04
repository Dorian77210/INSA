#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, const char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage : %s <command> <arg1> ... <argN> \n", *argv);
        return EXIT_FAILURE;
    }

    unsigned count = argc - 2;
    const char *command = argv[1];

    for(unsigned i = 2; i < argc; ++i)
    {
        if (fork() == 0)
        {
            if (execl(command, command, argv[i], NULL) == -1)
            {
                fprintf(stderr, "Error when exec the command %s\n", command);
            }
        }
    }

    // wait the end of children
    while (wait(NULL) != -1);
    printf("End of the children\n");

    return EXIT_SUCCESS;
}