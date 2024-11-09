#include <stdio.h>

int mostrar_menu (int num1, int num2);
int sumar (int a, int b);
int restar (int a, int b);
int multiplicar (int a, int b);
float dividir (int a, int b);

int main ()
{

    int num1, num2, opcion, resultado;
    float resultado_div;

    printf ("Ingrese el primer numero: ");
    scanf ("%d", &num1);
    printf ("Ingrese el segundo numero: ");
    scanf ("%d", &num2);

    do
    {
        opcion = mostrar_menu (num1, num2);

        switch (opcion)
        {
            case 1: resultado = sumar (num1, num2);
            printf ("\nEl resultado de la suma es: %d\n", resultado);
            break;

            case 2: resultado = restar (num1, num2);
            printf ("\nEl resultado de la resta es: %d\n", resultado);
            break;

            case 3: resultado = multiplicar (num1, num2);
            printf ("\nEl resultado de la multiplicacion es: %d\n", resultado);
            break;

            case 4: resultado_div = dividir (num1, num2);
            printf ("\nEl resultado de la division es: %.1f\n", resultado_div);
            break;

            case 5: printf ("Ingrese el primer numero: ");
            scanf ("%d", &num1);
            printf (" Ingrese el segundo numero: ");
            scanf ("%d", &num2);
            break;

            case 6: printf ("\nSaliendo del programa ...\n");
            break;

            default: printf ("\nOpcion invalida. Intente de nuevo.\n");
            break;
        }

    }while (opcion != 6);

    return 0;
}

int mostrar_menu (int num1, int num2)
{
    int opcion;

    printf("\nMenu de Opciones\n");
    printf("---- -- --------\n");
    printf("Numero 1: %d Numero 2: %d\n", num1, num2);
    printf("1) Sumar\n");
    printf("2) Restar\n");
    printf("3) Multiplicar\n");
    printf("4) Dividir\n");
    printf("5) Ingresar Nuevos Numeros\n");
    printf("6) Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    while (opcion < 1 || opcion > 6)
    {
        printf ("Opcion invalida. Ingrese una opcion de 1 a 6: ");
        scanf ("%d", &opcion);
    }

    return opcion;
}

int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    return a * b;
}

float dividir(int a, int b)
{
    return (float)a / b;
}

