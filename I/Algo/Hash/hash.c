#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* mettez ici vos déclarations de fonctions et types */
typedef char * Key;
typedef enum { EMPTY, FILLED, DELETED } CellStatus;
typedef struct {
    CellStatus status;
    Key key;
    char* value;
} Cell;

typedef struct {
    int size;
    Cell* cells;    
} HashTable;

unsigned int HashFunction(Key key, unsigned int size);

HashTable* init(int size) {
    int i;

    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    hash_table->size = size;
    hash_table->cells = (Cell*)malloc(hash_table->size * sizeof(Cell));

    for(i = 0; i < size; i++) {
        hash_table->cells[i].status = EMPTY;
        hash_table->cells[i].key = hash_table->cells[i].value = NULL;
    }

    return hash_table;
}

void insert(HashTable* table, Key key, char* value) {
    unsigned int encoded_key, current_index;

    encoded_key = HashFunction(key, table->size);
    current_index = encoded_key;

    if(table->cells[current_index].status == EMPTY ||
       table->cells[current_index].status == DELETED
    ) {
        table->cells[current_index].status = FILLED;
        table->cells[current_index].value = value;
        table->cells[current_index].key = key;
    } else { // DELETED status
        if(strcmp(key, table->cells[current_index].key) == 0) {
            // replace the cell
            free(table->cells[current_index].value);
            free(table->cells[current_index].key);
            table->cells[current_index].value = value;
            table->cells[current_index].key = key;
            return;
        }
        // else
        while(1) {
            current_index = (current_index + 1) % table->size;
            if(table->cells[current_index].status == EMPTY || 
               table->cells[current_index].status == DELETED
            ) {
                table->cells[current_index].key = key;
                table->cells[current_index].status = FILLED;
                table->cells[current_index].value = value;
                break;
            }

            if(current_index == encoded_key) break; // value not inserted
        }
    }
}   

void delete(HashTable* table, Key key) {
    int current_index, encoded_index;

    encoded_index = HashFunction(key, table->size);

    current_index = encoded_index;

    while(1) {
        if(strcmp(key, table->cells[current_index].key) == 0) {
            // same keys
            table->cells[current_index].status = DELETED;
            free(table->cells[current_index].key);
            free(table->cells[current_index].value);
            break;
        }

        current_index = (current_index + 1) % table->size;

        if(current_index == encoded_index) break;
    }
}

void query(HashTable* table, Key key) {
    unsigned int current_index, encoded_index;

    encoded_index = HashFunction(key, table->size);
    current_index = encoded_index;

    while(1) {  
        if(table->cells[current_index].status == FILLED
        && strcmp(table->cells[current_index].key, key) == 0
        ) {
            printf("%s\r\n", table->cells[current_index].value);
            return;
        }

        current_index = (current_index + 1) % table->size;
        if(current_index == encoded_index) break;
    }

    printf("Not found\r\n");
}

void stats(HashTable* table) {
    int size = table->size, filled_cells, deleted_cells, empty_cells, i;
    filled_cells = deleted_cells = empty_cells = 0;
    Cell current_cell;

    printf("size    : %d\r\n", size);

    for(i = 0; i < table->size; i++) {
        current_cell = table->cells[i];
        switch(current_cell.status) {
            case DELETED:
                deleted_cells++;
            break;
            case EMPTY:
                empty_cells++;
            break;
            case FILLED:
                filled_cells++;
            break;

            default: break;
        }
    }

    printf("empty   : %d\r\n", empty_cells);
    printf("deleted : %d\r\n", deleted_cells);
    printf("used    : %d\r\n", filled_cells);
}

void destroy(HashTable* table) {
    int i;
    for(i = 0; i < table->size; i++) {
        if(table->cells[i].status == FILLED
        ) {
            free(table->cells[i].value);
            free(table->cells[i].key);
        }
    }

    free(table->cells);
    free(table);
}

void error(void);

int main(void) 
{
   int size;
   char lecture[100];
   char * key;
   char * val;
   HashTable* table;

   if (fscanf(stdin,"%99s",lecture)!=1)
      error();
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"init")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         size = atoi(lecture);
         table = init(size);
      }
      else if (strcmp(lecture,"insert")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         val = strdup(lecture);
         insert(table, key, val);
      }
      else if (strcmp(lecture,"delete")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
        //  key = strdup(lecture);
         delete(table, lecture);
      }
      else if (strcmp(lecture,"query")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1) 
            error();
        key = strdup(lecture);
        query(table, key);
      }
      else if (strcmp(lecture,"destroy")==0)
      {
          destroy(table);
      }
      else if (strcmp(lecture,"stats")==0)
      {
          stats(table);
      }

      if (fscanf(stdin,"%99s",lecture)!=1)
         error();
   }
   return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n%(sizeof(unsigned int)*8);
  return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
   unsigned int i;
   unsigned int val = 0;
   unsigned int power = 0;
   for (i=0;i<strlen(key);i++)
   {
     val += shift_rotate(key[i],power*7);
     power++;
   }
   return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
   return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
   return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
   printf("input error\r\n");
   exit(0);
}

