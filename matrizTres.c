// percorre primeiro colunas da matriz
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher uma matriz com números aleatórios
void preencherMatriz(float **matriz, int linhas, int colunas)
{

    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            matriz[i][j] = rand() % 10;
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(float **matriz, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            printf("%0.0f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para alocar memória para uma matriz
float **alocarMatriz(int linhas, int colunas)
{
    float **matriz = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
    }
    return matriz;
}

// Função para somar duas matrizes
void somarMatrizes(float **matriz1, float **matriz2, float **resultado, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Função para calcular a matriz transposta
void calcularTransposta(float **matriz, float **transposta, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            transposta[j][i] = matriz[i][j];
        }
    }
}

// Função para liberar memória de uma matriz
void liberarMatriz(float **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para calcular a matriz inversa (para matrizes 3x3)
int calcularMatrizInversa(float **matriz, float **inversa, int linhas)
{
    // Implementação simplificada usando eliminação de Gauss-Jordan
    // Esta implementação assume que a matriz é invertível

    // Copia a matriz original para a matriz inversa
    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            inversa[i][j] = matriz[i][j];
        }
    }

    // Inicializa a matriz de identidade

    float **identidade = alocarMatriz(linhas, linhas);

    // Inicializando a matriz identidade
    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            if (i == j)
            {
                identidade[i][j] = 1;
            }
            else
            {
                identidade[i][j] = 0;
            }
        }
    }

    // Aplica a eliminação de Gauss-Jordan
    for (int k = 0; k < linhas; k++)
    {
        float pivo = inversa[k][k];

        // Divide a linha pelo pivô
        for (int j = 0; j < linhas; j++)
        {
            inversa[k][j] /= pivo;
            identidade[k][j] /= pivo;
        }

        // Reduz outras linhas
        for (int i = 0; i < linhas; i++)
        {
            if (i != k)
            {
                float fator = inversa[i][k];
                for (int j = 0; j < linhas; j++)
                {
                    inversa[i][j] -= fator * inversa[k][j];
                    identidade[i][j] -= fator * identidade[k][j];
                }
            }
        }
    }

    // A matriz identidade agora contém a inversa
    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {

            inversa[i][j] = identidade[i][j];
        }
    }

    liberarMatriz(identidade, linhas);

    return 1; // Sucesso
}

// Função para multiplicar duas matrizes
void multiplicarMatrizes(float **matriz1, float **matriz2, float **resultado, int linhas1, int colunas1)
{
    int colunas2 = colunas1;
    for (int j = 0; j < colunas2; j++)
    {
        for (int i = 0; i < linhas1; i++)
        {

            resultado[i][j] = 0.0;
            for (int k = 0; k < colunas1; k++)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main()
{
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Define o tamanho das matrizes
    int linhas = 2048;
    int colunas = 2048;

    float **matriz1 = alocarMatriz(linhas, colunas);
    float **matriz2 = alocarMatriz(linhas, colunas);

    // Preenche as matrizes com números aleatórios
    preencherMatriz(matriz1, linhas, colunas);
    preencherMatriz(matriz2, linhas, colunas);

    // Imprime as matrizes
    printf("Matriz 1:\n");
    imprimirMatriz(matriz1, linhas, colunas);

    printf("\nMatriz 2:\n");
    imprimirMatriz(matriz2, linhas, colunas);

    float **resultado = alocarMatriz(linhas, colunas);
    // Cria uma matriz para armazenar a soma

    // Chama a função para somar as matrizes
    somarMatrizes(matriz1, matriz2, resultado, linhas, colunas);
    printf("\nMatriz resultado soma:\n");
    imprimirMatriz(resultado, linhas, colunas);

    // Cria uma matriz para armazenar a transposta
    float **transposta = alocarMatriz(linhas, colunas);

    // Chama a função para calcular a matriz transposta
    calcularTransposta(matriz1, transposta, linhas, colunas);
    printf("\nMatriz resultado transposta:\n");
    imprimirMatriz(transposta, linhas, colunas);
    liberarMatriz(transposta, linhas);

    // Cria uma matriz para armazenar a inversa
    float **inversa = alocarMatriz(linhas, colunas);

    // Chama a função para calcular a matriz inversa
    if (calcularMatrizInversa(matriz1, inversa, linhas))
    {
        // Imprime a matriz inversa
        printf("\nMatriz Inversa:\n");
        imprimirMatriz(inversa, linhas, colunas);
    }
    else
    {
        printf("\nA matriz não é invertível.\n");
    }

    // Chama a função para multiplicar as matrizes
    multiplicarMatrizes(matriz1, matriz2, resultado, linhas, colunas);

    // Imprime o resultado
    printf("\nResultado da Multiplicação:\n");
    imprimirMatriz(resultado, linhas, colunas);

    // Libera a memória alocada para as matrizes
    liberarMatriz(matriz1, linhas);
    liberarMatriz(matriz2, linhas);
    liberarMatriz(resultado, linhas);

    return 0;
}
