#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int main(){

    srand(time(NULL));

    // declaring the variables

    int line[]   ={ 0, 1, 2, 3, 4, 5 };
    int column[] ={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int limit_line;
    int limit_column;

    // inicializing 




    printf("%d\n", line[rand() % 10]);
 /*   for (int i = 0; i < 10; i++)
    {
    limit_column = rand() % (sizeof(column) / sizeof(int));
    limit_line = rand() % (sizeof(line) / sizeof(int));
    int rLines = line[limit_line] ;
    int rColunm = column[limit_column];
    
    printf("%d %d\n", rLines, rColunm);

    }
    
*/

}