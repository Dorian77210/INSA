#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s <n> \n", *argv);
        return 1;
    }

    unsigned count = (unsigned int)strtoul(argv[1], NULL, 0);
    pid_t pid = getpid();

    printf("%d: debut\n", pid);
    for(unsigned i = count; i > 0; i--)
    {
        printf("%d: %u\n", pid, i);
        sleep(1U);
    }

    printf("%d: fin\n", pid);

    return 0;
}
