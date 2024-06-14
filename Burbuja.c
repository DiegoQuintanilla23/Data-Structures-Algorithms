#include <stdio.h>
#include <time.h>
#define N 50

int main()
{
    int ar[N];

    generar(ar);
    imprimir(ar);
    burbuja(ar);
    printf("\n\n\n");
    imprimir(ar);
}
void burbuja(int A[N])
{
    int c,p,tmp;
    for(p=1;p<N;p++)
    {
      for(c=0;c<N-p;c++)
        {
        if(A[c]>A[c+1])
            {
            tmp=A[c];
            A[c]=A[c+1];
            A[c+1]=tmp;
            }
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
