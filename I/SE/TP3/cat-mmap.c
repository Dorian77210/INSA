#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    struct stat stats;
    int fd, filesize;
    char *content;

    for(int i=1; i<argc ; i++)
    {
        fd = open (argv[i], O_RDONLY, 0466);
        if (fd == -1)
        {
            fprintf (stderr, "Error during the opening of the file %s\n", argv[i]);
            continue;
        }

        if (fstat(fd, &stats) == -1)
        {
            fprintf (stderr, "Error when retrieving stats for the file %s\n", argv[i]);
            close (fd);
            continue;
        }

        filesize = stats.st_size;
        content = mmap(NULL, filesize, PROT_WRITE, MAP_PRIVATE | MAP_FILE, fd, 0);
        if (content == MAP_FAILED)
        {
            fprintf (stderr, "Error when mmap\n");
            continue;
        }

        write (1, content, filesize);
        close (fd);
        munmap (content, filesize);
    }    

    return 0;
}
