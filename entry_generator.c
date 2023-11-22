#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int opt = 0;
    int quantidade = 1;
    int minimo = 0;
    int maximo = 10;

	while ((opt = getopt(argc, argv, "q:a:z:")) != -1) {
		switch (opt) {
		case 'q':
			quantidade = atoi(optarg);
			break;
		case 'a':
			minimo = atoi(optarg);
			break;
		case 'z':
			maximo = atoi(optarg);
			break;
		default:
            break;
		}
	}

    FILE* file;
    char mode[2] = {'i','r'}; //insere, remove, busca
    file = fopen("entry.txt","w");
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++)
        fprintf(file, "%c %d\n",mode[((rand() % 10) == 0)? 1: 0], (rand() % maximo) + minimo + 1);

    fclose(file);

    return 0;
}