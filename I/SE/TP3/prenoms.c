#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FILENAME "prenoms.dat"

typedef struct {
    int sexe; // 1=M, 2=F
    char prenom[25];
    int annee_naissance; // 1900..2018
    int nombre;
} tuple;

void print_tuple(const tuple *t)
{
    printf("Sexe : %c, name : %s, born year : %d, number : %d\n", t->sexe == 1 ? 'M' : 'F', t->prenom, t->annee_naissance, t->nombre);
}

const char *getLongestName(const tuple *t, int size)
{
    const char *longest_name = t[0].prenom;
    int longest_length = strlen(longest_name), current_length;

    for (int i = 1; i < size; ++i)
    {
        current_length = strlen(t[i].prenom);
        if (current_length > longest_length)
        {
            longest_length = current_length;
            longest_name = t[i].prenom;
        }
    }

    return longest_name;
}

const char *get_most_popular(const tuple *t, int size)
{
    int result = -1;
    int index;

    for (int i = 0; i < size; ++i)
    {
        if (t[i].nombre > result)
        {
            result = t[i].nombre;
            index = i;
        }
    }

    return t[index].prenom;
}

int get_year_by_name(const tuple* t, int size, const char *name)
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(name, t[i].prenom) == 0)
        {
            return t[i].annee_naissance;
        }
    }

    return -1;
}

void to_camel_case(tuple *t, int size)
{
    int keep_cap = 1;
    for (int i = 0; i < size; ++i)
    {
        keep_cap = 1;
        for (int j = 0; t[i].prenom[j] != '\0'; ++j)
        {
            if (!keep_cap)
            {
                keep_cap = 0;
                t[i].prenom[j] += ('a' - 'A');
            }

            keep_cap = (t[i].prenom[j] == '-');
        }
    }
}

int main(int argc, char **argv)
{
    tuple *tuples;
    struct stat stats;

    int filesize, tuples_count;
    int fd = open (FILENAME, O_RDONLY, 0466);
    
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    if (fstat(fd, &stats) == -1)
    {
        perror("fstat");
        close(fd);
        exit(1);
    }

    filesize = stats.st_size;

    tuples = (tuple*)mmap(NULL, filesize, PROT_WRITE, MAP_PRIVATE | MAP_FILE, fd, 0);
    // number of tuples
    tuples_count = filesize / sizeof(tuple);

    printf("Tuples count : %d\n", tuples_count);

    to_camel_case(tuples, tuples_count);

    for (int i = 0; i < tuples_count; ++i)
    {
        print_tuple(tuples + i);
    }

    close(fd);
    munmap(tuples, filesize);

    return 0;
}
