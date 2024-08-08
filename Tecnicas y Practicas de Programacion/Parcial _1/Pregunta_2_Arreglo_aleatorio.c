#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minFaltante(int arreglo[200])
{
    int cantidad, contador = 1, *pArreglo, contador2 = 0, faltante;
    while (contador != 0)
    {   
        int bandera = 0;
        pArreglo = arreglo;
        for(contador2 = 0; contador2 < 200; contador2++)
        {
            if (*(pArreglo++) != contador)
            {
                bandera ++;
            } 
        }       
        if(bandera == 200)
        {
            faltante = contador;
            contador = -1;
        }
        contador ++;
    }
    return faltante;
}

int maxFaltante(int arreglo[200])
{
    int cantidad, contador = 500, *pArreglo, contador2 = 0, faltante;
    while (contador != 0)
    {   
        int bandera = 0;
        pArreglo = arreglo;
        for(contador2 = 0; contador2 < 200; contador2++)
        {
            if (*(pArreglo++) != contador)
            {
                bandera ++;
            } 
        }       
        if(bandera == 200)
        {
            faltante = contador;
            contador = 1;
        }
        contador--;
    }
    return faltante;
}

int main()
{
    int arreglo[200], contador = 0, contador2, numAleatorio, *pArreglo;
    srand(time(NULL));
    printf("El arreglo de 200 datos entre 1 y 500 es:\n\n");
    while(contador < 200)
    {
        int bandera = 0;
        numAleatorio = 1 + rand()%(500-1+1);
        pArreglo = arreglo;
        if(contador == 0)
        {
            arreglo[contador] = numAleatorio;
            printf("%d ", numAleatorio);
            contador++;
        }
        else
        {
            for(contador2 = 0; contador2 < contador; contador2++)
            {
                if(*(pArreglo++) != numAleatorio)
                {
                    bandera++;
                }   
            }
            if(bandera == contador)
            {
                arreglo[contador] = numAleatorio;
                printf("%d ", numAleatorio);  
                contador++;  
            }            
        }     
    }
    printf("\n\nEl numero menor faltante es %d y el numero mayor faltante es %d\n", minFaltante(arreglo), maxFaltante(arreglo) );

    return 0;
}