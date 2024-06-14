#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int clave;
    char marca[15];
    char modelo[15];
    int disco;
    int ram;
    float costo;
    int existencia;
}Tpc;

void Venta(int n);
void Compra(int n);
void Baja(int n);
void Alta(Tpc d);
void imprimir();
void print(Tpc f);
int menu();
Tpc Capturapc();
void check();

int main()
{
    int op,e,c,v;
    Tpc d;
    do
    {
        op=menu();
        switch(op)
        {
        case 1:
            d=Capturapc();
            Alta(d);
            break;
        case 2:
            check();
            printf("\nClave de la PC que desea borrar:\n");
            printf("0) Cancelar\n");
            scanf("%d",&c);
            if(c!=0)
            {
               Baja(c);
               break;
            }else{break;}
        case 3:
            e=0;
            check();
            printf("\n1) Venta\n2) Compra\n");
            while(e<1||e>2)
            {
                scanf("%d",&e);
            }
            printf("\nClave de la PC:\n");
            scanf("%d",&v);
            if(e==1)
            {
                Venta(v);
            }
            if(e==2)
            {
                Compra(v);
            }
            break;
        case 4:
            check();
            imprimir();
            break;
        }
    }while(op!=5);
}
void Venta(int n)
{
    FILE *pc;
    Tpc x;
    int v,u,m;
    printf("\nCantidad:\n");
    scanf("%d",&v);
    pc=fopen("pc.dat","rb+");

    fseek(pc,0,SEEK_END);
    m=ftell(pc)/sizeof(Tpc);
    rewind(pc);
    for(u=0;u<m;u++)
    {
        fread(&x,sizeof(Tpc),1,pc);
        if(x.clave==n)
        {
            x.existencia=(x.existencia-v);
            fseek(pc,-sizeof(Tpc),SEEK_CUR);
            fwrite(&x,sizeof(Tpc),1,pc);
        }
    }
    fclose(pc);
}
void Compra(int n)
{
    FILE *pc;
    Tpc x;
    int c,u,m;
    printf("\nCantidad:\n");
    scanf("%d",&c);
    pc=fopen("pc.dat","rb+");

    fseek(pc,0,SEEK_END);
    m=ftell(pc)/sizeof(Tpc);
    rewind(pc);
    for(u=0;u<m;u++)
    {
        fread(&x,sizeof(Tpc),1,pc);
        if(x.clave==n)
        {
            x.existencia=(x.existencia+c);
            fseek(pc,-sizeof(Tpc),SEEK_CUR);
            fwrite(&x,sizeof(Tpc),1,pc);
        }
    }
    fclose(pc);
}
void Baja(int n)
{
    FILE *pc;
    Tpc x;
    int u,p;
    pc=fopen("pc.dat","rb+");

    fseek(pc,0,SEEK_END);
    p=ftell(pc)/sizeof(Tpc);
    rewind(pc);
    for(u=0;u<p;u++)
    {
        fread(&x,sizeof(Tpc),1,pc);
        if(x.clave==n)
        {
            x.clave=-1;
            fseek(pc,-sizeof(Tpc),SEEK_CUR);
            fwrite(&x,sizeof(Tpc),1,pc);
        }
    }
    fclose(pc);
}
void Alta(Tpc d)
{
    FILE *pc;
    pc=fopen("pc.dat","ab+");
    fwrite(&d,sizeof(Tpc),1,pc);
    fclose(pc);
}
void imprimir()
{
    Tpc x;
    FILE *p;
    int n,u;
    p=fopen("pc.dat","rb");

    fseek(p,0,SEEK_END);
    n=ftell(p)/sizeof(Tpc);
    rewind(p);
    for(u=0;u<n;u++)
    {
        fread(&x,sizeof(Tpc),1,p);
        if(x.clave!=-1)
        {
            print(x);
        }
    }
    fclose(p);
}
void print(Tpc f)
{
    printf("\n");
    printf("\nClave: %d",f.clave);
    printf("\nMarca: %s",f.marca);
    printf("\nModelo: %s",f.modelo);
    printf("\nCapacidad en Disco Duro (GB): %d",f.disco);
    printf("\nCapacidad en Memoria RAM (GB): %d",f.ram);
    printf("\nCosto: %f",f.costo);
    printf("\nExistencia: %d",f.existencia);
    printf("\n");
}
int menu()
{
    int op;
    printf("\n--- Elige una opcion ---\n");
    printf("1) Alta de Computadora\n");
    printf("2) Baja de Computadora\n");
    printf("3) Compra o Venta\n");
    printf("4) Impresion\n");
    printf("5) Salir\n");
    scanf("%d",&op);
    return (op);
}
Tpc Capturapc()
{
    Tpc p;
    printf("\nClave: ");
    scanf("%d",&p.clave);
    printf("\nMarca: ");
    fflush(stdin);
    gets(p.marca);
    printf("\nModelo: ");
    fflush(stdin);
    gets(p.modelo);
    printf("\nCapacidad en Disco Duro (GB): ");
    scanf("%d",&p.disco);
    printf("\nCapacidad en Memoria RAM (GB): ");
    scanf("%d",&p.ram);
    printf("\nCosto: ");
    scanf("%f",&p.costo);
    printf("\nExistencia: ");
    scanf("%d",&p.existencia);
    return(p);
}
void check()
{
    FILE *pc;
    pc=fopen("pc.dat","rb");
    if(pc==NULL)
    {
        printf("\n\tERROR\nArchivo no encontrado\n");
        exit(0);
    }
    fclose(pc);
}
