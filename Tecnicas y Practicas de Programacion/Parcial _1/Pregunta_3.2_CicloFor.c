/*
    Descripcion del problema:

    Eres el encargado de hacer un programa pra un profesor de un colegio publico colombiano, 
    lo que debes hacer es un programa que guarde y muestre en un arreglo las notas de 20 estudiantes,
    en una tarea ademas mostrar por pantalla la participacion de los estudiantes (20 excelente, mas de 10 
    bueno y menos de 10 malo).

*/

#include <stdio.h>

void claseExcelente(int cantidad)
{
    if (cantidad == 20)
    {
        printf("La clase tuvo una excelente participacion\n");
    }
    else if (cantidad >= 10 && cantidad < 20)
    {
        printf("La clase tuvo una buena participacion\n");
    }
    else
    {
        printf("La clase tuvo una mala participacion\n");
    }
}

int main()
{   
    int cantidad = 0, contador, contador2, contador3; 
    float notaEstudiante = 0;
    printf("Digite cuantos estudiantes hicieron la tarea: ");
    scanf("%d", &cantidad);
    float notas[20];

    for(contador = 0; contador < cantidad; contador++)
    {
        printf("\nDigite la nota del estudiante %d: ", contador);
        scanf("%f", &notaEstudiante);
        notas[contador] = notaEstudiante;
    }
    for(contador3 = cantidad; contador3 < 20; contador3++)
    {
        notas[contador3] = 0;
    }
    for(contador2 = 0; contador2 < 20; contador2++)
    {
        printf("La nota del estudiante numero %d es %f\n", contador2, notas[contador2]);
    }
    claseExcelente(cantidad);
    return 0;
}

/*
    Ciclo usado y justificacion:

    En mi opinion es mejor utilizar ciclos for pues, para las diferentes soluciones del problemas se deben
    hacer los ciclos un finita cantidad de veces e ir llenando datos por lo que es mas sencillo utilizar un ciclo for
    para este ejercicio.


*/


