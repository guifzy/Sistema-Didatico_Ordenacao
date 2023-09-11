#include <stdio.h>
 
// armazena o tamanho do heap
int end;
 
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// retorna o filho esquerdo de A[i]
int LEFT(int i) {
    return (2*i + 1);
}
 
// retorna o filho direito de A[i]
int RIGHT(int i) {
    return (2*i + 2);
}

/* 
   Algoritmo de heapify-down recursivo:
   Verifica o maior termo entre o nó pai
   e o nó filho, a partir disso ele faz a troca
   até ele ser organizado completamente.
*/
void heapify(int A[], int i)
{
    //obs: o indicie 'i' representa o índice do nó pai
    // obtém filho esquerdo e direito do nó no índice `i`
    int left = LEFT(i);
    int right = RIGHT(i);
 
    // compara `A[i]` com seu filho esquerdo e direito
    // e encontre o maior valor
    int largest = i;
 
    if (left < end && A[left] > A[i]) {
        largest = left;
    }
 
    if (right < end && A[right] > A[largest]) {
        largest = right;
    }
 
    // troca com um filho de maior valor e
    // chama heapify no filho
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, largest); /*
                               quando realizado a troca, é usada a recursividade para verificar
                               se existe algum nó filho maior que o novo nó pai.
                             */
    }
}
// Reorganiza os elementos do array para construir o heap
void BuildHeap(int A[])
{
    // chama o heapify a partir do último nó interno de todos os
    // caminho até o nó raiz
    int i = (end - 2) / 2;// calculo para determinar o ultimo nó pai
    while (i >= 0) { // determina todos os nós pais até o nó raiz
        heapify(A, i--); // verifica se cada nó está ordenado corretamente
    }
}
void heapsort(int A[], int n)
{
    // inicializa o tamanho do heap como o número total de elementos no array
    end = n;
 
    // reorganiza os elementos do array para construir o max-heap
    BuildHeap(A);
 
    /* O loop a seguir considera a lista como ordenada em heap, ou seja
    o elemto raiz(A[0]) equivale ao maior valor da lista, dito isso, 
    iremos trocar o valor raiz pelo valor do último elemento da lista(último nó filho).
    Assim que a troca for feita iremos decrementar o tamanho da lista e realizar
    novamanete o 'heapify' tendo agora, a raiz do heap como o antigo último elemento da lista
    realizando esse processo sussetivamente até sobrarem apenas um elemento no heap */
 
    // faz até restar apenas um elemento no heap
    while (end != 1)
    {
        // move o próximo maior elemento para o final do
        // array (move-o na frente dos elementos ordenados)
        swap(&A[0], &A[end - 1]);
 
        // diminui o tamanho do heap em 1
        end--;
 
        // chama heapify no novo nó raiz 
        heapify(A, 0);
    }
}

int main(void)
{
    int A[] = { 6, 4, 7, 1, 9, -2 };
    int n = sizeof(A) / sizeof(A[0]);
 
    // executa heapsort no array
    heapsort(A, n);
 
    // imprime o array ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
 
    return 0;
}