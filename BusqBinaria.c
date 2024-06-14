#include <stdio.h>
#include <time.h>
#define N 6

int main()
{
    int ar[N],p1,p2,d;

    generar(ar);
    imprimir(ar);
    printf("\n\n\n");
    burbuja(ar);
    imprimir(ar);
	
    printf("\n\n\nDato a buscar: ");
    scanf("%d",&d);
	
    p1=busqbinaria(ar,d);
    p2=busqbinariarecu(ar,d,0,N-1);
    printf("\n pos= %d %d",p1,p2);
}
int busqbinaria(int A[N],int d)
{
    int mitad;
    int primero=0, ultimo=N-1;
    while(primero<=ultimo)
    {
        mitad=(primero+ultimo)/2;
        if(A[mitad]==d)
        {
            return(mitad);
        }
        if(d<A[mitad])
        {
            ultimo=mitad-1;
        }else{primero=mitad+1;}
    }
    return(-1);
}
int busqbinariarecu(int A[N],int d,int primero, int ultimo)
{
    int mitad;
    mitad=(primero+ultimo)/2;
    if(A[mitad]==d)
    {
        return(mitad);
    }
    if(d<A[mitad]&&primero<=mitad-1)
    {
        return(busqbinariarecu(A,d,primero,mitad-1));
    }
    if(d>A[mitad]&&ultimo>=mitad+1)
    {
        return(busqbinariarecu(A,d,mitad+1,ultimo));
    }
    return(-1);
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

