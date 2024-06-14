#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
    char marca[50];
    char tipo[20];
    int modelo;
    float costo;
}Tcoche;

typedef struct
{
    Tcoche cola[N];
    int inicio;
    int fin;
    int tam;
}Tcola;

int ver();
void imprimir(Tcoche d);
Tcoche capturadatos();
int capturatam();
int menu();
void inicializacola(Tcola *c, int tam);
int colaVacia(Tcola c);
int colaLlena(Tcola c);
int enqueue(Tcola * c, Tcoche d);
int dequeue(Tcola * c, Tcoche *d);

int main()
{
    Tcola c;
    Tcoche d;
    int op, tam=-1,en=-1,de,V;
    do
    {
    op=menu();
    switch(op)
    {
        case 1: if(tam<0)
                {
                    tam=capturatam();
                    inicializacola(&c,tam);
                    break;
                }else if(tam>0)
                {
                    V=ver();
                    if(V==1)
                    {
                        tam=capturatam();
                        inicializacola(&c,tam);
                        break;
                    }else{break;}
                }
        case 2: if(tam==-1)
                {
                    printf("\nNo se ha inicializado la Cola\n");
                    break;
                }
                d=capturadatos();
                en=enqueue(&c,d);
                if (en==0)
                {
                    printf("\nNo se pudo insertar el dato a la Cola\n");
                }else{printf("\nDato Insertado correctamente\n");}
                break;
        case 3: if(en==-1)
                {
                    printf("\nNo se puede eliminar nada\n");
                    break;
                }
                de=dequeue(&c,&d);
                if (de==0)
                {
                    printf("\nNo se pudo eliminar mas datos de la Cola\n");
                    break;
                }else{printf("\nDato eliminado correctamente\n");}
                imprimir(d);
                break;
    }
    }while(op!=4);
}int ver()
{
    int vv=2;
    while(vv<0||vv>1)
    {
        printf("\nLos datos seran eliminados, desea continuar?\n 1 = Si  0 = No\n");
        scanf("%d",&vv);
    }
    return (vv);
}
void imprimir(Tcoche d)
{
    printf("\nDatos del coche eliminado:\n");
    printf("\nMarca:  %s", d.marca);
    printf("\nTipo:  %s", d.tipo);
    printf("\nModelo:  %d", d.modelo);
    printf("\nCosto:  %f\n\n", d.costo);
}
Tcoche capturadatos()
{
    Tcoche c;
    printf("\nMarca: ");
    fflush(stdin);
    gets(c.marca);
    printf("\nTipo: ");
    fflush(stdin);
    gets(c.tipo);
    printf("\nModelo: ");
    scanf("%d",&c.modelo);
    printf("\nCosto: ");
    scanf("%f",&c.costo);
    return(c);
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
int menu()
{
    int op;
    printf("\n--- Elige una opcion ---\n");
    printf("1) Inicializar Cola\n");
    printf("2) Insertar datos\n");
    printf("3) Quitar dato\n");
    printf("4) Salir\n");
    scanf("%d",&op);
    return (op);
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
int enqueue(Tcola * c, Tcoche d)
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
int dequeue(Tcola * c, Tcoche *d)
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
