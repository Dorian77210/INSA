#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITERATIONS 10
#define INIT_SIZE 100

typedef struct {
    char* name;
    char tel[11];
} Personne;

void print_repository(Personne* persons) {
    int i;
    for(i = 0; i < ITERATIONS; i++) {
        printf("%s : %s \n", persons[i].name, persons[i].tel);
    }
}

int main(int argc, const char** argv) {
    Personne persons[ITERATIONS];
    Personne person;    
    int i, length;
    char buffer[INIT_SIZE];

    for(i = 0; i < ITERATIONS; i++) {
        printf("Enter your name : ");
        fflush(stdout);
        scanf("%s", &buffer);

        length = strlen(buffer);
        person.name = (char*)malloc((1 + length) * sizeof(char));
        strncpy(person.name, buffer, length);

        printf("Enter your phone : ");
        fflush(stdout);
        scanf("%s", &person.tel);

        persons[i] = person;
    }

    print_repository(persons);


    return EXIT_SUCCESS;
}