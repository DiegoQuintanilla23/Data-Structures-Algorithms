#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{

}Tdato;

typedef struct
{
    Tdato cola[N];
    int inicio;
    int fin;
    int tam;
}Tcola;

int main()
{
	//se necesita definir el tamaño
}
int capturatam()
{
    int n=0;
    while (n<=0)
    {
        printf("Tamaño de la Cola (>0 y <=100): ");
        scanf("%d",&n);
    }
    return (n);
}
void inicializacola(Tcola *c, int tam)
{
    tam++;
    c->tam = tam <= N? tam : N;
    c->inicio = 0;
    c->fin = 0;
}
int colaVacia(Tcola c)
{
    int reg;
    reg = c.inicio == c.fin? 1 : 0;
    return(reg);
}
int colaLlena(Tcola c)
{
    int reg;
    reg = (c.fin + 1) % c.tam == c.inicio? 1:0;
    return(reg);
}
int enqueue(Tcola * c, Tdato d)
{
    int reg = 0;
    if( ! colaLlena(*c))
    {
        c->cola[c->fin] = d;
        c->fin = (c->fin + 1) % c->tam;
        reg = 1;
    }
    return(reg);
}
int dequeue(Tcola * c, Tdato *d)
{
    int reg = 0;
    if( ! colaVacia(*c))
    {
        *d = c->cola[c->inicio];
        c->inicio = (c->inicio + 1) % c->tam;
        reg = 1;
    }
    return(reg);
}
