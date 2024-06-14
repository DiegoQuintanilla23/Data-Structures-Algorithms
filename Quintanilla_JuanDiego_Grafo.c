#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct
{
    int cola[N];
    int inicio;
    int fin;
    int tam;
}Tcola;
typedef struct
{
    char nombre[30];
    int edad;
    char carrera;
}TNodo;
typedef struct
{
    TNodo Nodos[N];
    int Adyacencias[N][N];
    int numvertices;
}Tgrafo;

int menu();
TNodo capturanodo();
void inicializargrafo(Tgrafo *g);
int insertanodo(Tgrafo *g, TNodo d);
int insertararista(Tgrafo *g, TNodo n1, TNodo n2);
int eliminararista(Tgrafo *g,TNodo n1, TNodo n2);
int eliminarnodo(Tgrafo *g, TNodo n);
void imprimegrafo(Tgrafo g);
void imprimenodo(TNodo m);
void Amplitud(Tgrafo g);
void profundidad(Tgrafo g);
void dfs(Tgrafo g, int v, int Visitados[N]);
int Comparanodos(TNodo P1,TNodo P2);
void copiarnodo(TNodo *P1, TNodo P2);
void inicializacola(Tcola *c, int tam);
int colaVacia(Tcola c);
int colaLlena(Tcola c);
int enqueue(Tcola * c, int d);
int dequeue(Tcola * c, int *d);

int main()
{
    Tgrafo g;
    TNodo n,n1,n2;
    int op;
    int inn,ina,ela,eln,v=-1;
    do
    {
        op=menu();
        switch(op)
        {
        case 1:
            if(v!=-1)
            {
                printf("El grafo sera reinicidado, continuar? \n1)Si\n0)No\n");
                scanf("%d",&v);
                if(v==0)
                {
                    break;
                }
                if(v==1)
                {
                    inicializargrafo(&g);
                    printf("\n\t\tGrafo reinicidao\n\n");
                    break;
                }else{
                printf("\n\t\tNo valido\n\n");
                break;}
            }
            inicializargrafo(&g);
            printf("\n\t\tGrafo Inicializado\n\n");
            v=0;
            break;
        case 2:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            n=capturanodo();
            inn=insertanodo(&g,n);
            printf("\n*************************\n");
            if(inn==1)
            {
                printf("\n\t\tInsertado correctamente\n");
                break;
            }else if(inn==0)
            {
                printf("\n\t\tNo se ha podido insertar\n");
                break;
            }
        case 3:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            printf("\n\t\tAlumno 1:\n");
            n1=capturanodo();
            printf("\n\t\tAlumno 2:\n");
            n2=capturanodo();
            ina=insertararista(&g,n1,n2);
            printf("\n*************************\n");
            if(ina==1)
            {
                printf("\n\t\tRelacion insertada correctamente\n");
                break;
            }else if(ina==0)
            {
                printf("\n\t\tRelacion no insertada\n");
                break;
            }
        case 4:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            printf("\n\t\tAlumno 1:\n");
            n1=capturanodo();
            printf("\n\t\tAlumno 2:\n");
            n2=capturanodo();
            ela=eliminararista(&g,n1,n2);
            printf("\n*************************\n");
            if(ela==1)
            {
                printf("\n\t\tRelacion Eliminada\n");
                break;
            }else if(ela==0)
            {
                printf("\n\t\tNo se No se pudo eliminar la relacion\n");
                break;
            }
        case 5:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            printf("\n\t\tAlumno a eliminar\n");
            n=capturanodo();
            eln=eliminarnodo(&g,n);
            printf("\n*************************\n");
            if(eln==1)
            {
                printf("\n\t\tEliminado Correctamente\n");
                break;
            }else if(eln==0)
            {
                printf("\n\t\tNo se ha eliminado\n");
                break;
            }
        case 6:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            imprimegrafo(g);
            printf("\n*************************\n");
            break;
        case 7:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            profundidad(g);
            printf("\n*************************\n");
            break;
        case 8:
            if(v==-1)
            {
                printf("\nGrafo no inicializado\n");
                break;
            }
            printf("\n*************************\n");
            Amplitud(g);
            printf("\n*************************\n");
            break;
        }
    }while(op!=9);
}
int menu()
{
    int op;
    printf("\n--- Elige una opcion ---\n");
    printf("1) Inicializar el grafo\n");
    printf("2) Nuevo Alumno\n");
    printf("3) Nueva Relacion\n");
    printf("4) Eliminar Relacion\n");
    printf("5) Eliminar Alumno\n");
    printf("6) Imprimir el grafo\n");
    printf("7) Recorrido Primero en Profundidad\n");
    printf("8) Recorrido Primero en Amplitud\n");
    printf("9) Salir\n");
    scanf("%d",&op);
    return (op);
}
TNodo capturanodo()
{
    TNodo n;
    printf("\nNombre: ");
    fflush(stdin);
    gets(n.nombre);
    printf("\nCarrera ");
    printf("( c)Computacion, i)Informatica, s)Sistemas Inteligentes ): ");
    fflush(stdin);
    scanf("%c",&n.carrera);
    printf("\nEdad: ");
    scanf("%d",&n.edad);
    return(n);
}
void inicializargrafo(Tgrafo *g)
{
    g->numvertices=0;
}
int insertanodo(Tgrafo *g, TNodo d)//1 si lo agrego. 0 si no
{
    int i;
    if(g->numvertices==N)
    {
        return(0);
    }
    copiarnodo(&g->Nodos[g->numvertices],d);
    g->numvertices++;
    for(i=0;i<=g->numvertices;i++)
    {
        g->Adyacencias[g->numvertices][i]=0;
        g->Adyacencias[i][g->numvertices]=0;
    }
    return(1);
}
int insertararista(Tgrafo *g, TNodo n1, TNodo n2)//1 si//0 no
{
    int v1=-1,v2=-1,i;
    for(i=0;i<g->numvertices;i++)
    {
        if(Comparanodos(g->Nodos[i],n1)==1)
        {
            v1=i;
        }
        if(Comparanodos(g->Nodos[i],n2)==1)
        {
            v2=i;
        }
    }
    if(v1==-1||v2==-1)
    {
        return(0);
    }
    g->Adyacencias[v1][v2]=1;
    g->Adyacencias[v2][v1]=1;
    return(1);
}
int eliminararista(Tgrafo *g,TNodo n1, TNodo n2)//1 si//0 no
{
    int i, v1=-1,v2=-1;
    for(i=0;i<g->numvertices;i++)
    {
        if(Comparanodos(g->Nodos[i],n1)==1)
        {
            v1=i;
        }
        if(Comparanodos(g->Nodos[i],n2)==1)
        {
            v2=i;
        }
    }
    if(v1!=-1&&v2!=-1)
    {
        g->Adyacencias[v1][v2]=0;
        g->Adyacencias[v2][v1]=0;
        return(1);
    }
    return(0);
}
int eliminarnodo(Tgrafo *g, TNodo n)//1 si//0 no encontrado
{
    int v=-1,i,j;
    for(i=0;i<g->numvertices;i++)
    {
        if(Comparanodos(g->Nodos[i],n)==1)
        {
            v=i;
        }
    }
    if(v==-1)
    {
        printf("\nNo encontrado\n");
        return(0);
    }
    g->numvertices--;
    for(i=v;i<g->numvertices;i++)
    {
        copiarnodo(&g->Nodos[i],g->Nodos[i+1]);
        for(j=0;j<g->numvertices;j++)
        {
            g->Adyacencias[j][i]=g->Adyacencias[j][i-1];
        }
        for(j=0;j<g->numvertices;j++)
        {
            g->Adyacencias[i][j]=g->Adyacencias[i-1][j];
        }
    }
    return(1);
}
void imprimegrafo(Tgrafo g)
{
    int i,j;
    for(i=0;i<g.numvertices;i++)
    {
        printf("\n Nombre: %s Carrera: %c Edad: %d ", g.Nodos[i].nombre, g.Nodos[i].carrera, g.Nodos[i].edad);
    }
    printf("\n");
    for(i=0;i<g.numvertices;i++)
    {
        for(j=0;j<g.numvertices;j++)
        {
            printf("%d\t",g.Adyacencias[i][j]);
        }
        printf("\n");
    }
}
void imprimenodo(TNodo m)
{
    printf("\nNombre: %s",m.nombre);
    printf("\nCarrera: %c",m.carrera);
    printf("\nEdad: %d",m.edad);
    printf("\n");
}
void Amplitud(Tgrafo g)
{
    int Visitados[N],v,i;
    int u=0;
    Tcola c;
    for(i=0;i<g.numvertices;i++)
    {
        Visitados[i]=0;
    }
    inicializacola(&c,N);
    enqueue(&c,u);
    Visitados[u]=1;
    imprimenodo(g.Nodos[u]);
    do
    {
        dequeue(&c,&u);
        for(v=0;v<g.numvertices;v++)
        {
            if(g.Adyacencias[u][v]==1&&Visitados[v]==0)
            {
                enqueue(&c,v);
                Visitados[v]=1;
                imprimenodo(g.Nodos[v]);
            }
        }
    }while(!colaVacia(c));
}
void profundidad(Tgrafo g)
{
    int i,v,u=0;
    int Visitados[N];
    for(i=0;i<g.numvertices;i++)
    {
        Visitados[i]=0;
    }
    Visitados[u]=1;
    imprimenodo(g.Nodos[u]);
    for(v=0;v<g.numvertices;v++)
    {
        if(g.Adyacencias[u][v]==1&&Visitados[v]==0)//realacion y no visitado
        {
            dfs(g,v,Visitados);
        }
    }
}
void dfs(Tgrafo g, int v, int Visitados[N])
{
    int w;
    Visitados[v]=1;
    imprimenodo(g.Nodos[v]);
    for(w=0;w<g.numvertices;w++)
    {
        if(g.Adyacencias[v][w]==1&&Visitados[w]==0)
        {
            dfs(g,w,Visitados);
        }
    }
}
int Comparanodos(TNodo P1,TNodo P2)//1 iguales//0 diferentes
{
    if(P1.edad==P2.edad&&strcmp(P1.nombre,P2.nombre)==0&&P1.carrera==P2.carrera)
    {
        return(1);
    }
    return(0);
}
void copiarnodo(TNodo *P1, TNodo P2)
{
    P1->edad=P2.edad;
    strcpy(P1->nombre,P2.nombre);
    P1->carrera=P2.carrera;
}


void inicializacola(Tcola *c, int tam)
{
    tam++;
    c->tam = tam <= N? tam : N;
    c->inicio = 0;
    c->fin = 0;
}
int colaVacia(Tcola c)//1 si//0 no
{
    int reg;
    reg = c.inicio == c.fin? 1 : 0;
    return(reg);
}
int colaLlena(Tcola c)//1 si//0 no
{
    int reg;
    reg = (c.fin + 1) % c.tam == c.inicio? 1:0;
    return(reg);
}
int enqueue(Tcola * c, int d)//1 si//0 no
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
int dequeue(Tcola * c, int *d)//1 si//0 no
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
