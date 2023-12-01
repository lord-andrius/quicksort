#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int vetor[], int comeco, int fim)
{
    int pivo = comeco;
    if( fim == comeco || fim < comeco) return;
    for (int c = comeco; c <= fim; c++)
    {
        if (vetor[c] < vetor[pivo])
        {
            for (int i = c; i > pivo; i--)
            {
                int tmp = vetor[i - 1];
                vetor[i - 1] = vetor[i];
                vetor[i] = tmp;
            }
        }

    }
    quicksort(vetor, comeco, pivo);
    quicksort(vetor, pivo + 1, fim);
}

int main(void)
{
    srand(time(NULL));
    int x[5] = {0};
    printf("Sequência não ordenada: ");
    for (int c = 0; c < sizeof(x) / sizeof(int); c++)
    {
        x[c] = rand() % 100;
        printf("%d ", x[c]);
    }
    printf("\n");

    printf("Sequência ordenada: ");
    quicksort(x, 0, 4);
	for(int c = 0; c < sizeof(x) / sizeof(int);c++)
        printf("%d ", x[c]);
    printf("\n");
}
