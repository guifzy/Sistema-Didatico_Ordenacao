#include <stdio.h>

int main()
{
    int vet[] = {4, 7, 3, 2, 8, 5, 9, 6, 1, 10};
    int tam = 10;

    sort(vet, 0, tam - 1);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    
    return 0;
}
void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int vetor[], int menor, int maior)
{
    if(menor < maior)
    {
        int indexPivot = divisao(vetor, menor, maior);
        sort(vetor, menor, indexPivot - 1);
        sort(vetor, indexPivot + 1, maior);
    }
}

int divisao(int vetor[], int menor, int maior)
{
    int pivot = vetor[maior];
    int i = menor;

    for (int j = menor; j < maior; j++)
    {
        if (vetor[j] <= pivot)
        {
            troca(&vetor[i], &vetor[j]);
            i++;
        }
        
    }
    troca(&vetor[i], &vetor[maior]);
    return i;

}