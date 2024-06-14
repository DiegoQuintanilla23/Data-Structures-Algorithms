#include <stdio.h>
#include <time.h>
#define N 5

int main()
{
    int ar[N];

    generar(ar);
    imprimir(ar);
    insercion(ar);
    printf("\n\n\n");
    imprimir(ar);
}
void insercion(int A[N])
{
    int p,c,tem;
    for(p=1;p<N;p++)
    {
        for(c=p;c>0 && A[c]<A[c-1];c--)
        {
            tem=A[c];
            A[c]=A[c-1];
            A[c-1]=tem;
        }
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

