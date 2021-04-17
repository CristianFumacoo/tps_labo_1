#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"


int main()
{
    int numUno = 0;
    int numDos = 0;

    int flagFactUno;
    int flagFactDos;

    int flagNumUno = 0;
    int flagNumDos = 0;
    int flagHacerCuentas = 0;


    int salir = 0;
    int opc;

    float suma;
    float resta;
    float multiplicacion;
    float division;
    float factorialUno;
    float factorialDos;



    do
    {
        system("cls");

        calcu(numUno,numDos);
        opc = menu();

        flagFactUno = 0;
        flagFactDos = 0;


        switch(opc)
        {
            case 1:
                numUno = pedirNumero();
                flagNumUno = 1;
            break;

            case 2:
                numDos = pedirNumero();
                flagNumDos = 1;
            break;

            case 3:
                if(flagNumUno == 1 && flagNumDos == 1)
                {
                    suma = sumar(numUno,numDos);
                    resta = restar(numUno,numDos);
                    multiplicacion = multiplicar(numUno,numDos);
                    division = dividir(numUno,numDos);
                    factorialUno = factorizar(numUno);
                    factorialDos = factorizar(numDos);

                    flagHacerCuentas = 1;

                    printf("Las operaciones se realizaron correctamente.\n");
                }
                else
                {
                    printf("Asegurarse de ingresar los 2 numeros\n");
                }

            system("pause");
            break;

            case 4:
                if(flagHacerCuentas)
                {
                    printf("La suma dio: %.0f\n",suma);
                    printf("La resta dio: %.0f\n",resta);
                    printf("La multiplicacion dio: %.0f\n",multiplicacion);

                    if(numUno != 0)
                    {
                        printf("La division dio: %.2f\n",division);
                    }
                    else
                    {
                        printf("No se puede dividir por 0\n");
                    }

                    if(factorialUno <= 2147483647)
                    {
                        printf("Factorial del Primer numero: %.0f\n",factorialUno);
                        flagFactUno = 1;
                    }
                    else if(!flagFactUno)
                    {
                        printf("El factorial del numero Uno es demasiado grande.\n");
                    }

                    if(factorialDos <= 2147483647)
                    {
                        printf("Factorial del Segundo numero: %.0f\n",factorialDos);
                        flagFactDos = 1;
                    }
                    else if(!flagFactDos)
                    {
                        printf("El factorial del numero Dos es demasiado grande.\n");
                    }
                }
                else
                {
                    printf("Asegurese de hacer las cuentas.\n");
                }


                system("pause");
                break;
            case 5:
                printf("Nos vemos!");
                salir = 1;
                break;
            default:
                printf("Opcion incorrecta.\n");
                system("pause");
                break;
        }


    }while(salir == 0);
    return 0;
}
































