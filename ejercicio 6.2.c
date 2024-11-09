#include <stdio.h>

int EstaDentroDelRango (int num, int lim_inf, int lim_sup);
int LeerYValidar (int lim_inf, int lim_sup);

int main ()
{

    int num, count_100_500 = 0, count_pares_500_1200 = 0, sum_1200_2000 = 0, count_1200_2000 = 0;
    float div;

    while ((num = LeerYValidar (100, 2000)) != 99)
    {
        if (EstaDentroDelRango (num, 100, 500))
        {
            count_100_500 ++;
        }
        if (EstaDentroDelRango (num, 500, 1200) && num % 2 == 0)
        {
            count_pares_500_1200 ++;
        }
        if (EstaDentroDelRango (num, 1200, 2000))
        {
            sum_1200_2000 += num;
            count_1200_2000 ++;
            div = (float)sum_1200_2000 / count_1200_2000;
        }
    }

    printf ("\n Cantidad de numeros entre 100 y 500: %d\n", count_100_500);
    printf ("Cantidad de numeros pares ingresados entre 500 y 1200: %d\n", count_pares_500_1200);

    if (count_1200_2000 > 0)
    {
        printf ("Promedio de numeros entre 1200 y 2000: %.1f\n", div);
    }
    else
    {
        printf ("NO se ingresaron numeros mayores a 1200.\n");
    }

    return 0;
}

int EstaDentroDelRango (int num, int lim_inf, int lim_sup)
{
    if (num >= lim_inf && num <= lim_sup)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int LeerYValidar (int lim_inf, int lim_sup)
{
    int num;
    do
    {
        printf ("Ingrese un numero entre %d y %d (99 para salir): ", lim_inf, lim_sup);
        scanf ("%d", &num);

        if ((num < lim_inf || num > lim_sup) && num != 99)
        {
            printf ("Numero invalido. Intente de nuevo.\n\n");
        }
    }while (!EstaDentroDelRango (num, lim_inf, lim_sup) && num != 99);

    return num;
}



