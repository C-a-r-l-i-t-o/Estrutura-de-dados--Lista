#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------

//implementacao do codigo 
typedef struct No{
        
    int valor;
    struct No *proximo;    

}No;

typedef struct {

    No *inicio;
    int tamanho;


}Lista;


//insercao no inicio da lista
void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof (No));
    novo-> valor = valor;
    novo-> proximo = lista-> inicio;
    lista-> inicio = novo;
    lista-> tamanho++;
}

//insercao no final da lista
void inserirFim(Lista *lista, int valor){
    No *no, *novo = (No*)malloc(sizeof(No)); 
    novo-> valor = valor;
    novo-> proximo =  NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    } else{
            no = lista-> inicio;
            while (no-> proximo != NULL)
                no = no->proximo;
            no-> proximo = novo; 
            
    }
        lista-> tamanho++;
}

//funcao para remover um item da lista
void excluiR(Lista *lista , int valor){
    No *inicio = lista -> inicio;// se for o primeiro no 
    No *noaexcluiR = NULL;
    if( inicio != NULL && lista-> inicio-> valor == valor){
        noaexcluiR = lista-> inicio;
        lista-> inicio = noaexcluiR -> proximo;
    } else{
        // se for no meio da lista o NO 
            while(inicio != NULL && inicio -> proximo != NULL && inicio -> proximo -> valor == valor){
                inicio = inicio -> proximo;// isto é para percorrer a lista caso nao seja o inicio a ser removido             
                }
            if (inicio != NULL && inicio-> proximo != NULL){
                noaexcluiR = inicio-> proximo;
                inicio-> proximo= noaexcluiR-> proximo;
            }
    } if (noaexcluiR){

        free(noaexcluiR);
        lista-> tamanho --; 
    }

}





// imprimir a lista 
void imprimir(Lista *lista){
    No *inicio = lista->inicio; //criado um ponteiro inicio, para receber o inicio da lista
    printf("Tamanho da lista: %d - \n", lista-> tamanho);
    while(inicio != NULL){// considerando que não  sabemos o inicio
        printf("%d ", inicio-> valor);
        inicio = inicio ->proximo;
    }
    printf("\n \n"); // para saltar duas linhas 
    
}

//----------------------------------------------------------------------------------------
//arquivo main

int main(){
    
    Lista lista; 
    int opcao, valor;
    lista.inicio = NULL;
    lista.tamanho = 0;
    
    do{
        printf("1-Inserir no inicio \n2-Imprimir \n3-Inserir no final \n4-Remover elemento \n5-Sair \n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
               printf("Digite um valor desejado na insercao: \n");
               scanf("%d", &valor);
               inserirInicio(&lista, valor);  
               break;
            case 2:
               imprimir(&lista); 
               break;
            case 3:
                printf("Digite um valor desejado na insercao: \n");
                scanf("%d", &valor); 
              inserirFim(&lista, valor);
              break;
            case 4:
                printf("Digite um valor desejado a ser removido: \n");
                scanf("%d", &valor); 
              excluiR(&lista, valor);
              break;    
            case 5:
               printf("Final! \n");
               break;      
            default: 
                printf(" Ops, argumento invalido!\n");

        } 
    }while (opcao != 5 ); 
    
    


    return 0;
}
