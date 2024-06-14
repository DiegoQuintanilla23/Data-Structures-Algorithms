#include <stdio.h>
#include <time.h>
#define N 5

int main()
{
    int ar[N];

    generar(ar);
    imprimir(ar);
    seleccion(ar);
    printf("\n\n\n");
    imprimir(ar);
}
void seleccion(int A[N])
{
    int c,p,tmp,t;

    for(p=1;p<N;p++)
    {
      t=0;
      for(c=0;c<N-p+1;c++)
        {
            if(A[c]>A[t])
            {
                t=c;
            }
        }
        tmp=A[t];
        A[t]=A[N-p];
        A[N-p]=tmp;
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
