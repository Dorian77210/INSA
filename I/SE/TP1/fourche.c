#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>children

int main(int argc, char** argv)
{
    pid_t parent, children;

    parent = getpid();
    printf("%d: hello world\n", parent);
    printf("%d: je suis le parent\n", parent);

    children = fork();
    if (children == 0)
    {
        // children
        printf("%d: je suis l'enfant\n", getpid());
    } else if (children < 0)
    {
        fprintf(stderr, "Error during forking\n");
        exit(1);
    }

    return 0;
}
