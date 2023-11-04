#include <stdlib.h>
#include <stdio.h>

int posição(){

    int pos[2] = {4, 8};
    return *pos;
}

int main(){

    int pos = posição();

    printf("%d \n", pos);

    return 0;

}