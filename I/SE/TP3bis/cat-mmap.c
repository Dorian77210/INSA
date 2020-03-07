#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    struct stat stats;
    int fd;
    char *buffer;

    for(int i=1; i<argc ; i++)
    {
        fd = open(argv[i], O_RDONLY, 0466);
        if (fd == -1)
        {
            perror("open");
            continue;
        }

        if (fstat(fd, &stats) == -1)
        {
            perror("fstat");
            close(fd);
            continue;
        }

        buffer = mmap(NULL, stats.st_size, PROT_WRITE, MAP_PRIVATE | MAP_FILE, fd, 0);
        if (buffer == MAP_FAILED)
        {
            fprintf(stderr, "Error during mmap\n");
            close(fd);
            exit(1);
        }

        write(1, buffer, stats.st_size);

        munmap(buffer, stats.st_size);
        close(fd);
    }    

    return 0;
}
