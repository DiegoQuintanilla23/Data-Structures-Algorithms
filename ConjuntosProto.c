#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
typedef struct
{
   //Datos
}TDato;
typedef struct
{
    TDato Conjunto[N];
    int tam;
    int pos;
}TConjunto;

int main()
{

}
void InicializarConjunto(TConjunto *C, int tam)
{
    C->tam= tam<=N?tam:N;
    C->pos=0;
}
int capturatam()
{
    int n=0;
    scanf("%d",&n);
    return (n);
}
// 1 si puede insertar / 0 No inserta--ya esta lleno / -1 No insertar--dato repetido
int InsertarConjunto(TConjunto *C, TDato d)
{
    int cont;
    if(ConjuntoLleno(*C)==1)
    {
        return(0);
    }
    ///for(cont=0;cont<C->pos&&C->Conjunto[cont]!=d; cont++);
	//for(cont=0;cont<c->pos&&comparadato(c->Conjunto[cont],d)==0;cont++);//si es un dato struct
    if(cont==C->pos)
    {
        ///C->Conjunto[C->pos]=d;
		//pasadato(&c->Conjunto[c->pos],d);//si es tipo struct
        C->pos++;
        return(1);
    }
    return(-1);
}
TDato capturadato()
{
    TDato d;
    ///Se capturan todos los datos del tdato
    return(d);
}
//1 si esta lleno/ 0 si no
int ConjuntoLleno(TConjunto C)
{
    if(C.pos==C.tam)
    {
        return(1);
    }
    return(0);
}
//1 si lo elimina//0 si no elimina, no existe//
int EliminarConjunto(TConjunto *C, TDato d)
{
    int cont;
    ///for(cont=0;cont<C->pos && C->Conjunto[cont]!=d; cont++);
	//for(cont=0;cont<c->pos&&comparadato(c->Conjunto[cont],d)==0;cont++);//si es un dato struct
    if(cont==C->pos)
    {
        return(0);
    }
    for(;cont<C->pos-1;cont++)
    {
        ///C->Conjunto[cont]=C->Conjunto[cont+1];
		//pasadato(&c->Conjunto[cont],c->Conjunto[cont+1]);//si es dato struct
    }
    C->pos--;
    return(1);
}
void pasadato(Tdato *d1,Tdato d2)
{
    //strcpy(d1->titulo,d2.titulo);
    //d1->anio=d2.anio;
    ///se pasa a d1 todos los campos de d2
}
void Diferencia(TConjunto A, TConjunto B, TConjunto *C)
{
    int i,cont;
    InicializarConjunto(&*C,A.tam);
    for(i=0; i<A.pos;i++)
    {
        ///for(cont=0;cont<B.pos && B.Conjunto[cont]!=A.Conjunto[i]; cont++);
		//for(cont=0;cont<B.pos&&comparadato(B.Conjunto[cont],A.Conjunto[i])==0;cont++);//dato struct
        if(cont==B.pos)
        {
            InsertarConjunto(&*C,A.Conjunto[i]);
        }
    }
}
// 1 si son iguales/ 0 si son diferentes
int comparadato(TDato d1,TDato d2)
{
    //if(strcmp(d1.titulo,d2.titulo)!=0){return (0);}
    //return (1);
	///comparar cada campo del dato con if's(==) y regresa 0 en cada uno
}
void Interseccion(TConjunto A, TConjunto B, TConjunto *C)
{
   int i,cont;
   InicializarConjunto(&*C,A.tam);
   for(i=0; i<A.pos;i++)
    {
        ///for(cont=0;cont<B.pos&&B.Conjunto[cont]!=A.Conjunto[i];cont++);
		//for(cont=0;cont<B.pos&&comparadato(B.Conjunto[cont],A.Conjunto[i])==0;cont++);//datostruct
        if(cont<B.pos)
        {
            InsertarConjunto(&*C,A.Conjunto[i]);
        }
    }
}
//1 si realizo ls union, 0 no lo realizo, no caben
int Union(TConjunto A,TConjunto B, TConjunto *C)
{
    int i;
    InicializarConjunto(&*C,A.tam+B.tam);
    for(i=0;i<A.pos;i++)
    {
        InsertarConjunto(&*C,A.Conjunto[i]);
    }
    for(i=0;i<B.pos;i++)
    {
        if(InsertarConjunto(&*C,B.Conjunto[i])==0)
        {
            return(0);
        }
    }
    return(1);
}
void ImprimeConjunto(TConjunto C)
{
    int i;
    printf("\n");
    for (i=0;i<C.pos;i++)
    {
		printf("\n%d",i+1);// poscicion
        ///se imprimen los datos de c
		//printf("\nTitulo: %s",c.Conjunto[i].titulo);
    }
}
