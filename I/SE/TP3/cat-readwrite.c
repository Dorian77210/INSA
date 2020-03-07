#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    int fd;
    char buffer;
    for(int i=1; i<argc ; i++)
    {
        fd = open(argv[i], O_RDONLY, 0466);
        if (fd == -1)
        {
            fprintf(stderr, "Error during the opening of the file %s\n", argv[i]);
            continue;
        }

        while (read(fd, &buffer, sizeof (char)) == 1)
        {
            write(1, &buffer, sizeof(buffer));
        }

        close (fd);
    }    

    return 0;
}
