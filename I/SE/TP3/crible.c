#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

void afficher(char* crible, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (crible[i])
        {
            printf("%d, ", i);
        }
    }

    putchar('\n');
}

void rayer_multiples(char* crible, int n, int k)
{
    for (int i = k * 2; i < n; i = i + k)
    {
        crible[i] = 0;
    }
}


int main(int argc, char **argv)
{
    int n=1000;
    if(argc>1)
    {
        n = atoi(argv[1]);
        assert( n > 0 );
    }

    assert(n <= 1000);

    char *crible = mmap(NULL, n, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, 0x0, 0x0);
    if (crible == MAP_FAILED)
    {
        fprintf (stderr, "Error during mmap\n");
        exit(1);
    }    

    for(int i=0; i<n; i++)
    {
        crible[i] = 1;//par défaut: pas encore barré
    }
    
    for(int k=2; k<n; k++)
    {
        if (fork() == 0)
        {
            rayer_multiples(crible, n, k);
            exit(0);
        }
    }

    while (wait(NULL) != -1);

    afficher(crible, n);
    munmap(crible, n);

    return 0;
}
