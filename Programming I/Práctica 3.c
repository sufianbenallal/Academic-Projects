// Práctica 3
// Autor: Sufian Benallal Chakroun
// Fecha: 15/12/2021
// Propósito: Arrays, Sentencias de control

#include <stdio.h>
#include <stdlib.h>
int potencia (int base, int exp);
int factorial(int num);

int main()
{
	int opcion = 0, base, exponente, numero;
	while (opcion < 3)
	{
		printf("Elija una opción:\n ");
		printf("1 – Calcular la potencia ");
		printf("2 – Calcular número del factorial ");
		printf("3 - Salir ");
		scanf("%d", &opcion);
		if (opcion == 1)
		{
			printf("Introduzca la base:");
			scanf("%d", &base);
			do
			{
				printf("Introduzca el exponente:");
				scanf("%d", &exponente);
			} while (exponente < 0);

			printf("El resultado es:%d\n", potencia(base,
				exponente));
		}
		else if (opcion == 2)
		{
			printf("Introduzca un numero:");
			scanf("%d", &numero);
			printf("El factorial es:%d\n", factorial(numero));
		}
}
	//FIN while
	return 0;
}
//FIN main
int potencia(int base, int exponente)
{
	double resultado = 0;
	int exp = exponente;
	if (exp == 0)
		resultado = 1;
	else
	{
		if (exp < 0)
			exp = -exp;
		while (exp > 1)
		{
			resultado *= base;
			exp--;
		}
	}
		if (exp < 0)
			resultado = 1 / resultado;
		return resultado;
}


	int factorial(int numero)
	{
		int resultado = 0;
		if (numero == 0)
			resultado = 1;
		else
			resultado = numero;
		while (numero > 1)
		{
			numero--;
			resultado *= numero;
		}
		return resultado;
	}



//////////////////////////////////////////////////////////////////////////////////////////////////





#include <stdio.h>
#include <stdlib.h>
#define MAX 10

	int main()
	{
		int n, m, i, j, temp;
		int numeros[MAX], i;
		printf("Introduzca el númmero de numeros a ordenar: \n\n");
		scanf("%d", &n);

			printf("Introduce %d número: \n ", i);
			for (i = 0; i < MAX; i++)
				scanf(" %d", &numeros[i]);
			for (i = 0; i < MAX; i++)
				printf("%d \n", numeros[i]);

			for (m = 1; m < n; m++)
			{
				j = m - 1;
				temp = numeros[m];
				while (numeros[j]>temp && j>=0)
				{
					numeros[j + m] = numeros[j];
					j--;
				}
				numeros[j + m] = temp;
			}
		for (i = 0; i < MAX; i++)
			printf(" %d \n\n", numeros[i]);
		return 0;
	}


////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
	void cuenta_billetes_monedas(int, int[]);
	int main()
	{
		int valor[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
		int cantidad;
		printf("Practica 3, ejercicio 2\n");
		printf("Introduce una cantidad de euros (sin centimos): ");
		scanf("%d", &cantidad);
		if (cantidad <= 0)
		{
			printf("ERROR: La cantidad debe ser mayor que cero.\n");
			system("pause");
			return -1;
		}
		cuenta_billetes_monedas(cantidad, valor);
		system("pause");
		return 0;
	}
	//Completar aquí la definición de la función a realizar







	///////////////////////////////////////////////////////////////////////////////////////////////////




#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define SALIR 6

	int Menu();
	int introducir_array(int[]);
	void visualizar_array(int Array[], int n_eltos);
	void ordenar_insercion(int A[], int num);
	int busqueda_binaria(int x, int valores[], int num);
	int introducir_valor(int, int[], int);

	int main()
	{
		int opcion;
		int Array[MAX], n_eltos = 0, posición, x, a, resultado, q, nuevo;

		opcion = Menu();
		int op = 0, x, pos, resu;
		while ((op = Menu()) != SALIR)
		{
			switch (op)
			{
			case 1:
				printf("1. Introduce el array\n\n");
				n_eltos = introducir_array(Array);

				break;
			
			case 2:
				printf("2.Muestra el array\n\n");
				visualizar_array(Array, n_eltos);
				system("pause");

				break;
			
			case 3:
				printf("3.Reduce el array\n\n");
				ordenar_insercion (Array, n_eltos);
				
				break;
			
			case 4:
				printf("4.Busca un elemento en el array\n\n");
				if (n_eltos==0)
				{
					printf
					("No hay elementos en el array, por favor seleccione la opcion 1\n");
				}
				else
				{
					x = 1;
					for (a  = 0; a <n_eltos - 1; a++)
					{
						if (Array[a]>Array[a+1])
						{
							x = 0;
							a = n_eltos;
						}
					}
					if (x == 0)
					{
						printf("Los elementos no están ordenados, por favor seleccione la opción 3 anterior\n");
					}
					else
					{
						printf("Introduce el numero a ser buscado: ");
						scanf("%d", &x);
						posición = busqueda_binaria(x, Array, n_eltos);
						if (posición==-1)
						{
							printf("El numero %d no es el array\n, x");
						}
						else
						{
							printf("%d esta localizado en la posición %d\n", x, posición);
						}
					}

				}
				break;

			case 5:
				printf("5.Añade un elemento\n\n");
				printf("Introduce un numero a añadir:");
				scanf("%d", &x);
				resultado = leervalor(x, Array, n_eltos);
				if (resultado==-1)
				{
					printf("El array esta lleno\n");
				}
				else
				{
					printf("El valor fue añadido correctamente\n");
					n_eltos++;
				}

				break;

			case 6:
				printf("6.Modifica un elemento en el array\n\n ");
				printf("Introduce un valor a cambiar: ");
				scanf("%d", &q);
				if (n_eltos == 0);
				{
					printf("No hay elemento en el array, por favor seleccione la opcion 1 primero\n");
				}
				else
				{
					x = 1;
					for (a = 0; a < n_eltos - 1; a++)
					{
						if (Array[a]>Array[a+1])
						{
							x = 0;
							a = n_eltos;
						}
					}
					if (x==0)
					{
						printf("Elementos no ordenados, por favor seleccione la opcion 3 primero\n");
					}
					else
					{
						posición = busqueda_binaria(q, Array, n_eltos);
						if (posición==-1)
						{
							printf("El numero %d no esta en el array \n", q);
						}
						else
						{
							printf("%d esta localizado en la posición %d\n", q, posición);
							printf("Introduce la nueva posición %d valor: ", posición);
							scanf("%d", &nuevo);
							Array[posición - 1] = nuevo;
							printf("seleccione la opción 2 en orden para visualizar los cambios\n");
						}
					}
				}
				break;

			default:
				printf("ERROR: opción erronea\n\n");

				break;
			}
			system("pause");
			option = Menu();
		}
	}
	int Menu()
	{
		int op;
		system("cls");
		do
		{
			system("cls");
			printf("\n");
			printf("\t1. Introducir array\n");
			printf("\t2. Visualizar array\n");
			printf("\t3. Ordenar array\n");
			printf("\t4. Buscar un elemento en el array\n");
			printf("\t5. Leer un elemento del array\n");
			printf("\t6. Modifica un elemento en el array\n");
			printf("\t7. Salir\n\n Elige una opción:");
			scanf("%d", &op);
			if (op < 1 || op > 7)
			{
				printf("Opción no valida\n");
				system("pause");
			}
		} while (op < 1 || op > 7 );
		return op;
	}
	
	int leerarray(int arry[])
		int p, m;

	printf("Introduce el numero de numeros del array: ");
	scanf("%d", &p);
	while (p<1 || p<N )
	{
		printf("Error: El numero debe estar entre 1 y 10\n");
		system("pause");
		system("cls");
		printf("Introduce el numero de numeros en el array: ");
		scanf("%d", &p);
	}
	printf("Introducir %d numeros: \n", p);
	for (m = 0; m < p; m++)
	{
		scanf("%d, &arry[m]");
	}
	return p;

	
	void mirararray(int array[], int n_elto)
	{
		int m;

		if (n_elto==0)
		{
			printf("No hay elementos en el array, por favor seleccione la opción 1 primero");
		}
		else
		{
			for (m = 0; m < n_elto; m++)
				printf("%d", array[m]);
		}
	}
	printf("\n");

	void ordenerarray(int array[], int n_elto)
	{
		int i, j, aux;

		if (n_elto == 0)
			printf("Ni hay elemento en el array, por favor seleccione la opcion 1 primero");
	}
	else
	{
	for ( i = ; i < n_elto; i++)
	{
		j = i - 1;
		aux = array[i];
		while (array[j]>aux && j>=0)
		{
			Array[j + 1] = aux;
		}
		printf("Elija la opción 2 para ver la matriz ordenada");
	}
	printf("\n");
	}

	int busquedabinaria(int y, int array[], int n_elto)
	{
		int inf, sup, mean, index = 0;


		inf = 0;
		sup = n_elto - 1;
		while (inf<=sup && index==0)
		{
			mean = (inf + sup + 1) / 2;
			if(Array[mean]>y)
				inf=mean+1;
		}
		else
		{
		index = 1;
        }
	}
	if (index == 0)
	{
		return -1;
	}
	else
	{
		return mean + 1;
	}
	printf("\n");


	int leervalor(int z, int array[], int n_elto)
	{
		int add = 1;

		if (n_elto== N)
		{
		else
		{
			array[n_elto] = z;
		}
		}
		return add;
}