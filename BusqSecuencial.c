#include <stdio.h>
#include <time.h>
#define N 5

int main()
{
    int ar[N],dato,pos1,pos2,pos3;
    generar(ar);
    imprimir(ar);
    printf("\n\n\n");
    burbuja(ar);
    imprimir(ar);
	
    printf("\n\n\nDato a buscar: ");
    scanf("%d",&dato);
	
    pos1=buscasecuencialdesord(ar,dato);
    pos2=buscasecuencialord(ar,dato); // solo sive ya ordenado
    pos3=bussecrecu(ar,dato,0);
    printf("\n pos= %d %d %d",pos1,pos2,pos3);//te regresan las posciciones donde esta
}
int buscasecuencialdesord(int A[N],int d)
{
    int c;
    for(c=0;c<N;c++)
    {
        if(A[c]==d)
        {
            return(c);
        }
    }
    return(-1);
}
int buscasecuencialord(int A[N],int d)
{
    int c;
    for(c=0;c<N&&A[c]<=d;c++)
    {
        if(A[c]==d)
        {
            return(c);
        }
    }
    return(-1);
}
int bussecrecu(int A[N],int d,int c) // recursiva
{
    if(c==N)
    {
        return(-1);//no recursivo
    }
    if(A[c]==d)
    {
        return(c); //no recursivo
    }
    return(bussecrecu(A,d,c+1)); //recursivo
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
void burbuja(int A[N])
{
    int c,p,tmp;
    for(p=1;p<N;p++) //inicia en 1 para que no compare con un valor basura
    {
      for(c=0;c<N-p;c++) //Se le resta la pasada para que no se pase
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

