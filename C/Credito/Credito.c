#include <stdio.h>

int main(void)
{
    char string[20];
    int longitud = 0;

    printf("Ingrese el número de su tarjeta de crédito/débito:\n");
    fgets(string, 20, stdin);

    // Eliminar el salto de línea y calcular la longitud
    for (int i = 0; i < 20; i++)
    {
        if (string[i] == '\n' || string[i] == '\0')
        {
            string[i] = '\0';
            longitud = i;
            break;
        }
    }

    // Validar que solo haya dígitos
    for (int i = 0; i < longitud; i++)
    {
        if (string[i] < '0' || string[i] > '9')
        {
            printf("INVALID\n");
            return 0;
        }
    }

    // Algoritmo de luhn
    int suma = 0;
    int multiplicar = 0;

    for (int i = longitud - 1; i >= 0; i--)
    {
        int digito = string[i] - '0';

        if (multiplicar)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
        }
        suma += digito;
        multiplicar = !multiplicar;
    }

    // Validar
    if (suma % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // identificar tipo de tarjeta
    if (longitud == 15 && string[0] == '3' && (string[1] == '4' || string[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (longitud == 16 && string[0] == '5' && (string[1] >= '1' && string[1] <= '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((longitud == 13 || longitud == 16) && string[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
