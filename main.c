#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função que realiza a troca de valores em ambos os métodos de ordenação
void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int divisao(int vetor[], int menor, int maior)
{
    int pivo = vetor[maior];// Escolha o elemento mais à direita como pivô
    int i = menor;// Índice do menor elemento

    // Percorre os elementos da lista a partir do menor elemento
    for (int j = menor; j < maior; j++)
    {
        // Se o elemento atual for menor ou igual ao pivô
        if (vetor[j] <= pivo)
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

void quickSort(int vetor[], int menor, int maior)
{
    // Encontra o índice do elemento pivô, arr[pivô]
    if (menor < maior)
    {
        // Envia os parâmetros para a função divisão, começando assim o método
        int indexPivo = divisao(vetor, menor, maior);
        // A função retorna o índice final do pivô
        printf("Pivo selecionado a partir do elemento mais a direita da lista: \n");
        printf("Pivo: %d\n", vetor[indexPivo]);
        printf("Troca: %d no indice: %d <-> %d no indice: %d\n", vetor[indexPivo], indexPivo,  vetor[maior], maior);
        system("pause");
        printf("\n");

        // Ordena os elementos antes e depois do pivô
        quickSort(vetor, menor, indexPivo - 1);
        quickSort(vetor, indexPivo + 1, maior);     
    }
    
}

void heapify(int vetor[], int tamanho, int i)
{
    // obtém filho esquerdo e direito do nó no índice `i`
    int left = 2 * i + 1;
    int right = 2* i + 2;
    // compara `A[i]` com seu filho esquerdo e direito
    // e encontre o maior valor
    int largest = i;
 
    if (left < tamanho && vetor[left] > vetor[i]) {
        largest = left;
    }
 
    if (right < tamanho && vetor[right] > vetor[largest]) {
        largest = right;
    }
 
    // troca com um filho de maior valor e
    // chama heapify no filho
    if (largest != i)
    {
        troca(&vetor[i], &vetor[largest]);
        heapify(vetor, tamanho, largest); 
    }
}

void heapSort(int vetor[], int tamanho) {
    // Constrói o heap (reorganiza o array)
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i);
    }

    // Extrai elementos do heap um por um
    for (int i = tamanho - 1; i > 0; i--) {
        // Move a raiz atual para o final do array
        troca(&vetor[0], &vetor[i]);

        // Chama a função heapify na subárvore reduzida
        heapify(vetor, i, 0);
    }
}

void criarVetor(int vetor[], int tamanho, int *count)
{
    int i, tipo;
    printf("\n|------------------------------------|");
    printf("\n|  1- Vetor crescente                |");
    printf("\n|  2- Vetor decrescente              |");
    printf("\n|  3- Vetor aleatorio                |");
    printf("\n|------------------------------------|\n");
    printf("\nInsira o numero correspondente a uma das opcoes acima: ");
    scanf("%d", &tipo);

    switch (tipo) {
        case 1: // Ordem crescente
            for (i = 0; i < tamanho; i++) {
                vetor[i] = i + 1;
            }
            break;
        case 2: // Ordem decrescente
            for (i = 0; i < tamanho; i++) {
                vetor[i] = tamanho - i;
            }
            break;
        case 3: // Aleatório
            srand(time(NULL));
            for (i = 0; i < tamanho; i++) {
                vetor[i] = rand() % 100; // Gera números aleatórios de 0 a 99
            }
            break;
    }
    *count = 1; 

}

int main()
{
    int opcao, tam;
    int count = 0;// Contador para saber se já foi gerado um array

    printf("\n|-----------------------------------------------|");
    printf("\n|  BEM VINDO AO SISTEMA DIDADICO DE ORDENACAO!  |");
    printf("\n|-----------------------------------------------|\n");

    // Armazena o valor do tamanho e cria um array com o tamnho da variavel
    printf("\nInsira o tamanho do vetor a ser criado: ");
    scanf("%d", &tam);
    int vet[tam];

    do {
        printf("\n|------------------------------------|");
        printf("\n|  1- Criar um novo array            |");
        printf("\n|  2- Ordenar por QuickSort          |");
        printf("\n|  3- Ordenar por HeapSort           |");
        printf("\n|  4- Sair do programa               |");
        printf("\n|------------------------------------|\n");
        printf("\nInsira o numero correspondente a uma das opcoes acima: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (count != 0)
                {
                    int condicao;
                    printf("\nDeseja criar um vetor diferente?\n");
                    printf("\n|------------------|");
                    printf("\n|    1- sim        |");
                    printf("\n|    2- nao        |");
                    printf("\n|------------------|\n");
                    scanf("%d", &condicao);
                    if (condicao == 1)
                    {
                        criarVetor(vet, tam, &count);
                        printf("\nVetor criado:\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);                            
                        }
                        printf("\n");
                        system("pause");
                    }
                    
                }else
                {
                    criarVetor(vet, tam, &count);
                    printf("\n|------------------|");
                    printf("\n|  Vetor criado:   |");
                    printf("\n|------------------|\n");
                    for (int i = 0; i < tam; i++)
                    {
                        printf("%d ", vet[i]);
                    }
                    printf("\n");
                    system("pause");
                }
               
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNenhum vetor registrado\n");
                }else
                {     
                    int condicao;
    
                    printf("\nSelecione qual das opcoes deseja visualizar: ");
                    printf("\n|---------------------------|");
                    printf("\n|  1-Ordenacao comentada    |");
                    printf("\n|  2-resultado da ordenacao |");
                    printf("\n|---------------------------|\n");
                    scanf("%d", &condicao);
                    if (condicao == 1)
                    {
                        quickSort(vet, 0, tam - 1);
                    }else
                    {
                        printf("\n|------------------|");
                        printf("\n| Vetor ordenado:  |");
                        printf("\n|------------------|\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);
                        }   
                        printf("\n");
                        system("pause");
                    }                       
                }
                break;

            case 3:
                heapSort(vet, tam);
                for (int i = 0; i < tam; i++)
                {
                    printf("%d ", vet[i]);
                }
                printf("\n");
                system("pause"); 
                break;

            case 4:                
                printf("\n   Programa encerrado.");
                opcao = 4;
                break;

            default:
                printf("\n|-----------------------------|");
                printf("\n|       OPCAO INVALIDA!       |");
                printf("\n|-----------------------------|");
                break;
        }
    } while (opcao != 4);


    return 0;
}