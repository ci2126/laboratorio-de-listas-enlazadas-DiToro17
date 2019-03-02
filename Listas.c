#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int val;
    struct nodo *sig;
} Nodo;

typedef Nodo * Lista;

Lista newList(){
return NULL;
}
///Inserta en la cabeza de la Lista
void inserta(int x, Lista *L){
Nodo *p = malloc(sizeof(Nodo));
p->val = x;
p->sig = *L;
*L = p;
}

int esVacia(Lista L){
return L==NULL;
}
// pre: L es no vacía
int firstInList(Lista L){
return L->val;
}
///Booleano: 1 si x está, 0 si NO
int estaEn(int x, Lista L){
Nodo *p = L;
while(p != NULL && p->val != x) p = p->sig;
return p != NULL;
}
///Escribe la lista L de nombre name entre dos corchetes
void writeList(Lista L, char name[]){
printf("\n%s = [",name);
if (L == NULL) printf("].");
else {
while (L->sig != NULL) {
printf("%d, ", L->val);
L = L->sig;
}
printf("%d].",L->val);
}
}

/// Ejercicio 5)
///Inserta a x al final de la Lista L---apend
void insertaT(int x, Lista *L){
Nodo *p = malloc(sizeof(Nodo)), *q = *L;
p->val = x;
p->sig = NULL;
if (*L == NULL){
(*L)->val=x;
(*L)->sig=NULL;
}
else {
(*L)->sig=x;
(*L)->sig->sig=NULL;
}
}

///Elimina la primera ocurrencia de x de la lista L
void elimina(int x, Lista *L){
Nodo *p = *L, *q;
if (p != NULL){
if (p->val == x){
*L= p->sig;
free (p);
} else {
while (p->sig != NULL && (p->sig)->val != x) p = p->sig; //BUSQUEDA lINEAL
if (p->sig != NULL) {
q= p->sig;
p->sig=q->sig;
free (q);
}
}
}
}

///Produce en *N una copia de L
void clona(Lista L, Lista *N){
*N = NULL;
Nodo *q;
if (L != NULL){
*N = malloc(sizeof(Nodo));
(*N)->val=L->val;
q=*N;
L=L->sig;
while(L != NULL){
q->sig = malloc(sizeof(Nodo));
q=q->sig;
q->val=L->val;
L=L->sig;
}
q->sig = NULL;
}
}

///Concatena las listas L y K. L= L:K, K = NULL
void concat(Lista *L, Lista *K){
if (*L == NULL) *L = *K;
else {
Nodo *p = *L;
while(p->sig!= NULL){
p=p->sig;
p->sig=*K;
}
}
*K = NULL;
}


/// Ejercicio 6

int sizeR(Lista L){
if(L == NULL) return 0;
else return 1+ sizeR(L->sig);
}
///Recursiva...
int estaEnR(int x, Lista L){
if(L == NULL) return 0;
else if (L->val == x) return 1;
return estaEnR(x, L->sig);
}
///Inserta a x al final de la Lista L---apend
void insertaTR(int x, Lista *L){
if(*L == NULL) {
Nodo *p = malloc(sizeof(Nodo));
p->val = x;
p->sig = NULL;
*L = p;
}
else insertaTR(x, &((*L)->sig));
}
///Elimina la primera ocurrencia de x en la Lista *L
void eliminaR(int x, Lista *L){
if (*L != NULL){
if ((*L)->val == x) {
Nodo *p = *L;
*L = (*L)->sig;
free(p);
}
else eliminaR(x, &((*L)->sig));
} /// else skip
}

// Ejercicio de MERGE
Lista merge(Lista L,Lista M){
Nodo *p=malloc(sizeof(Nodo));
Lista n= p;

    while(L&&M){
      if (L->val < M->val){
        p->val=L->val;
        L = L->sig;
      } else {
        p->val=M->val;
        M=M->sig;
        p->sig=malloc(sizeof(Nodo));
        p=p->sig;
      }

        if (!L) L=M;
        while(L){
          p->val=L->val;
          L=L->sig;
          p->sig=malloc(sizeof(Nodo));
          p=p->sig;
        }
      p->sig=NULL;
      return n;
    }


}


///programa de prueba
int main(){
printf("\nProbando Lista...:");
Lista L = newList(), L1 = newList();
writeList(L, "L");
inserta(4,&L);
inserta(9,&L);
inserta(5,&L);
writeList(L, "L");
printf("\nA la cabeza de L esta: %d",firstInList(L));
if (esVacia(L1)) printf("\nL1 es vacia."); else printf("\nL1 NO es vacia.");
int x = 7; char s[] = "L";
if (estaEn(x, L)) printf("\n%d esta en %s.", x, s); else printf("\n%d NO esta en %s.", x, s);
return 0;
}
