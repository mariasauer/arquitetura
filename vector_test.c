#include <stdio.h>
#include <stdlib.h>

void insere(int* vec, int* size, int value){
    
    for (int i = 0; i < *size; i++){
        if (vec[i] == value)
            return;
    }
    printf("%d\n", *size);
    *size = *size + 1;
    printf("%d\n", *size);

    if (!(vec = (int*) realloc(vec, *size))){
        perror("Error realloc");
        exit(0);
    }

    vec[*size - 1] = value;
}


void remover(int* vec, int* size, int value){
    int to_remove = -1;

    for (int i = 0; i < *size; i++){
        if (vec[i] == value)
            to_remove = i;
    }

    if (to_remove == -1)
        return;

    for (int i = *size - 1; i > to_remove; i--){
        vec[i - 1] = vec[i];
    }

    printf("%d\n", *size);
    *size = *size - 1;
    printf("%d\n", *size);

    if (!(vec = (int*) realloc(vec, *size))){
        perror("Error realloc");
        exit(1);
    }
}

int main(){
    int* vec;
    char mode;
    int value;
    int size = 10;
    int iteração = 0;
    
    if (!(vec = (int*) malloc(sizeof(int)*10)))
        return 1;

    while(scanf("%c %d", &mode, &value)){
        printf("%d\n", iteração);
        switch (mode){
        case 'i':
            insere(vec, &size, value);            
            break;
        case 'r':
            remover(vec, &size, value);
            break;
        default:
            break;
        }
        iteração++;
    }
    free(vec);

    return 0;
}