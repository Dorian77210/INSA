#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    pid_t parent, children;
    parent = getpid();

    printf("%d: hello world \n", parent);
    if(fork() == 0)
    {
        children = getpid();
        printf("%d: Je suis l'enfant\n", children);
    } else
    {
        printf("%d: Je suis le parent\n", parent);
    }

    return 0;
}
