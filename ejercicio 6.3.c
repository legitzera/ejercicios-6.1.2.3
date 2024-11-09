#include <stdio.h>

int CUADRANTE(int x, int y);
int PUNTAJE(int c1, int c2, int c3, int c4, int centro);

int main()
{
    int participante, x, y;
    int c1, c2, c3, c4, centro;
    int puntaje, max_puntaje = 0, ganador = 0;
    int total_disparos_centro = 0;

    while (1)
    {
        printf("Ingrese el numero del participante (negativo para finalizar): ");
        scanf("%d", &participante);

        if (participante < 0)
            break;

        // Inicializamos contadores para cada cuadrante y el centro
        c1 = c2 = c3 = c4 = centro = 0;

        for (int i = 1; i <= 5; i++)
        {
            do
            {
                printf("Ingrese las coordenadas X e Y del disparo %d: ", i);
                scanf("%d %d", &x, &y);

                // Validamos que el disparo no esté en los ejes
                if (x == 0 || y == 0)
                    printf("Disparo sobre el eje. Ingrese nuevamente.\n");

            } while (x == 0 || y == 0); // Repetimos si el disparo está sobre los ejes

            // Determinamos el cuadrante del disparo
            int cuadrante = CUADRANTE(x, y);

            // Contamos los disparos según el cuadrante
            switch (cuadrante)
            {
                case 1: c1++; break;
                case 2: c2++; break;
                case 3: c3++; break;
                case 4: c4++; break;
                case 0: centro++; break;
            }
        }

        // Calculamos el puntaje del participante actual
        puntaje = PUNTAJE(c1, c2, c3, c4, centro);
        printf("Participante %d - Puntaje: %d\n", participante, puntaje);
        printf("Disparos en cada cuadrante: C1=%d, C2=%d, C3=%d, C4=%d, Centro=%d\n", c1, c2, c3, c4, centro);

        // Actualizamos el total de disparos en el centro
        total_disparos_centro += centro;

        // Determinamos el participante con el puntaje máximo
        if (puntaje > max_puntaje)
        {
            max_puntaje = puntaje;
            ganador = participante;
        }
    }

    // Mostramos los resultados finales
    printf("\nParticipante ganador: %d con un puntaje de %d\n", ganador, max_puntaje);
    printf("Cantidad total de disparos en el centro: %d\n", total_disparos_centro);

    return 0;
}

// Función CUADRANTE: Determina en qué cuadrante se encuentra un disparo o si está en el centro
int CUADRANTE(int x, int y)
{
    if (x == 0 && y == 0)
        return 0; // Centro

    if (x > 0 && y > 0)
        return 1; // Primer cuadrante
    if (x < 0 && y > 0)
        return 2; // Segundo cuadrante
    if (x < 0 && y < 0)
        return 3; // Tercer cuadrante
    if (x > 0 && y < 0)
        return 4; // Cuarto cuadrante

    return -1; // Esto nunca debería suceder
}

// Función PUNTAJE: Calcula el puntaje total basado en los disparos en cada cuadrante y el centro
int PUNTAJE(int c1, int c2, int c3, int c4, int centro)
{
    return (c1 + c2) * 50 + (c3 + c4) * 40 + centro * 100;
}


