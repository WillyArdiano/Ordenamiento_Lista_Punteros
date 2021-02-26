#include <stdio.h>
#include <stdlib.h>

struct Numero
{
    int valor;
    struct Numero *siguente;
    struct Numero *anterior;
};



void mostrarMenu();
void agregarNumero(int valor);
void ordenarNumeros();
void verLista();


struct Numero numeroPrincipal;
int opcion;
int valorNumero;
int cantidadDeNumeros;


int main(){
    mostrarMenu();
}

void mostrarMenu(){
    printf("\nSeleccione opcion a realizar\n1. Ingresar numero\n2. Ordenar numeros\n3. Ver lista\n4. Salir\n");
    scanf("%d",&opcion);
    if(opcion==1){
        printf("Ingrese numero a agregar:\n");
        scanf("%d",&valorNumero);
        agregarNumero(valorNumero);
    }else if(opcion==2){
        ordenarNumeros();
    }else if(opcion==3){
        verLista();
    }else{
        exit(-1);
    }
}

void agregarNumero(int valor){
    struct Numero *nuevoNumero = (struct Numero*)malloc(sizeof(struct Numero));
    nuevoNumero->valor=valor;
    if(numeroPrincipal.siguente==NULL){
        numeroPrincipal.siguente=nuevoNumero;
    }else{
        struct Numero *numeroTemporal = numeroPrincipal.siguente;
        while (numeroTemporal->siguente!=NULL)
        {
            numeroTemporal = numeroTemporal->siguente;
        }
        numeroTemporal->siguente=nuevoNumero;
        nuevoNumero->anterior=numeroTemporal;        
    }
    printf("Numero agregado\n");
    cantidadDeNumeros++;
    mostrarMenu();
}

void verLista(){
    struct Numero *numeroTemporal = &numeroPrincipal;
    printf("-----------------------------INICIO---------------------------------\n");
    if(numeroPrincipal.siguente!=NULL){
        numeroTemporal=numeroPrincipal.siguente;
        while(numeroTemporal->siguente!=NULL){
            printf("Numero: %d\n",numeroTemporal->valor);
            numeroTemporal=numeroTemporal->siguente;
        }
        printf("Numero: %d\n",numeroTemporal->valor);
    }
    printf("------------------------------FIN----------------------------------\n");
    mostrarMenu();
}

void ordenarNumeros(){
    struct Numero *apuntador1 = numeroPrincipal.siguente;
    struct Numero *apuntador2 = numeroPrincipal.siguente->siguente;
    int valorTemporal;

    if(apuntador1!=NULL && apuntador2!=NULL){
        //hay almenos 2 elementos en la lista
        for (int i = 0; i < cantidadDeNumeros; i++)
        {
            while (apuntador2!=NULL)
            {
                if(apuntador1->valor>apuntador2->valor){
                    //switch
                    valorTemporal = apuntador1->valor;
                    apuntador1->valor = apuntador2->valor;
                    apuntador2->valor=valorTemporal;
                }
                apuntador1=apuntador1->siguente;
                apuntador2=apuntador2->siguente;
            }
            apuntador1 = numeroPrincipal.siguente;
            apuntador2 = numeroPrincipal.siguente->siguente; 
        }
        
    }
    printf("Numeros Ordenados\n");
    mostrarMenu();
}