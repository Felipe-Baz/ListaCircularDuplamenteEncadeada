/* Programa: Lab 5
Autor: Felipe Baz Mitsuishi
Versao: 1.0 - 10/10/2019
*/
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
struct elemento
{
   int numero;
   struct elemento *prox;
   struct elemento *ant;
};
typedef struct elemento tipoElemento;
struct estruturaLCDDE
{
   tipoElemento *primeiro;
   int tamanho;
};
typedef struct estruturaLCDDE tipoListaCDDE;
void inicializaLista(tipoListaCDDE *listaAux)
{
   listaAux->primeiro = NULL;
   listaAux->tamanho = 0;
}
void insereElementoFinal(tipoListaCDDE *ListaAux, int numero)
{
   tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
   novo->numero = numero;
   if (ListaAux->tamanho == 0)
   {
      novo->prox = novo;
      novo->ant = novo;
      ListaAux->primeiro = novo;
   }
   else
   {
      novo->prox = ListaAux->primeiro;
      novo->ant = ListaAux->primeiro->ant;
      ListaAux->primeiro->ant->prox = novo;
      ListaAux->primeiro->ant = novo;
   }
   ListaAux->tamanho++;
}
void removeLista(tipoListaCDDE *listaAux, tipoElemento *Aux)
{
   if(listaAux->tamanho == 1)
   {
      listaAux->primeiro = NULL;
   }else if(listaAux->primeiro == Aux)
   {
      Aux->ant->prox = Aux->prox;
      Aux->prox->ant = Aux->ant;
      listaAux->primeiro = listaAux->primeiro->prox;
   }else
   {
      Aux->ant->prox = Aux->prox;
      Aux->prox->ant = Aux->ant;
   }
   free(Aux);
   listaAux->tamanho--;
}
void printaLista(tipoListaCDDE *listaAux)
{
   tipoElemento *Aux = listaAux->primeiro;
   int i;
   if (listaAux->tamanho == 1)
   {
      printf("%d\n", listaAux->primeiro->numero);
   }else
   {
      for (i = 0; i < listaAux->tamanho; i++)
      {
         printf("%d ", Aux->numero);
         Aux = Aux->prox;
      }
      printf("\n");
   }
}
// ###################### Funcoes e Procedimentos do programa ##############
/*Code*/
// ############################ Principal ###################################
int main()
{
   int i, NumDeKids = 0, num = 0, Paozin = 0, passadas = 0;
   tipoListaCDDE MyList;
   inicializaLista(&MyList);
   scanf("%d", &NumDeKids);
   for (i = 0; i < NumDeKids; i++)
   {
      scanf("%d", &num);
      insereElementoFinal(&MyList, num);
   }
   printaLista(&MyList);
   tipoElemento *Aux = MyList.primeiro;
   scanf("%d", &Paozin);
   for (i = 0; i < Paozin; i++)
   {
      if(Aux == MyList.primeiro->ant)
      {
         passadas++;
      }
      Aux = Aux->prox;
   }
   removeLista(&MyList, Aux);
   printf("Passadas na lista: %d\n", passadas);
   printaLista(&MyList);
   return 0;
}
