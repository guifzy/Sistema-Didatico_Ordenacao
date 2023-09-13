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

void quickSort(int vetor[], int menor, int maior, int condicao, int passos)
{
    // Encontra o índice do elemento pivô, arr[pivô]
    if (menor < maior)
    {
        // Envia os parâmetros para a função divisão, começando assim o método
        int indexPivo = divisao(vetor, menor, maior);
        // A função retorna o índice final do pivô

        if (condicao == 2)//condição para pular o passo a passo comentado
        {
            goto resultado;
        }
        
        switch (passos)//switch case para determinar quais passos serão visualizados 
        {
        case 1:
            printf("Pivo selecionado a partir do elemento mais a direita da lista: \n");
            printf("Pivo: %d\n", vetor[indexPivo]);
            system("pause");
            printf("\n");
            break;
        case 2:
            printf("Troca: %d no indice: %d <-> %d no indice: %d\n", vetor[indexPivo], indexPivo,  vetor[maior], maior);
            system("pause");
            printf("\n");
            break;
        case 3:
            printf("Divisao do vetor: [");
            for (int i = menor; i <= maior; i++)
            {
                printf("%d", vetor[i]);
                if (i != maior)
                printf(", ");
            }
            printf("]\n\n");
            system("pause");
            printf("\n");
            break;
        case 4:
            printf("Pivo selecionado a partir do elemento mais a direita da lista: \n");
            printf("Pivo: %d\n", vetor[indexPivo]);
            printf("Troca: %d no indice: %d <-> %d no indice: %d\n", vetor[indexPivo], indexPivo,  vetor[maior], maior);      
            printf("Divisao do vetor: [");
            for (int i = menor; i <= maior; i++)
            {
                printf("%d", vetor[i]);
                if (i != maior)
                printf(", ");
            }
            printf("]\n\n");
            system("pause");
            printf("\n");
            break;
        default:
            break;
        }
        

    resultado:
        // Ordena os elementos antes e depois do pivô
        quickSort(vetor, menor, indexPivo - 1, condicao, passos);
        quickSort(vetor, indexPivo + 1, maior, condicao, passos);     
    }
    
}

void imprimirVetor(int vetor[], int tamanho)
{
    printf("[");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", vetor[i]);
        if (i != tamanho - 1)
            printf(", ");
    }
    printf("]\n");
}

void heapify(int vetor[], int tamanho, int i, int passos)
{
    // obtém filho esquerdo e direito do nó no índice `i`
    int left = 2 * i + 1;
    int right = 2* i + 2;
    // compara `A[i]` com seu filho esquerdo e direito
    // e encontre o maior valor

    if (passos == 1 || passos == 2)
    {
        printf("\nRaiz: %d", vetor[0]);
        printf("\nElemento atual: %d", vetor[i]);
        if (left < tamanho)
            printf("\nFilho da esquerda: %d", vetor[left]);
        if (right < tamanho)
            printf("\nFilho da direita: %d", vetor[right]);
        printf("\n");
        system("pause");
        
    }

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
        if (passos == 1)
        {
            printf("\nTroca: %d no indice: %d <-> Filho maior: %d no indice: %d", vetor[i], i,  vetor[largest], largest);
            printf("\nRepeticao do processo com o %d como elemento atual.", vetor[i]);
            printf("\n");
            system("pause");
        }
        
        troca(&vetor[i], &vetor[largest]);
        heapify(vetor, tamanho, largest, passos); 
    }
}

void heapSort(int vetor[], int tamanho, int passos) {
    // Constrói o heap (reorganiza o array)
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i, passos);
    }
    if (passos == 1 || passos == 2)
    {
        printf("\nHeap construido(array reorganizado): ");
        imprimirVetor(vetor, tamanho);
        system("pause");
        printf("\n");
    }
    

    // Extrai elementos do heap um por um
    for (int i = tamanho - 1; i > 0; i--) {

        if (passos == 1)
        {
            printf("\nOrdenacao do heap organizado: ");
            printf("\nTroca raiz: %d no indice %d <-> Ultimo elemento: %d no indice: %d",vetor[0], 0,vetor[i], i);
        }
        // Move a raiz atual para o final do array
        troca(&vetor[0], &vetor[i]);
        if (passos == 1)
        {
            printf("\nPasso %d: ", tamanho - i);
            imprimirVetor(vetor, tamanho);
            printf("\nReconstrucao do heap: ");
        }
        
        // Chama a função heapify na subárvore reduzida
        heapify(vetor, i, 0, passos);
        
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
    clock_t inicio, fim;// Variaveis para contar os giros do clock e assim determinar o tempo para ordenação
    double tempo_gasto;
    int opcao, tam;
    int *ponteiroTam = &tam;
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
                    int condicaoVet;
                    printf("\nDeseja criar um vetor diferente?\n");
                    printf("\n|------------------|");
                    printf("\n|    1- sim        |");
                    printf("\n|    2- nao        |");
                    printf("\n|------------------|\n");
                    scanf("%d", &condicaoVet);
                    if (condicaoVet == 1)
                    {
                        printf("\nInsira o tamanho do vetor a ser criado: ");
                        scanf("%d", ponteiroTam);
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

            case 2:// Ordenação quicksort
                if (count == 0)
                {
                    printf("\nNenhum vetor registrado\n");
                }else
                {     
                    int condicao, passos;
    
                    printf("\nSelecione qual das opcoes deseja visualizar: ");
                    printf("\n|---------------------------|");
                    printf("\n|  1-Ordenacao comentada    |");
                    printf("\n|  2-resultado da ordenacao |");
                    printf("\n|---------------------------|\n");
                    scanf("%d", &condicao);
                    if (condicao == 1)
                    {
                        
                        printf("\nQual passo deseja visualizar: ");
                        printf("\n|---------------------------|");
                        printf("\n|  1-Pivos selecionados     |");
                        printf("\n|  2-Trocas realizadas      |");
                        printf("\n|  3-Divisoes do vetor      |");
                        printf("\n|  4-Todos os passos        |");
                        printf("\n|---------------------------|\n");
                        scanf("%d", &passos);

                        inicio = clock(); //giros do clock no começo
                        quickSort(vet, 0, tam - 1, condicao, passos);

                        fim = clock();//giros do clock no fim
                        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                        printf("\n|------------------|");
                        printf("\n| Vetor ordenado:  |");
                        printf("\n|------------------|\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);
                        } 
                        printf("\nTempo gasto para o uso do metodo: %.5lf segundos", tempo_gasto);  
                        printf("\n");
                        system("pause");
                    }else
                    {
                        inicio = clock(); //giros do clock no começo
                        quickSort(vet, 0, tam - 1, condicao, passos);

                        fim = clock();//giros do clock no fim
                        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                        printf("\n|------------------|");
                        printf("\n| Vetor ordenado:  |");
                        printf("\n|------------------|\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);
                        }   
                        printf("\nTempo gasto para o uso do metodo: %.5lf segundos", tempo_gasto);
                        printf("\n");
                        system("pause");
                    }                       
                }
                break;

            case 3:// ordenacao heapsort
                if (count == 0)
                {
                    printf("\nNenhum vetor registrado\n");
                }else
                {     
                    int condicao, passos;
    
                    printf("\nSelecione qual das opcoes deseja visualizar: ");
                    printf("\n|---------------------------|");
                    printf("\n|  1-Ordenacao comentada    |");
                    printf("\n|  2-resultado da ordenacao |");
                    printf("\n|---------------------------|\n");
                    scanf("%d", &condicao);
                    if (condicao == 1)
                    {
                        
                        printf("\nQual passo deseja visualizar: ");
                        printf("\n|---------------------------------------|");
                        printf("\n|  1-Construcao e reconstrucao do heap  |");
                        printf("\n|  2-Somente os elementos selecionados  |");
                        printf("\n|---------------------------------------|\n");
                        scanf("%d", &passos);

                        inicio = clock(); //giros do clock no começo
                        heapSort(vet, tam, passos);

                        fim = clock();//giros do clock no fim
                        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                        printf("\n|------------------|");
                        printf("\n| Vetor ordenado:  |");
                        printf("\n|------------------|\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);
                        }
                        printf("\nTempo gasto para o uso do metodo: %.5lf segundos", tempo_gasto);
                        printf("\n");
                        system("pause"); 
                        break;

                    }else
                    {
                        int condicao = 0; //reinicia as variáveis para exibir somente a ordenação
                        int passos = 0;

                        inicio = clock(); //giros do clock no começo
                        heapSort(vet, tam, passos);

                        fim = clock();//giros do clock no fim
                        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                        printf("\n|------------------|");
                        printf("\n| Vetor ordenado:  |");
                        printf("\n|------------------|\n");
                        for (int i = 0; i < tam; i++)
                        {
                            printf("%d ", vet[i]);
                        }
                        printf("\nTempo gasto para o uso do metodo: %.5lf segundos", tempo_gasto);
                        printf("\n");
                        system("pause");                      
                    }
                }
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