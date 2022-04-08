#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
int valor;
struct Node* proximo;

}No;

No* inserir(No* no, int valor){
  No* novo = (No*)malloc(sizeof(No));
  novo->proximo = no;
  novo->valor = valor;

  return novo;
}

void imprimir(No* no){
  if(no->proximo == NULL)
  {
    printf("%i", no->valor);
  }
  else
  {
    printf("%i ", no->valor);
    imprimir(no->proximo);
  }
}

 void inversoImprimir(No* no){
  if(no == NULL)
  {
    return;
  }
  else
  {
    inversoImprimir(no->proximo);
    printf("%i ", no->valor);
  }
}

No* remover(No* no, int valor){
  if (no != NULL)
  {
    if (no->valor == valor)
    {
    No* notemporario = no;
    no = no->proximo;

    free(notemporario);

    return no;
    }
    else
    {
      no->proximo = remover(no->proximo, valor);
      return no;
    }
  }
  else
  {
  return NULL;  
  }
}

No* buscar(No* no, int valor){
  if (no == NULL)
  {
    return NULL;
  }
  else{
    if (no->valor == valor)
    {
      imprimir(no);
      return no;
    }
    else
    {
      no->proximo = buscar(no->proximo, valor);
      return no;
    }
  }
  
}

int main(void) {
  
  No* lista = NULL;
  printf("Inserindo 10,20 e 30: \n");
  lista = inserir(lista, 10);
  lista = inserir(lista, 20);
  lista = inserir(lista, 30);
  lista = inserir(lista, 40);
  
  imprimir(lista);

  lista = remover(lista, 20);
  
  printf("\n\nRemovendo 20 da lista: \n");
  imprimir(lista);
  
  printf("\n\nBuscando 10 dentro da lista: \n");
  lista = buscar(lista, 10);

printf("\n\nImprimindo lista do início ao fim \n");
  imprimir(lista);
  
printf("\n\nImprimindo lista do fim para o início: \n");
  inversoImprimir(lista);


  return 0;
}

