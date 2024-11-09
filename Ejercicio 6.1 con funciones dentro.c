#include <stdio.h>

int main ()
{

    int num1, num2, opcion;
    float resultado;

    printf ("Ingrese el primer numero: ");
    scanf ("%d", &num1);
    printf ("Ingrese el segundo numero: ");
    scanf ("%d", &num2);

    do
    {
        printf("\nMenu de Opciones\n");
        printf("---- -- --------\n");
        printf("Numero 1: %d Numero 2: %d\n", num1, num2);
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Ingresar Nuevos Numeros\n6) Salir\n");
        printf("Ingrese su opcion: \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1: resultado = num1 + num2;
            printf ("El resultado es : %.1f\n", resultado);
            break;

            case 2: resultado = num1 - num2;
            printf ("El resultado es : %.1f\n", resultado);
            break;

            case 3: resultado = num1 * num2;
            printf ("El resultado es : %.1f\n", resultado);
            break;

            case 4: resultado = num1 / num2;
            printf ("El resultado es : %.2f\n", resultado);
            break;

            case 5: printf ("Ingrese dos nuevos numeros: ");
            scanf ("%d%d", &num1, &num2);
            break;

            case 6: printf ("Saliendo del programa ...\n");
            break;

            default: printf ("Opcion NO valida. Ingrese una opcion correcta.");
            break;
        }
    }while (opcion != 6);

    return 0;
}


