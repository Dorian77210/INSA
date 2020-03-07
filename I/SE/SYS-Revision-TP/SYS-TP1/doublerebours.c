#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage : %s <n1> <n2>\n", *argv);
        exit(1);
    }

    if (fork() == 0)
    {
        execl("./rebours", "./rebours", argv[1], NULL);
    }

    execl("./rebours", "./rebours", argv[2], NULL);


    return 0;
}
