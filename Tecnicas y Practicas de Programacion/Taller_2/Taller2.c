#include <stdio.h>


// Muestra lineas de asteriscos 2 veces dependiendo del numero digitado por el usuario no mayor a 15

void lineaAsteriscos()
{
  int bandera = 0;
  printf("Bienvenido a Astericomania\n\n");
  while(bandera < 10)
  {
    int contador = 0, numeroAsteriscos = 0;
    printf("Digite un numero: ");
    scanf("%d", &numeroAsteriscos);
    if (numeroAsteriscos > 0 && numeroAsteriscos <= 15)
    {
        for(contador = 1; contador <= (numeroAsteriscos*2); contador++)
        {
            if (contador == 1)
            {
                printf("\n%d", numeroAsteriscos);
            }
            printf(" * ");
            if (contador == (numeroAsteriscos*2))
            {
                printf("%d\n\n", numeroAsteriscos);
            }
            if (contador == numeroAsteriscos)
            {
                printf("%d \n%d", numeroAsteriscos ,numeroAsteriscos);
            }
        }
        bandera ++;
    }
  }
}

// Muestra el promedio de los numeros dados por el usuario en un rango de 50 a 80
// y lo felicita si digita 71

void juegoDivertidisimo()
{
  int contador = 0, cantidadJugadas = 0, rango = 0, totalNumeros = 0, contadorRangoDos = 0, bandera = 1;
  float promedio, contadorRangoUno = 0;
  printf("Bienvenido al JUEGO DEFINITIVO\n\n");
  printf("Digite la candidad de veces que jugara: ");
  scanf("%d", &cantidadJugadas);
  while(contador < cantidadJugadas)
  {
    printf("Digite un numero entre 50 y 80: ");
    scanf("%d", &rango);
    if (rango >= 50 && rango <= 80)
    {
      if (rango == 71)
      {
        if (bandera == 1)
        {
          printf("felicidades\n");
          bandera ++;
        }
        else if (bandera == 2)
        {
          printf("felicidades, venga manana por un premio\n");
          bandera ++;
        }
        else if (bandera == 3)
        {
          printf("¡¡esta muy sospechoso!!\n");
          bandera ++;
        }
        contadorRangoUno --;
        totalNumeros -= rango;
      }
      if (rango >= 50 && rango <= 60)
      {
        contadorRangoDos++;
      }
      contadorRangoUno++;
      totalNumeros += rango;
      contador ++;
    }
    else
    {
      printf("El numero esta mal digitado\n");
    }
  }
  promedio = ( totalNumeros / contadorRangoUno);
  printf("%f\n", promedio);
}

// Muestra el inventario de La Farra (frutas, verduras y cuantos camiones llegaron)

void laFarra()
{
  int dias = 0, camionesA = 0, camionesB3 = 0, camionesB4 = 0;
  float cebollaKilos = 0, naranjaKilos = 0, mangoKilos = 0;
  printf("Bienvenido a La Farra (productos frescos y de calidad)\n\n");
  printf("¿Cuantos dias se hara el inventario de productos?: ");
  scanf("%d", &dias);
  while(dias > 0)
  {
    int cantidadCamiones = 0, camion = 0, cantidadProductos = 0;
    float cebolla = 0, naranja = 0, mango = 0;
    printf("Digite la candidad de camiones llegaron el dia de hoy: ");
    scanf("%d", &cantidadCamiones);
    while(cantidadCamiones > 0)
    {
      printf("Digite que tipo de camion es (1. para A) y (2. para B): ");
      scanf("%d", &camion);
      if(camion == 1)
      {
        camionesA ++;
        cantidadCamiones --;
      }
      else if(camion == 2)
      {
        printf("Digite cuantos productos trae el camion 2, 3 o 4: ");
        scanf("%d", &cantidadProductos);
        if(cantidadProductos == 2)
        {
          printf("Digite cuantos kilos de cebolla trajo: ");
          scanf("%f", &cebolla);
          cebollaKilos += cebolla;
        }       
        else if(cantidadProductos == 3)
        {
          printf("Digite cuantos kilos de cebolla trajo: ");
          scanf("%f", &cebolla);
          cebollaKilos += cebolla;
          printf("Digite cuantos kilos de naranja trajo: ");
          scanf("%f", &naranja);
          naranjaKilos += naranja;          
          camionesB3 ++;
        }
        else if(cantidadProductos == 4)
        {
          printf("Digite cuantos kilos de cebolla trajo: ");
          scanf("%f", &cebolla);
          cebollaKilos += cebolla;
          printf("Digite cuantos kilos de naranja trajo: ");
          scanf("%f", &naranja);
          naranjaKilos += naranja;
          printf("Digite cuantos kilos de mango trajo: ");
          scanf("%f", &mango);
          mangoKilos += mango;                              
          camionesB4 ++;
        }
        cantidadCamiones --;
      }
    }
    dias --;
  }
  printf("Llegaron %d camiones tipo A a La Farra\n", camionesA);
  printf("Llegaron %d camiones de 3 productos y %d camiones de 4 productos a La Farra\n", camionesB3, camionesB4);
  printf("Llegaron %f kilos de cebolla a La Farra\n", cebollaKilos);
  printf("Llegaron %f kilos de naranja a La Farra\n", naranjaKilos);
  printf("Llegaron %f kilos de mango a La Farra\n", mangoKilos);
}

// Muestra los numeros primos de 1 a (n >= 1000) y si la suma de esos primos da primo

void numerosPrimos()
{
  int contadorNumero = 1, contadorPrimos = 1, numero = 0, primos3Digitos = 0, bandera = 1, sumaPrimos = 0;
  printf("Bienvenido a Primo Mania\n\n");
  while(contadorNumero != 0)
  {
    printf("Digite un numero igual o mayor que 1000: ");
    scanf("%d", &numero);
    if(numero >= 1000)
    {
      contadorNumero = 0;     
    }
    else
    {
      printf("Ohhh es muy pequeño D:\n");
    }
  }
  while(contadorPrimos <= numero)
  {
    int comprobarPrimos = 1, esPrimo = 0, comprobarPrimosSumas = 1, esPrimoSuma = 0, sumaPrimosRespusta = 0;
    for(comprobarPrimos = 1; comprobarPrimos <= contadorPrimos; comprobarPrimos++)
    {
      if(contadorPrimos % comprobarPrimos == 0)
      {
        esPrimo ++; 
      }
    }
    if(esPrimo <= 2)
    {
      if(contadorPrimos < 100)
      {
        if (bandera == 1)
        {
          printf("Los numeros primos < 100 son:\n");
          bandera ++;
        }
        printf("%d\n", contadorPrimos);
      }
      else if(contadorPrimos >= 100 && contadorPrimos < 1000)
      {
        if (bandera == 2)
        {
          printf("\nLos numeros primos >= 100 y < 1000 son:\n");
          bandera ++;
        }
        printf("%d\n", contadorPrimos);
        primos3Digitos ++;
      }
      else if(contadorPrimos >= 1000)
      {
        if (bandera == 3)
        {
          printf("\nLos numeros primos >= 1000 son:\n");
          bandera ++;
        }
        printf("%d\n", contadorPrimos);
      }
    }
    sumaPrimos = contadorPrimos;
    while(sumaPrimos > 0)
    {
      sumaPrimosRespusta += sumaPrimos % 10;
      sumaPrimos = sumaPrimos/10;
    }
    for(comprobarPrimosSumas = 1; comprobarPrimosSumas <= sumaPrimosRespusta; comprobarPrimosSumas++)
    {
      if(sumaPrimosRespusta % comprobarPrimosSumas == 0)
      {
        esPrimoSuma ++; 
      }
    }
    if(esPrimo <= 2 && esPrimoSuma <= 2)
    {
      printf("La suma de los digitos de este numero es %d y ademedas es primo\n", sumaPrimosRespusta);
    }
    contadorPrimos ++;
  } 
  printf("\nHubieron %d numeros primos de 3 digitos\n", primos3Digitos);
}




void menu()
{
  int opciones;
  do
  {
    printf("1. Asteriscos\n");
    printf("2. Juego definitivo\n");
    printf("3. La Farra\n");
    printf("4. Numeros primos\n");
    printf("5. Salir\n");

    printf("Digite que opcion quiere:\n");
    scanf("%d", &opciones);
      switch(opciones)
      {
        case 1:
          lineaAsteriscos();
          break;
        case 2:
          juegoDivertidisimo();
          break;
        case 3:
          laFarra();
          break;
        case 4:
          numerosPrimos();
          break;
        case 5:
          break;
        default:
          printf("Digite una opcion valida\n");
      }

  }while(opciones != 5);
}

int main() 
{
  menu();
  return 0;
}