#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 100

int main()
{
///declarar variable tipo file
    FILE *ptr;

///abrir archivo y asociar a la variable de tipo file
    ptr=fopen("ruta \\ Nombre archivo y extension", "tipo archivo"); //necesita carpeta creada, doble slash
    if(ptr==NULL)
    {
        printf("Error: archivo no encontrado");
        exit(0);
    }

///TEXTO ESCRIBIR
    int x=65;
    float y=3.1459;
    char c='g';
    char cad[20];
    fprintf(ptr,"%d %f",x,y);//guardar en un archivotexto .txt
    fputc('A',ptr);//guardar caracter .txt
    fputc(c,ptr);//guardar caracter .txt
    fputs("nigg",ptr);//guardar string .txt
    fputs(cad,ptr);//guardar string .txt

///TEXTO LEER
    int x;
    float y;
    char c;
    fscanf(ptr,"%d%f %c",&x,&y,&c);//escibe lo del archivo en las variables .txt
    printf("los datos son: %d %f %c",x,y,c);// los imprime .txt

///BINARIOS ESCRIBIR
    int x=65;
    float y=3.1459;
    char c='g';
    fwrite(&x,sizeof(int),1,ptr);//escribir en un .bin
    fwrite(&y,sizeof(float),1,ptr);//escribir en un .bin
    fwrite(&c,sizeof(char),1,ptr);//escribir en un .bin

///BINARIOS LEER
    int x;
    float y;
    char c;
    fread(&x,sizeof(int),1,ptr);//leer en un .bin
    fread(&y,sizeof(float),1,ptr);// leer en un .bin //los escribe en las variables
    fread(&c,sizeof(char),1,ptr);// leer en un .bin
    printf("Datos: %d %f %c\n",x,y,c);

///GLOBAL
    printf("pos=%d\n"ftell(ptr));//indicador de posicion
    feof(ptr);//fin de archivo//1 FIN  0 NO FIN
    fclose(ptr);//cerrar archivo

///CICLOS IMPRIMIR TEXTO//read
        //normal
    int x;
    float y;
    char c;
    fscanf(ptr,"%d%f %c",&x,&y,&c);
    while(feof(ptr)==0)//fin de archivo //1 cuando es fin, 0 cuando no
    {
        fscanf(ptr,"%d%f %c",&x,&y,&c);
        printf("los datos son: %d %f %c",x,y,c);
    }

        //imprime en forma de puros char
    char c;
    c=fgetc(ptr);
    while(feof(ptr)==0)
    {
        printf("%c",c);
        c=fgetc(ptr);
    }

        //imprime todo en forma de puras string
    char cad[20];
    //fgets(cad,15,ptr);//lee espacios, hasta el num 15-1 o salto de linea //no lee el ultimo
    fscanf(ptr,"%s",cad);
    while(feof(ptr)==0)
    {
        printf("\n%s",cad);
        fscanf(ptr,"%s",cad);
        //fgets(cad,15,ptr); //no lee el ultimo
    }

///CICLO IMPRIMIR BINARIO//read
    int x;
    float y;
    char c;
    fread(&x,sizeof(int),1,ptr);
    while(!feof(ptr))
    {
        fread(&y,sizeof(float),1,ptr);
        fread(&c,sizeof(char),1,ptr);
        printf("Datos: %d %f %c\n",x,y,c);
        fread(&x,sizeof(int),1,ptr);
    }

///EJEMPLO DE PASO DE PARAMETRO EN CADENAS
    divide("numeros.txt");
        void divide(char arc[])
        FILE *i;
        i=fopen(arc,"r");

///OTROS EJEMPLOS
    ptr=fopen("Alumnos.bin","rb+");
    //ab se escibe al final, rb+ se sobreescribe al inicio

}
void EjemploSepararEnteros()
{
    ///separa un archivo binario en 2 de texto
    FILE *i;
    FILE *a;
    FILE *b;
    int u,x,n;

    i=fopen("numeros.dat","rb");
    a=fopen("pares.txt","a");
    b=fopen("impares.txt","a");

    fseek(i,0,SEEK_END);//mueve al final en indicador
    n=ftell(i)/sizeof(int);//indicador de posicion dividido entre los bytes
    fseek(i,0,SEEK_SET);//lo regresa al inicio
    //rewind(i);
    for(u=0;u<n;u++)
    {
        fread(&x,sizeof(int),1,i);
        if(x%2==0)
        {
            fprintf(a,"%d ",x);
        }
        if(x%2!=0)
        {
            fprintf(b,"%d ",x);
        }
    }
    fclose(i);
    fclose(a);
    fclose(b);
}
void EjemploSepararEnBin()
{
    ///separa de un archivo de texto en 2 binarios, y los imprime
    FILE *i;
    FILE *a;
    FILE *b;
    i=fopen(arc,"r");
    a=fopen("pares.dat","wb");
    b=fopen("impares.dat","wb");
    int x,n,u;
    fseek(i,0,SEEK_END);
    n=ftell(i)/sizeof(int);
    fseek(i,0,SEEK_SET);
    for(u=0;u<n;u++)
    {
        fscanf(i,"%d",&x);
        if(x%2==0)
        {
            fwrite(&x,sizeof(int),1,a);
        }
        if(x%2!=0)
        {
            fwrite(&x,sizeof(int),1,b);
        }
    }
    fclose(i);
    fclose(a);
    fclose(b);
///imprimir
    int x;
    FILE *p;
    p=fopen(ar,"rb");
    printf("Datos de %s:\n",ar);
    fread(&x,sizeof(int),1,p);
    while(!feof(p))
    {
        printf("%d \n",x);
        fread(&x,sizeof(int),1,p);
    }
    fclose(p);
}
