#include <stdio.h>
#include <time.h>
#define N 100

int main()
{
    int ar[N],i,f;
    i=0;
    f=N-1;
    srand(time(0));
    
	generar(ar);
    imprimir(ar);
    
	quicksort(ar,i,f);
    
	printf("\n\n\n");
    imprimir(ar);
}
void quicksort(int A[N],int i,int f)
{
    int izq=i,der=f,pos=i,aux,band=1;
    while(band==1)
    {
        band=0;
        while(A[pos]<=A[der]&&pos!=der)
        {
            der--;
        }
        if (pos!=der)
        {
            aux=A[pos];
            A[pos]=A[der];
            A[der]=aux;
            pos=der;
        }
        while(A[pos]>=A[izq]&&pos!=izq)
        {
            izq++;
        }
        if (pos!=izq)
        {
            band=1;
            aux=A[pos];
            A[pos]=A[izq];
            A[izq]=aux;
            pos=izq;
        }
    }
    if((pos-1)>i)
    {
        quicksort(A,i,pos-1);
    }
    if(f>(pos+1))
    {
        quicksort(A,pos+1,f);
    }
}
void imprimir(int A[N])
{
    int x;
    for(x=0;x<N;x++)
    {
        printf("%d\t",A[x]);
    }
}
void generar(int A[N])
{
    int c;
    for(c=0;c<N;c++)
    {
        A[c]=rand()%50;
    }
}

