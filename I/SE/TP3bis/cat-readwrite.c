#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fd;
    char buffer;

    for(int i=1; i<argc ; i++)
    {
        fd = open(argv[i], O_RDONLY, 0466);
        if (fd == -1)
        {
            perror("open");
            continue;
        }

        while (read(fd, &buffer, sizeof(char)) != 0)
        {
            write(1, &buffer, sizeof(char));
        }

        close(fd);
    }    

    return 0;
}
