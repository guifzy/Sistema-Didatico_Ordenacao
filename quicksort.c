#include <stdio.h>

void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int vetor[], int menor, int maior)
{
    // Encontra o índice do elemento pivô, arr[pivô]
    if(menor < maior)
    {
        // Envia os parâmetros para a função divisão, começando assim o método
        int indexPivot = divisao(vetor, menor, maior);
        // A função retorna o índice final do pivô

        // Ordena os elementos antes e depois do pivô
        sort(vetor, menor, indexPivot - 1);
        sort(vetor, indexPivot + 1, maior);
    }
}

int divisao(int vetor[], int menor, int maior)
{
    int pivot = vetor[maior];// Escolha o elemento mais à direita como pivô
    int i = menor;// Índice do menor elemento

    // Percorre os elementos da lista a partir do menor elemento
    for (int j = menor; j < maior; j++)
    {
        // Se o elemento atual for menor ou igual ao pivô
        if (vetor[j] <= pivot)
        {
            troca(&vetor[i], &vetor[j]);
            // Após a troca dos valores, a variavel 'i' é incrementada em 1
            //para assim, percorrer todos índicies da lista menores que o povô
            i++;
        }
        
    }
    // Troca o elemento final de 'i'(vetor[i]) com o último elemento da lista(vetor[maior])
    troca(&vetor[i], &vetor[maior]);
    // Com isso, é possível retornar o índice final do pivô
    return i;

}

int main()    //                             i   
{             //{4, 7, 3, 2, 8, 5, 9, 6, 1, 10};
              //                         j   max
              //             i
              //{4, 3, 2, 5, 6, 7, 9, 8                       
              //                   j  max
              //          i                           
              //{4, 3, 2, 5
              //       j  max
              //                  i
              //               7, 8, 9}; 
              //                  j  max

    int vet[] = {4, 7, 3, 2, 8, 5, 9, 6, 1, 10};
    int tam = 10;

    sort(vet, 0, tam - 1);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    
    return 0;
}