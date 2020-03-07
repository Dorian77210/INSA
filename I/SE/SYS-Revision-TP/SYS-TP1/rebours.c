#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s <n> \n", *argv);
        exit(1);
    }

    int n = atoi(argv[1]);

    assert(n > 0);

    pid_t pid = getpid();

    printf("%d: debut\n", pid);

    for (int i = n; i > 0; --i)
    {
        printf("%d: %d\n", pid, i);
        sleep(1u);
    }

    printf("%d: fin\n", pid);

    return 0;
}
