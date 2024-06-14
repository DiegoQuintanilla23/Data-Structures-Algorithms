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
    //datos del nodo
}TNodo;
typedef struct
{
    TNodo Nodos[N];
    int Adyacencias[N][N];
    int numvertices;
}Tgrafo;



int main()
{
    Tgrafo g;
    TNodo n,n1,n2;
    int inn,ina,ela,eln;
}

TNodo capturanodo()
{
    TNodo n;
    ///printf("\nNombre: ");
    ///fflush(stdin);
    ///gets(n.nombre);

	//capturar datos del nodo
    return(n);
}
void inicializargrafo(Tgrafo *g)
{
    g->numvertices=0;
}
int insertanodo(Tgrafo *g, TNodo d)///1 si lo agrego. 0 si no
{
    int i;
    if(g->numvertices==N)
    {
        return(0);
    }
    ///g->Nodos[g->numvertices]=d;///
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
    //if(v1==-1) no existe mensaje error
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
        //g->Nodos[i]=g->Nodos[i+1];
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
void imprimegrafo(Tgrafo g)///
{
    int i,j;
    for(i=0;i<g.numvertices;i++)
    {
        //printf("\n Nombre: %s Carrera: %c Edad: %d ", g.Nodos[i].nombre, g.Nodos[i].carrera, g.Nodos[i].edad);
		///imprime los datos del nodo en [i]
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
    //printf a todos los datos del nodo m
}
void Amplitud(Tgrafo g)///
{
    int Visitados[N],v,i;
    int u=0;//se puede pedir
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
    int i,v,u=0;//se puede pedir
    int Visitados[N];
    for(i=0;i<g.numvertices;i++)
    {
        Visitados[i]=0;
    }
    Visitados[u]=1;
    imprimenodo(g.Nodos[u]);
    //para cada vertice v del grafo
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
int Comparanodos(TNodo P1,TNodo P2)///1 iguales//0 diferentes
{
	//compara datos de los 2 nodos
    ///if(P1.edad==P2.edad&&strcmp(P1.nombre,P2.nombre)==0&&P1.carrera==P2.carrera)
    {
        return(1);
    }
    return(0);
}
void copiarnodo(TNodo *P1, TNodo P2)
{
    ///P1->edad=P2.edad;
    ///strcpy(P1->nombre,P2.nombre);
	//copia lo de P2 a P1
}


//funciones de cola para enteros
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
