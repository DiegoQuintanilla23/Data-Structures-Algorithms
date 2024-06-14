# include <stdio.h>

#define N 20

typedef struct
{
    int Conjunto[N];
    int tam;
    int pos;
}TConjunto;

int InsertarConjunto(TConjunto *C, int d);
void ImprimeConjunto(TConjunto C);
void InicializarConjunto(TConjunto *C, int tam);
int ConjuntoLleno(TConjunto C);

int main()
{
    TConjunto C;
    int x;

    InicializarConjunto(&C,5);

    x=InsertarConjunto(&C,5);
    printf(" %d ",x);
    x=InsertarConjunto(&C,8);
    printf(" %d ",x);
    x=InsertarConjunto(&C,5);
    printf(" %d ",x);
    x=InsertarConjunto(&C,4);
    printf(" %d ",x);
    x=InsertarConjunto(&C,6);
    printf(" %d ",x);
    x=InsertarConjunto(&C,1);
    printf(" %d ",x);
    x=InsertarConjunto(&C,10);
    printf(" %d ",x);
    x=InsertarConjunto(&C,12);
    printf(" %d ",x);

    ImprimeConjunto(C);

    x=EliminarConjunto(&C,6);
    ImprimeConjunto(C);

    x=EliminarConjunto(&C,20);
    printf(" %d ",x);
    ImprimeConjunto(C);
}

void ImprimeConjunto(TConjunto C)
{
    int i;
    printf("\n");
    for (i=0;i<C.pos;i++)
    {
        printf("\n %d ",C.Conjunto[i]);
    }
}

void InicializarConjunto(TConjunto *C, int tam)
{
    C->tam= tam<=N?tam:N;

    C->pos=0;
}

/*1 -- Si Inserta
0 -- NO Inserta -- Está lleno
-1 - NO Inserta -- Está repetido - Ya existe*/
int InsertarConjunto(TConjunto *C, int d)
{
    int cont;

    if(ConjuntoLleno(*C)==1)
    {
        return(0);
    }
    for(cont=0;cont<C->pos && C->Conjunto[cont]!=d; cont++);
    if(cont==C->pos)
    {
        C->Conjunto[C->pos]=d;
        C->pos++;
        return(1);
    }
    return(-1);
}

int ConjuntoLleno(TConjunto C)
{
    if(C.pos==C.tam)
    {
        return(1);
    }
    return(0);
}

/*1 - SI Elimina el dato
0 - NO Elimina el dato, no existe*/
int EliminarConjunto(TConjunto *C, int d)
{
    int cont;

    for(cont=0;cont<C->pos && C->Conjunto[cont]!=d; cont++);
    if(cont==C->pos)
    {
        return(0);
    }

    for(;cont<C->pos-1;cont++)
    {
        C->Conjunto[cont]=C->Conjunto[cont+1];
    }
    C->pos--;
    return(1);
}


