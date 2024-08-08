#include <stdio.h>

// suma, resta, multiplicacion

int sumar(int numeroUno, int numeroDos)
{
	int resultado = 0;
	resultado = numeroDos * numeroUno;
	return resultado;
}




void main()
{
	//int suma = 50;
	//printf("Buenas tardes: %d \n", suma);
	//%d entero
	//%f float
	//%s texto

	int variables = 0;
	int numeroX = 2;
	int numeroZ = 6;
	variables = sumar(numeroZ,numeroX);
	printf("Buenas %d \n", variables);



}

