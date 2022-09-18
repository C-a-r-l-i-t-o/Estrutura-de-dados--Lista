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
        printf("1-Inserir no inicio \n2-Imprimir \n3-Inserir no finalzn \n5-Sair \n");
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

            case 5:
               printf("Final! \n");
               break;      
            default: 
                printf(" Ops, argumento invalido!\n");

        } 
    }while (opcao != 5 ); 
    
    


    return 0;
}
