#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char** argv)
{
    if (fork() == 0)
    {
        // children
        execl("./rebours", "./rebours", "10", NULL);
    }    

    // parent
    execl("./rebours", "./rebours", "5", NULL);

    return 0;
}
