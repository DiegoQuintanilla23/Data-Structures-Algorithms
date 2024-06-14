#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
    
}Tdatos;

typedef struct
{
    Tdatos pila[N];
    int tope;
    int tam;
}TPila;

int main()
{
    //se necesita definir tamaño y pasarselo a inicializa pila
}

int capturatam()
{
    int n=0;
    while (n<=0)
    {
        printf("Tamaño de la Nueva Pila (>0 y <=100): ");
        scanf("%d",&n);
    }
    return (n);
}
void inicializaPila(TPila *p, int tam)
{
    //p->tam = tam <= N? tam : N;
    if(tam<=N)
    {
        p->tam=tam;
    }else{p->tam=N;}

    p->tope = 0;
}
int pilaVacia(TPila p) //Si esta vacia 1, si no 0//
{
    int reg=1;
    if(p.tope>0)
    {
        reg=0;
    }
    return(reg);
}
int pilaLlena(TPila p) // si esta llena 1, si no 0
{
    int reg=1;
    if(p.tope<p.tam)
    {
        reg = 0;
    }
    return(reg);
}
int push(TPila *p, Tdatos d)//si lo inserta 1, sino 0
{
    int reg=0;
    if(pilaLlena(*p)==0) //(!pilaLlena(*p))/// si lo pudo insertar
    {
        p->pila[p->tope]=d;
        p->tope++;
        reg=1;
    }
    return(reg);
}
int pop(TPila *p, Tdatos *d)// si lo elimina 1, sino 0
{
    int reg=0;
    if(!pilaVacia(*p))
    {
        p->tope--;
        *d=p->pila[p->tope];
        reg=1;
    }
    return(reg);
}
