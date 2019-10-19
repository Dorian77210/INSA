
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY_MAX 5000
#define NBR_STUDENT_MAX 200
#define NBR_CLASSES 2

int main(int argc, const char** argv) {
    int x, capacity, i, j, delta;
    int nbr_students, p, c;
    int cpt, isFull = 0, max_capacity_ifa3, max_capacity_ifa4, nbr_ifa3 = 0, nbr_ifa4 = 0;

    scanf("%d", &capacity);
    scanf("%d", &nbr_students);

    int ifa3[nbr_students], ifa4[nbr_students];

    capacity++;

    ifa3[0]=0;
    ifa4[0]=0;
    //Get the values (poid/classe) for students
    for(x=0;x<nbr_students;x++){
        scanf("%d %d", &p, &c);
        if(c == 3){
            ifa3[nbr_ifa3+1] = p;
            nbr_ifa3++;
        }
        else{
            ifa4[nbr_ifa4+1]= p;
            nbr_ifa4++;
        }
    }
    int matrix_ifa3[NBR_STUDENT_MAX][CAPACITY_MAX];
    int matrix_ifa4[NBR_STUDENT_MAX][CAPACITY_MAX];

    //Calcul de la matrice ifa3
    for(i = 0; i <= nbr_ifa3; i++) {
        for(j = 0; j < capacity; j++) {
            delta = i - 1;
            x = j - ifa3[i];
            if(j == 0){
                matrix_ifa3[i][j]=1;
            }
            else if(delta >= 0 && matrix_ifa3[i - 1][j]) {
                matrix_ifa3[i][j] = 1;
            }                 
            else if(delta >= 0 && x >= 0){
                if(matrix_ifa3[i-1][j-ifa3[i]]) {
                    matrix_ifa3[i][j]=1;
                }
            }
           // printf("%d;",matrix_ifa3[i][j]);
           // printf("%d ",ifa3[i]);
            
        }
        //printf("\n");
    }

    //Calcul de la matrice ifa4
    for(i = 0; i <= nbr_ifa4; i++) {
        for(j = 0; j < capacity; j++) {
            delta = i - 1;
            x = j - ifa4[i];
            if(j == 0){
                matrix_ifa4[i][j]=1;
            }
            else if(delta >= 0 && matrix_ifa4[i - 1][j]) {
                matrix_ifa4[i][j] = 1;
            }                 
            else if(delta >= 0 && x >= 0){
                if(matrix_ifa4[i-1][j-ifa4[i]]) {
                    matrix_ifa4[i][j]=1;
                }
            }
            //printf("%d;",matrix_ifa4[i][j]);
            //printf("%d ",ifa4[i]);
            
        }
        //printf("\n");
    }
    if((nbr_ifa3)>=0 && (capacity-1)>= 0 && (nbr_ifa4)>=0){
        if((matrix_ifa3[nbr_ifa3][capacity - 1] == 1)&&(matrix_ifa4[nbr_ifa4][capacity - 1] != 1) ){
            printf("3\r\n");
        } 
        else if ((matrix_ifa3[nbr_ifa3][capacity - 1] != 1)&&(matrix_ifa4[nbr_ifa4][capacity - 1] == 1)){
            printf("4\r\n");
        }
        else if ((matrix_ifa3[nbr_ifa3][capacity - 1] == 1)&&(matrix_ifa4[nbr_ifa4][capacity - 1] == 1)){
            printf("3 4\r\n");
        }
        else{
            cpt = capacity-1;
            while(isFull!=1){
                isFull = matrix_ifa3[nbr_ifa3][cpt];
                cpt--;
            }
            max_capacity_ifa3 = cpt;

            isFull = 0;
            cpt = capacity -1;

            while(isFull!=1){
            isFull = matrix_ifa4[nbr_ifa4][cpt];
            cpt--;
            }
            max_capacity_ifa4 = cpt;
            if( max_capacity_ifa3>max_capacity_ifa4){
                printf("3\r\n");
            }
            else{
                printf("4\r\n");
            }   
        }
    }
    

    return EXIT_SUCCESS;
}