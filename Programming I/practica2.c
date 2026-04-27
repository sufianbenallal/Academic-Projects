// practica 2.c
//Autor: Sufian Benallal Chakroun
//Clase: 1C2

#include <stdio.h>
#include <stdlib.h>


// DECLARACIONES DE FUNCIONES-------------------------------------------------------------------------------------------

int menu(); // declaración de la función "menu"
int desplazar(int, int);
int parImpar(int);
void operacionesLogicasBits();
void intercambiar(double*, double*);
int numeroBits(int);
int obtenerValorBit(int, int);
int ponerACeroBit(int, int);
int cambiarBits(int, int, int);
long factorial(long);

int main ()
{
    // DEFINICIONES DE VARIABLES----------------------------------------------------------------------------------------

    int opcion; // opción elegida del menú
    int x = 0, y = 0, z = 0, p = 0;
    long xl = 0, yl = 0, zl = 0;
    double xd = 0, yd = 0, zd = 0, vd = 0;


    setvbuf(stdout, NULL, _IONBF, 0); //incluir si en depuración no muestra el texto de los printf por pantalla.

    printf ("PRACTICA 2\n");
    printf ("==========\n");

    opcion = menu(); // llama/invoca a la función "menu"

    while (opcion != 10) // sentencia repetitiva
    {
        switch (opcion) // sentencia condicional
        {
            case 1:
                printf("Ejercicio 1: Desplazar\n"); // llama a la función "printf"

                // Solicitar datos introducidos por el teclado"
                printf("Introduzca un numero: ");
                scanf("%d", &y);

                // Solicitar por teclado posiciones a desplazar
                printf("Posiciones a desplazar a la derecha: ");
                scanf("%d", &z);

                // Llamar a la función "desplazar"
                x = desplazar(y,z);

                // Mostrar el resultado
                printf("El numero desplazado es: %d\n\n", x);

                break;

            case 2:
                printf("Ejercicio 2: Par o impar\n");

                // Solicitar datos introducidos por el teclado
                printf("Introduzca un numero: ");
                scanf("%d", &y);

                // Llamar a la función "parImpar"
                x = parImpar(y);

                // Mostrar el resultado
                if (x != 0)
                    printf("El numero %d es impar\n\n", y);
                else
                    printf("El numero %d es par\n\n", y);
                break;

            case 3:

                printf("Ejercicio 3: Operaciones logicas y a nivel de bits\n");
                operacionesLogicasBits();
                break;

            case 4:
                printf("Ejercicio 4: Poner a cero un bit\n");

                //Solicitar datos introducidos por el teclado
                printf("introduzca un numero: ");
                scanf("%d", &y);

                // Solicitar por teclado la posición del bit
                printf("Posicion del bit a poner a cero: ");
                scanf("%d", &z);

                // LLamar a la función "ponerACeroBit"
                x = ponerACeroBit(y,z);

                //Mostrar el resultado
                printf("El numero modificado es: %d\n\n", x);

                break;
            case 5:
                printf("Ejercicio 5: Obtener valor bit\n");

                //Solicitar por teclado un numero entero
                printf("Introduzca un numero entero: ");
                scanf("%d", &y);

                // Preguntar por teclado la posicion del bit a conocer
                do{
                    printf("Introduzca la posicion del bit que desea conocer: ");
                    scanf("%d", &z);
                }while(z<0);

                // Llamar a la función
                x = obtenerValorBit(y,z);

                //Mostrar el resultado
                if( x >= 1){
                    printf("el valor del bit es: 1 \n", x);
                }
                else {
                    printf("el valor del bit es: 0 \n");
                }
                break;
            case 6:
                printf("Ejercicio 6: Factorial\n");

                //Solicitar por teclado un número entero positivo
                do
                {
                    printf("Introduzca un numero entero positivo: ");
                    scanf("%ld", &yl);
                }
                while (yl < 0);

                // Llamar a la función "factorial"
                xl = factorial(yl);

                // Comprobar que el numero sea <0 y <16 y mostrar el resultado
                if (xl==-1)
                    printf("No es posible calcular el factorial\n");
                else
                    printf("El factorial de %ld es: %ld\n\n", yl, xl);
                break;

            case 7:
                printf("Ejercicio 7: Numero de bits\n");

                // Solicitar datos introducidos por el teclado"
                do {
                    printf("Introduzca un numero entero positivo: ");
                    scanf("%d", &y);
                } while(y<0);

                //Llamar a la función
                x = numeroBits(y);

                // Mostrar el resultado
                printf("El numero de bits para representar %d es: %d\n", y, x);
                break;

            case 8:
                printf("Ejercicio 8: Cambiar bits\n");

                // Solicitar datos introducios por teclado
                do {
                    printf("Introduza un numero entero positivo: ");
                    scanf("%d", &y);
                }while(y<0);

                // Pedir por teclado las caracteriticas de como invertir el bit
                printf("Posicion del bit inicial a invertir: ");
                scanf("%d",&p);
                printf("Numero de bits a invertir: ");
                scanf("%d",&z);

                //LLamar a la función
                x = cambiarBits(y,p,z);

                //Mostrar el resultado
                if(x==-1)
                    printf("Numero de bits no valido");
                else
                    printf("El numero modificado es: %d", x);
                break;

            case 9:
                printf("Ejercicio 9: Intercambiar\n");

                // Solicitar datos introducidos por el teclado"
                printf("Introduzca el primer valor: ");
                scanf("%lf", &xd);

                // Solicitar por teclado el segundo valor
                printf("Introduzca el segundo valor: ");
                scanf("%lf", &yd);

                // Llamar a la función "intercambiar"
                intercambiar(&xd, &yd);
                printf("Nuevos valores : \n"
                       "\tx: %g\n"
                       "\ty: %g\n", xd, yd);
                // Mostrar el resultado"

                break;

            default:
                printf ("ERROR: Opcion incorrecta.\n");

                break;
        }
        opcion = menu(); // llamar a la función "menu"
    }
    return 0; //Final del programa
}

// DEFINICIONES DE FUNCIONES--------------------------------------------------------------------------------------------

int menu() // definición de la función "menu"
{
    int op;
    do // sentencia repetitiva
    {
        printf ("\n"
                "\t01.- Ejercicio 1\n"
                "\t02.- Ejercicio 2\n"
                "\t03.- Ejercicio 3\n"
                "\t04.- Ejercicio 4\n"
                "\t05.- Ejercicio 5\n"
                "\t06.- Ejercicio 6\n"
                "\t07.- Ejercicio 7\n"
                "\t08.- Ejercicio 8\n"
                "\t09.- Ejercicio 9\n"
                "\t10.- Salir\n"
                "\n"
                "Elija una opcion: ");
        scanf ("%d", &op); // llamar a la función "scanf"
        if (op < 1 || op > 10) // sentencia condicional
        {
            // printf("Opción no válida\n");
            printf("Opci%cn no v%clida\n", 0xA2, 0xA0);
        }
    }
    while (op < 1 || op > 10); // condición
    return op;
}

//------------------------------------------------------------------------------------
//1
int desplazar(int n, int npos)
{
    int ndesplazado;
    ndesplazado = n >> npos;
    return ndesplazado;
}
//-----------------------------------------------------------------------------------
//2
int parImpar(int n)
{
    int resultado;
    if(n%2==0)
        resultado = 0;
    else
        resultado = 1;

    return resultado;
}
//--------------------------------------------------------------------------------
//3
void operacionesLogicasBits() {
    int a = 8, b = 0, c = 15, d = 93, e, r1, r2, r3, r4, r5, r6;
    r1 = a && b || c && !d; // Falso -> r1= 0;
    r2 = !a || b && c || d; // Verdadero -> r2= 1;
    r3 = a < b || !c < d; // Falso -> r3= 0;
    r4 = a + b > d - c;  //Falso -> r4= 0;
    r5 = a && b && !c || !(a && b) && c; // Verdadero -> r5= 1;

    a = 0x12;
    b = 0x56;
    c = 0x9a;
    d = 0x0f;
    e = 0360;

    r1 = a & b | c; // r1= 154;
    r2 = c & 0177; //r2= 26;
    r3 = ~a & b ^ c; //r3= 222;
    r4 = e & c; //r4= 144;
    r5 = r4 & ~077;  //r5= 128;
    r6 = (a & d) << 4 | (a & e) >> 4; //r6= 33;
}
//------------------------------------------------------------------------------
//4
int ponerACeroBit(int n, int nPosBit)
{
    int resultado, mascara;
    mascara = 1 << nPosBit;
    resultado = n & ~mascara;
    return resultado;
}
//------------------------------------------------------------------------------
//5
int obtenerValorBit (int n, int nPosBit)
{
int resultado;
resultado=n & (1 << nPosBit);
return resultado;
}
//--------------------------------------------------------------------------------
//6
long factorial(long n)
{
    long factorial = 1, i=0;
    if (n < 0 || n > 16)
        return -1;
    else;
    for (int i = n; i>0; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}
//----------------------------------------------------------------------------------
//7
int numeroBits(int n)
{
    int dosElevadoN = 2, nBits = 1;
    while (dosElevadoN <= n)
    {
        dosElevadoN = dosElevadoN * 2;
        nBits++;
    }
    return nBits;
}
//----------------------------------------------------------------------------------
//8
int cambiarBits(int n, int npos , int nbits)
{
int i=0, mascara=0;
if(nbits>npos+1)
    return -1;
else
    for(i = npos; i > npos - nbits; i--)
    {
        mascara=1<<i;
        n=n^mascara;
    }
    return n;
}
//-------------------------------------------------------------------------
//9
void intercambiar(double* xl, double* yl) {
    double b = *xl;
    *xl = *yl;
    *yl = b;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////