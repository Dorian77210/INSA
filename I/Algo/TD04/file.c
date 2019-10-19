#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct {
    int begin;
    int end;
    int array[MAX_SIZE];
} File;

File* init() {
    File* file = NULL;

    file = (File*)malloc(sizeof(File));
    file->begin = 0x0;
    file->end = 0x0;

    return file;
}

void free_file(File* file) {
    free(file);
}

void queue(File* file, int value) {
    file->array[file->end] = value;
    file->end = (file->end + 1) % MAX_SIZE;
}

void dequeue(File* file) {
    if(file->begin == file->end) return;

    int value = file->array[file->begin];
    file->begin = (file->begin + 1) % MAX_SIZE;

    printf("%d\r\n", value);
}

int main(void)
{
    char lecture[100];
    int val;
    File* file = init();

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "bye") != 0)
    {
        if (strcmp(lecture, "queue") == 0)
        {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            queue(file, val);
        }
        else if (strcmp(lecture, "dequeue") == 0)
        {
            dequeue(file);
        }

        fscanf(stdin, "%99s", lecture);
    }

    free_file(file);

    return 0;
}