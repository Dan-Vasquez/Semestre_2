
//bibliotecas.
#include <stdio.h>

//sumarNumeros
int suma(int x, int y){
  return x+y;
}
// restarNumeros
int resta(int x, int y){
  return x-y;
}
// multiplicarNumeros
int multiplicacion(int x, int y){
  return x*y;
}
// dividirNumeros
float division(int x, int y){
  float resultado_division=0.0;
  if(y>0){
	resultado_division=(float)x/ (float)y;
  }else{
	printf("No se puede hacer esta operacion para los numeros %d--%d \n", x,y);
  }
  return resultado_division;
}
// encontrarPalindromo
void palindromo(int x){
  int numInvertido = 0;
  int numBase = x;

  while(x > 0)
  {
    numInvertido = numInvertido + x % 10;
    numInvertido = numInvertido * 10;
    x = x/10;
  }

  if((numInvertido/10) == numBase){
    printf("El numero %d es palindromo \n",numBase);
  }
  else{
    printf("El numero %d no es palindromo \n",numBase);
 }
}

//encuentraAñoBisiesto
int fechaBisiesto(int x){

if((x % 4) == 0){
return 1;
}

return 0;

}

// definirVariables
int main(){
  int numeroUno,numeroDos,numeroPalindromo,resultadoEntero,resultadoPalindromo,fecha,resultadoFecha;
  float resultadoFlotante;
// solicitarNumeros
  printf("Bienvenidos a este programa que realiza operaciones matematicas basicas con 2 numeros \n");
  printf("Ingrese el numero uno \n");
  scanf("%d",&numeroUno);
  printf("Ingrese el numero dos \n");
  scanf("%d",&numeroDos);
  printf("Ingrese un numero de 9 digitos \n");
  scanf("%d",&numeroPalindromo);
  printf("Ingrese una fecha anual \n");
  scanf("%d",&fecha);
  
  // resultadoOperaciones
  resultadoEntero=suma(numeroUno,numeroDos);
  printf("Resultado operacion suma %d \n", resultadoEntero);
  
   resultadoEntero=resta(numeroUno,numeroDos);
  printf("Resultado operacion resta %d \n", resultadoEntero);
  
   resultadoEntero=multiplicacion(numeroUno,numeroDos);
  printf("Resultado operacion multiplicacion %d \n", resultadoEntero);
  
   resultadoFlotante=division(numeroUno,numeroDos);
  printf("Resultado operacion division %f \n", resultadoFlotante);

  palindromo(numeroPalindromo);

  resultadoFecha = fechaBisiesto(fecha);
  if(resultadoFecha == 1){
    printf("La fecha %d es bisiesto y mi nombre es Daniel \n", fecha);
  }
  else{
    printf("La fecha %d no es bisiesto y tengo 2 hermanos \n", fecha);
  }
  
  return 0;

}