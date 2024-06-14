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
    Tcoche pila[N];
    int tope;
    int tam;
}TPila;

int ver();
void imprimir(Tcoche d);
Tcoche capturadatos();
int capturatam();
int menu();
void inicializaPila(TPila *p, int tam);
int pilaVacia(TPila p);
int pilaLlena(TPila p);
int push(TPila *p, Tcoche d);
int pop(TPila *p, Tcoche *d);

int main()
{
    TPila p;
    Tcoche d;
    int op, tam=-1, pu=-1, po,V;
    do
    {
    op=menu();
    switch(op)
    {
        case 1: if(tam<0)
                {
                    tam=capturatam();
                    inicializaPila(&p,tam);
                    break;
                }else if(tam>0)
                {
                    V=ver();
                    if(V==1)
                    {
                        tam=capturatam();
                        inicializaPila(&p,tam);
                        break;
                    }else{break;}
                }
        case 2: if(tam==-1)
                {
                    printf("\nNo se ha inicializado la Pila\n");
                    break;
                }
                d=capturadatos();
                pu=push(&p,d);
                if (pu==0)
                {
                    printf("\nNo se pudo insertar el dato a la Pila\n");
                }else{printf("\nDato Insertado correctamente\n");}
                break;
        case 3: if(pu==-1)
                {
                    printf("\nNo se puede eliminar nada\n");
                    break;
                }
                po=pop(&p,&d);
                if (po==0)
                {
                    printf("\nNo se pudo eliminar mas datos de la Pila\n");
                    break;
                }else{printf("\nDato eliminado correctamente\n");}
                imprimir(d);
                break;
    }
    }while(op!=4);
}
int ver()
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
        printf("Tamaño de la Nueva Pila (>0 y <=100): ");
        scanf("%d",&n);
    }
    return (n);
}
int menu()
{
    int op;
    printf("\n--- Elige una opcion ---\n");
    printf("1) Inicializar Pila\n");
    printf("2) Insertar datos\n");
    printf("3) Quitar dato\n");
    printf("4) Salir\n");
    scanf("%d",&op);
    return (op);
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
    int reg=1;//vacia
    if(p.tope>0)
    {
        reg=0;//no esta vacia
    }
    return(reg);
}
int pilaLlena(TPila p) // si esta llena 1, si no 0
{
    int reg=1; //llena
    if(p.tope<p.tam)
    {
        reg = 0;// no llena
    }
    return(reg);
}
int push(TPila *p, Tcoche d)
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
int pop(TPila *p, Tcoche *d)// si lo elimina 1, sino 0
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
