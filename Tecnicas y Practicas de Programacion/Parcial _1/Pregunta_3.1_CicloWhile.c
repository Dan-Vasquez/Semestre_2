/*
    Descripcion del problema:

    Eres un detective que tiene la tarea de encontrar a los 2 responsables
    de un robo de las joyas de la reina "LOS HERMANOS SINCERIDAD", para esta
    tarea tendras que preguntarle al detective si capturo a alguno de los hermano 
    para ir interrogando a cada crimital de la ciudad (Ni los
    cuente son muchos) hasta encontrarlos, la condicion para encontrar a los
    hermanos es preguntarles a cada uno cuantas joyas robaron en total (17)
    con la peculiaridad de que ellos no pueden mentir por un golpe que les dio 
    su madre con una zapato en la cabeza de pequeños y ademas uno de los dos le 
    suma a todo el doble y el otro le suma a todo 30 (pero shhh!!!, que nadie lo sabe
    aparte de ti).
*/

#include <stdio.h>


int main()
{   
    int hermanosEncontrados, joyasRobadas;

    printf("Por favor digita cuantos hermanos se han capturado hasta la fecha: ");
    scanf("%d", &hermanosEncontrados);
    while(hermanosEncontrados != 2)
    {
        printf("Digita cuantas joyas de la reina se robaron: ");
        scanf("%d", &joyasRobadas);
        if ( joyasRobadas == 34 )
        {
            hermanosEncontrados++;
            printf("Pasaras una muy larga temporada tras las rejas\n\n");
        }
        else if ( joyasRobadas == 37 )
        {
            hermanosEncontrados++;
            printf("Disfruta de una vida larga en la prision\n\n");
        }
        else
        {
            printf("No eres el ladron, pero te estare vijilando, cuida tu espalda\n\n");
        }
    }
    
    printf("Logramos encontrar a LOS HERMANOS SINCERIDAD, gracias por tu servicio\n");
    return 0;
}

/*
    Ciclo usado y justificacion:

    En mi opinion, en este tipo de problema es mejor utilizar un ciclo while, ya que al tener que ejecutar
    el ciclo de forma infinita hasta cumplirse una condicion, es mas facil de manipular el while, utilizando
    variables para que termine el ciclo dada la condicion. Por esto no se puede usar un ciclo for pues no
    tengo una cantidad finita de veces en la que se repetira el ciclo, ni se puede usar un ciclo do_while pues,
    debo tener una condicion de entrada para entrar al ciclo.
    n. 
*/


