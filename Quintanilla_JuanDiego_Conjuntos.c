#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

 typedef struct
 {
    char titulo[50];
    char autor[50];
    int anio;
    int ncanciones;
 }TDisco;
 typedef struct
 {
     TDisco Conjunto[N];
     int tam;
     int pos;
 }Tconjunto;

int capturatam();
void InicializarConjunto(Tconjunto *c, int tam);
TDisco capturadisco();
int InsertarConjunto(Tconjunto *c, TDisco d);
void pasadisco(TDisco *d1,TDisco d2);
int comparadisco(TDisco d1,TDisco d2);
int EliminarConjunto (Tconjunto *c,TDisco d);
int ConjuntoLleno(Tconjunto c);
int menu();
void imprimirconjunto(Tconjunto c);
void Diferencia (Tconjunto A, Tconjunto B, Tconjunto *C);
void Interseccion(Tconjunto A, Tconjunto B, Tconjunto *C);
int Union(Tconjunto A,Tconjunto B, Tconjunto *C);

int main()
{
	Tconjunto A,B,C;
	TDisco d;
	int v1=0,crv=0;
	int op,tam,in,el,un,x,c;
	do
    {
        op=menu();
        switch(op)
        {
        case 1: if(v1==1)
                {
                    printf("\nLos conjuntos seran reiniciados, continuar? \n1)Si\n0)No\n");
                    scanf("%d",&v1);
                    if(v1==0)
                    {
                        break;
                    }
                    if(v1==1)
                    {
                        tam=capturatam();
                        InicializarConjunto(&B,tam);
                        InicializarConjunto(&A,tam);
                        break;
                    }else{
                    printf("\n\t\tNo valido\n\n");
                    break;}
                }
                tam=capturatam();
                InicializarConjunto(&B,tam);
                InicializarConjunto(&A,tam);
                v1=1;
                break;
        case 2: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                printf("Conjunto A o B\n1) A\n2) B\n");
                scanf("%d",&c);
                if(c==1)
                {
                    d=capturadisco();
                    in=InsertarConjunto(&A,d);
                    if(in==1)
                    {printf("\n\t\tDisco insertado correctamente\n");}
                    if(in==0)
                    {printf("\n\t\tDisco No insertado/conjunto Lleno\n");}
                    if(in==-1)
                    {printf("\n\t\tDisco No insertado/Disco repetido\n");}
                    break;
                }else if(c==2)
                {
                    d=capturadisco();
                    in=InsertarConjunto(&B,d);
                    if(in==1)
                    {printf("\n\t\tDisco insertado correctamente\n");}
                    if(in==0)
                    {printf("\n\t\tDisco No insertado/conjunto Lleno\n");}
                    if(in==-1)
                    {printf("\n\t\tDisco No insertado/Disco repetido\n");}
                    break;
                }else{
                printf("\n\n\t\tOpcion no valida\n\n");
                break;}
        case 3: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                printf("Conjunto A o B\n1) A\n2) B\n");
                scanf("%d",&c);
                if(c==1)
                {
                    d=capturadisco();
                    el=EliminarConjunto(&A,d);
                    if(el==1)
                    {printf("\n\t\tDisco Eliminado correctamente\n");}
                    if(el==0)
                    {printf("\n\t\tEl Disco no existe\n");}
                    break;
                }else if(c==2)
                {
                    d=capturadisco();
                    el=EliminarConjunto(&B,d);
                    if(el==1)
                    {printf("\n\t\tDisco Eliminado correctamente\n");}
                    if(el==0)
                    {printf("\n\t\tEl Disco no existe\n");}
                    break;
                }else{
                printf("\n\n\t\tOpcion no valida\n\n");
                break;}
        case 4: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                printf("Conjunto A o B o Conjunto Resultado (C) \n1) A\n2) B\n3) Conjunto Resultado\n4) Los 3 conjuntos\n");
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\n**************\nA: \n");
                    imprimirconjunto(A);
                    printf("\n**************\n");
                    break;
                }else if(c==2)
                {
                    printf("\n**************\nB: \n");
                    imprimirconjunto(B);
                    printf("\n**************\n");
                    break;
                }else if(c==3)
                {
                    if(crv==0)
                    {
                        printf("\n\t\tNo hay nada en el conjunto resultado\n");
                        break;
                    }
                    printf("\n**************\nResultado: \n");
                    imprimirconjunto(C);
                    printf("\n**************\n");
                    break;
                }else if(c==4)
                {
                    if(crv==0)
                    {
                        printf("\n\t\tNo hay nada en el conjunto resultado\n");
                        break;
                    }
                    printf("\n**************\nA: \n");
                    imprimirconjunto(A);
                    printf("\n**************\nB: \n");
                    imprimirconjunto(B);
                    printf("\n**************\nResultado: \n");
                    imprimirconjunto(C);
                    printf("\n**************\n");
                    break;
                }else{printf("\n\n\t\tOpcion no valida\n\n");
                break;}
        case 5: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                un=Union(A,B,&C);
                crv=1;
                if(un==1)
                {printf("\n\t\tUnion realizada correctamente\n");}
                if(un==0)
                {printf("\n\t\tUnion no realizada/no cabe en el 3er conjunto\n");}
                break;
        case 6: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                Interseccion(A,B,&C);
                crv=1;
                printf("\n\t\tInterseccion Realizada\n");
                break;
        case 7: if(v1==0)
                {
                    printf("\n\t\tNo se han Inicializado los conjuntos\n");
                    break;
                }
                printf("1)A - B\n2)B - A\n");
                scanf("%d",&x);
                if(x==1)
                {
                    Diferencia(A,B,&C);
                    crv=1;
                    printf("\n\t\tDiferencia realizada (A-B)\n");
                    break;
                }else if(x==2)
                {
                    Diferencia(B,A,&C);
                    crv=1;
                    printf("\n\t\tDiferencia realizada (B-A)\n");
                    break;
                }else{
                printf("\n\n\t\tOpcion no valida\n\n");
                break;}
        }
    }while(op!=8);
}
int capturatam()
{
    int n=0;
    while (n<=0)
    {
        printf("\nTamaño del los nuevos conjuntos (>0 y <=50): ");
        scanf("%d",&n);
    }
    return (n);
}
void InicializarConjunto(Tconjunto *c, int tam)
{
    c->tam=tam<=N?tam:N;
    c->pos=0;
}
TDisco capturadisco()
{
    TDisco d;
    printf("\nTitulo: ");
    fflush(stdin);
    gets(d.titulo);
    printf("\nAutor: ");
    fflush(stdin);
    gets(d.autor);
    printf("\nAnio: ");
    scanf("%d",&d.anio);
    printf("\nNumero de Canciones: ");
    scanf("%d",&d.ncanciones);
    return(d);
}
int InsertarConjunto(Tconjunto *c, TDisco d)
{
    int cont;
    if(ConjuntoLleno(*c)==1)
    {
        return(0);
    }
    for(cont=0;cont<c->pos&&comparadisco(c->Conjunto[cont],d)==0;cont++);
    if(cont==c->pos)
    {
        pasadisco(&c->Conjunto[c->pos],d);
        c->pos++;
        return(1);
    }
    return(-1);
}
void pasadisco(TDisco *d1,TDisco d2)
{
    strcpy(d1->titulo,d2.titulo);
    strcpy(d1->autor,d2.autor);
    d1->anio=d2.anio;
    d1->ncanciones=d2.ncanciones;
}
int comparadisco(TDisco d1,TDisco d2)
{
    if(strcmp(d1.titulo,d2.titulo)!=0)
    {
        return (0);
    }
    if(strcmp(d1.autor,d2.autor)!=0)
    {
        return (0);
    }
    if(d1.anio!=d2.anio)
    {
        return (0);
    }
    if(d1.ncanciones!=d2.ncanciones)
    {
        return (0);
    }
    return (1);
}
int EliminarConjunto (Tconjunto *c,TDisco d)
{
	int cont;
	for(cont=0;cont<c->pos&&comparadisco(c->Conjunto[cont],d)==0;cont++);
	if(cont==c->pos)
	{
		return(0);
	}
	for(;cont<c->pos-1;cont++)
	{
		pasadisco(&c->Conjunto[cont],c->Conjunto[cont+1]);
	}
	c->pos--;
	return(1);
}
int ConjuntoLleno(Tconjunto c)
{
    if(c.pos==c.tam)
    {
        return(1);
    }
    return(0);
}
int menu()
{
    int op;
    printf("\n--- Elige una opcion ---\n");
    printf("1) Inicializar Nuevos Conjuntos (A y B)\n");
    printf("2) Agregar un Disco a un Conjunto\n");
    printf("3) Eliminar un Disco de un Conjunto\n");
    printf("4) Imprimir Conjuntos\n");
    printf("5) Unir los 2 conjuntos en un 3er conjunto\n");
    printf("6) Interseccion de los 2 conjuntos en un 3er Conjunto\n");
    printf("7) Diferencia de los 2 conjuntos en un 3er Conjunto\n");
    printf("8) Salir\n");
    scanf("%d",&op);
    return (op);
}
void imprimirconjunto(Tconjunto c)
{
	int i;
	for(i=0;i<c.pos;i++)
	{
	    printf("\n%d",i+1);
		printf("\nTitulo: %s",c.Conjunto[i].titulo);
		printf("\nAutor: %s",c.Conjunto[i].autor);
		printf("\nAnio: %d",c.Conjunto[i].anio);
		printf("\nNumero de Canciones: %d\n\n",c.Conjunto[i].ncanciones);
	}
}
void Diferencia (Tconjunto A, Tconjunto B, Tconjunto *C)
{
	int i,cont;
	InicializarConjunto(&*C,A.tam);
	for(i=0;i<A.pos;i++)
	{
		for(cont=0;cont<B.pos&&comparadisco(B.Conjunto[cont],A.Conjunto[i])==0;cont++);
		if(cont==B.pos)
		{
			InsertarConjunto(&*C,A.Conjunto[i]);
		}
	}
}
void Interseccion(Tconjunto A, Tconjunto B, Tconjunto *C)
{
	int i,cont;
	InicializarConjunto(&*C,A.tam);
	for(i=0;i<A.pos;i++)
	{
		for(cont=0;cont<B.pos&&comparadisco(B.Conjunto[cont],A.Conjunto[i])==0;cont++);
		if(cont<B.pos)
		{
			InsertarConjunto(&*C,A.Conjunto[i]);
		}
	}
}
int Union(Tconjunto A,Tconjunto B, Tconjunto *C)
{
	int i;
	InicializarConjunto(&*C,A.tam+B.tam);
	for(i=0;i<A.pos;i++)
	{
		InsertarConjunto(&*C,A.Conjunto[i]);
	}
	for(i=0;i<B.pos;i++)
	{
		if (InsertarConjunto(&*C,B.Conjunto[i])==0)
		{
			return (0);
		}
	}
	return (1);
}