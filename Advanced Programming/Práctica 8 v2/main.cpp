#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "CEmpresa.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
	{int i = 0;

	bool terminar = false;
	const char* OpMenu[] = { "1.  Vaciar() de CLista.",  // hecho
					 "2.  Operador [] CLista.",   // hecho
					 "3.  Constructor copia de CContrato.", // hecho
					 "4.  AgregarSiniestro() de CContrato.", // hecho
					 "5.  Operador << CCliente.",  // hecho
					 "6.  m_pSigCodigo static.",  // hecho
					 "7.  Presupuestar() de CSiniestro y derivadas", // hecho
					 "8.  AgregarContrato() de CCliente",  // hecho
					 "9.  total += seguros[i]",  // hecho
					 "10. Constructor CSiniestro y CSiniestroNormal", // hecho
					 "11. const_cast<CLista<T>*>(this)->", // hecho
					 "12. GetCoste()?",  // hecho
					 "13. c.AgregarSiniestro()", // hecho
					 "14. Plantilla CEmpresa.",  // hecho
					 "15. Guardar empresa.",  // hecho
					 "16. Salir." //hecho
	};
	const int numopciones = sizeof(OpMenu) / sizeof(char*);
	int opcion = 0;

	do
	{
		opcion = CUtils::menu(OpMenu, numopciones);
		switch (opcion)
		{
		case 1:
		{
			// Crear una lista para después vaciarla
			vector<string> miLista;
			string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
			"Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
			// Rellenar la lista con nombres
			for (i = 0; i < 10; i++)
				miLista.push_back(nombres[i]); // carga miLista con nombres[]

			// Mostrar la lista. Preveer execepción CIndiceIncorrecto.
			try
			{
				for (unsigned int i = 0; i < miLista.size(); i++)
				{
					cout << miLista.at(i) << " " << endl;
				}

				cout << endl;
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}

			// Vaciar la lista y verificar después que está vacía.
			miLista.clear();
			if (miLista.empty())
				cout << "Lista vacia!!" << endl;

			cout << "Es necesario porque la clase CLista tiene miembros privados(atributos)" << endl
				<< "del tipo CNodoLista y por lo tanto debe acceder a los métodos de la" << endl
				<< "clase CNodoLista para trabajar sobre estos atributos." << endl;
			system("pause");
			break;
		}

		case 2:
		{
			//Ejemplo operador [] con lista de enteros
			vector<int> listaINT;
			int numeros[] = { 1, 2, 3, 4, 5, 6, };

			// Crear un objeto lista que almacene 10 datos de tipo int
			for (i = 0; i < 6; i++)
				listaINT.push_back(numeros[i]);

			// mostrar la lista de enteros
			try
			{
				for (unsigned int i = 0; i < listaINT.size(); i++)
				{
					cout << listaINT.at(i) << " " << endl;
				}
				cout << endl;
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}

			//Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto
			int dato = 0;
			try
			{
				for (i = 0; i < 6; i++)
					dato += listaINT[i];
				cout << "La suma de los elementos de la lista de enteros es : " << dato << endl;
			}
			catch (CIndiceIncorrecto& e)
			{
				cout << e.what() << e.ind() << endl;
			}
			system("pause");
			break;
		}

		case 3:
		{

			// Crear e iniciar objeto CContrato a copiar
			CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);

			/* // Rellenar objeto original
			TSituacion situacion = local;
			original.AgregarSiniestro(CSiniestroUrgente(local,"siniestro 1"));
			original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
			original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));  */

			cout << " CONTRATO ORIGINAL: " << endl << endl << original;
			cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
			CContrato copia(original); // CONSTRUCTOR COPIA
			original = copia;
			cout << " CONTRATO COPIADO: " << endl << endl << copia << endl;
			system("pause");
			break;
		}

		case 4:
		{
			CContrato prueba(12345);
			// Agregar a "prueba" un siniestro urgente y otro normal
			prueba.AgregarSiniestro(CSiniestroUrgente(internacional, "Siniestro URG")); // siniestro urgente
			prueba.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));  // siniestro normal

			prueba.MostrarSiniestros();
			cout << endl;
			cout << "Es necesario que sea virtual en la clase base para que el" << endl;
			cout << "método Clonar() pueda ser redefinido en sus clases derivadas" << endl;
			system("pause");
			break;
		}

		case 5:
		{
			// Crear cliente
			CCliente cli("Juan");
			// Agregar un contrato con dos siniestros, urgente y normal, a cli
			CContrato contr(123456789);
			contr.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli.AgregarContrato(contr);

			// Mostrar datos
			cout << " Datos del cliente: \n" << endl << cli << endl;
			system("pause");

			cout << "\nLlamada explicita:\n" << "operator<<(cout.operator<<(\" Datos del cliente: \\n\").operator<<(endl), cli).operator<<(endl)" << endl;
			system("pause");
			break;
		}

		case 6:
		{
			cout << "La inicializacion debe estar en la parte de arriba de CSiniestro.cpp," << endl;
			cout << "antes de llamar al constructor y es imprescindible al ser una variable de tipo static." << endl;
			system("pause");
			break;
		}


		case 7:
		{
			CSiniestroUrgente MiSiniestroUrgente(internacional, "Siniestro Urgente Ejemplo");
			MiSiniestroUrgente.Presupuestar(7, 3);
			MiSiniestroUrgente.Mostrar();

			CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
			MiSiniestroNormal.Presupuestar(9, 4);
			MiSiniestroNormal.Mostrar();

			cout << "en la funcion Presupuestar() si la variable m_Coste fuese privada no tendrian" << endl
				<< "acceso a ella las clases derivada. Como es protegida si tienen acceso sus clases derivadas." << endl << endl
				<< "En la funcion GetCoste() la variable m_Coste si podria ser private, ya que el metodo" << endl
				<< "de una clase tiene acceso a los miembros privados de su clase" << endl;
			system("pause");
			break;
		}

		case 8:
		{
			// Crear un cliente cli
			CCliente cli("Cliente caso_8");
			CContrato contr(1234567);

			// Agregar a cli un contrato con siniestros
			contr.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli.AgregarContrato(contr);

			// Mostrar cli
			cout << " Datos del cliente: \n" << endl << cli << endl; // mostrar los datos del cliente, sus contratos y sus siniestros

			system("pause");
			break;
		}

		case 9:
		{
			// Crear una matriz dinámica de tipo CCliente apuntada por "seguros"
			CCliente* seguros;
			seguros = new(nothrow) CCliente[MAX_CLIENTES];

			if (seguros == NULL)
			{
				cout << "No hay memoria suficiente" << endl;
				system("pause");
				exit(1);
			}

			// Agregar contratos a los clientes de la matriz "seguros" agrega 1 contrato a cada cliente
			for (i = 0; i < MAX_CLIENTES; i++)
			{
				seguros[i].SetNombre("Cliente ");
				seguros[i].AgregarContrato(CContrato(i + 1));
				//seguros[i].AgregarContrato(CContrato(i + 10));
			}

			// Contar el número total de contratos
			long total = 0;
			for (int i = 0; i < MAX_CLIENTES; i++)
			{
				total += seguros[i];
			}
			cout << "\n El numero total de contratos de los clientes es de: ";
			cout << total << " contratos\n";
			system("pause");
			delete[] seguros;
			break;
		}

		case 10:
		{
			CSiniestroNormal s("Rotura de tambor");
			cout << endl;
			s.Mostrar(); cout << endl;

			cout << "Respuesta a la pregunta: ..." << endl;
			cout << "\n 1- se llama al constructor de CSiniestroNormal con parámetros";
			cout << "\n 2- se llama al constructor de CSiniestro , que es su clase base";
			cout << "\n 3- primero se ejecuta el constructor de la clase base CSiniestro y luego el de la clase derivada CSiniestroNormal" << endl;
			system("pause");
			break;
		}

		case 11:
		{
			cout << "El puntero es un puntero pasado como const, es decir apunta siempre" << endl;
			cout << " a un elemento concreto, y para realizar este metodo vamos a tener que" << endl;
			cout << "forzar ese puntero a uno 'no const' por lo tanto no se puede eliminar ese codigo" << endl;
			cout << "ya que necesitamos que el puntero modifique la direccion a la que apunta." << endl;
			system("pause");
			break;
		}

		case 12:
		{
			cout << "Claro que si podriamos llamar a la funcion GetCoste() desde la funcion Mostrar," << endl;
			cout << "ya que ambos son metodos publicos de la clase CSiniestro y por lo tanto se" << endl;
			cout << "pueden realizar este tipo de llamadas." << endl;
			system("pause");
			break;
		}

		case 13:
		{
			CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
			CSiniestroUrgente s(nacional, "Fallo general");
			c.AgregarSiniestro(s);

			cout << "1- Constructor con parametros de CContrato" << endl
				<< "2- llama al constructor de CSiniestroUrgente  y luego al de CSiniestro. Se ejecuta el " << endl
				<< "constructor de CSiniestro sin parametros y luego el de CSiniestroUrgente con parametros." << endl
				<< "3- llama al metodo AgregarSiniestro de la clase CContrato y le pasa como parametro el objeto" << endl
				<< " de la clase CSiniestroUrgente. Dentro de esta funcion se ejecuta el metodo AgregarObjeto() de la" << endl
				<< "plantilla CLista que se le pasa como parametro la copia de un objeto de la clase CSiniestroUrgente," << endl
				<< "copiado por el metodo Clonar() de la clase CSiniestroUrgente." << endl;
			system("pause");
			break;
		}

		case 14:
		{
			// Crear empresa1
			CEmpresa<CCliente> empresa1;

			// Agregar elementos a la empresa
			//  CLIENTE 1
			CCliente cli1("Cliente 1 caso_14");
			CContrato contr1(1234567);
			contr1.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr1.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli1.AgregarContrato(contr1);


			//  CLIENTE 2
			CCliente cli2("Cliente 2 caso_14");
			CContrato contr2(1234567);
			contr2.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr2.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli2.AgregarContrato(contr2);


			// agrego los clientes
			empresa1.AgregarElemento(cli1);
			empresa1.AgregarElemento(cli2);

			// Mostrar la empresa2
			cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;

			cout << "****************   EMPRESA 1   ****************" << endl << endl;
			for (int i = 0; i < empresa1.Tamanyo(); i++)
			{
				cout << empresa1[i] << endl;
			}

			system("pause");
			cout << endl << endl;

			// Crear empresa2 como copia de empresa1
			CEmpresa<CCliente> empresa2(empresa1);

			cout << "****************   EMPRESA 2   ****************" << endl << endl;
			for (int i = 0; i < empresa2.Tamanyo(); i++)
			{
				cout << empresa2[i] << endl;
			}

			system("pause");

			break;
		}

		case 15:
		{
			// Crear empresa: con 2 clientes
			CEmpresa<CCliente> empresa1;
			// Rellenar empresa

			 //  CLIENTE 1: un contrato y 2 siniestros
			CCliente cli1("Cliente 1 caso_15");
			CContrato contr1(1234567);
			contr1.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr1.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli1.AgregarContrato(contr1);


			//  CLIENTE 2: 1 contrato y 2 siniestros
			CCliente cli2("Cliente 2 caso_15");
			CContrato contr2(1234567);
			contr2.AgregarSiniestro(CSiniestroNormal("Siniestro NORM"));
			contr2.AgregarSiniestro(CSiniestroUrgente(local, "Siniestro URG"));
			cli2.AgregarContrato(contr2);

			// agrego los clientes
			empresa1.AgregarElemento(cli1);
			empresa1.AgregarElemento(cli2);

			cout << endl << "****************   EMPRESA 1   ****************" << endl << endl;
			for (int i = 0; i < empresa1.Tamanyo(); i++)
			{
				cout << empresa1[i] << endl;
			}

			system("pause");
			cout << endl << endl;

			// Guardar los nombres en un fichero (escribir)
			fstream fichero; // flujo
			fichero.open("mifichero.txt", ios::out | ios::in | ios::trunc);  // abrir fichero de texto para escribir y leer "w+"
			if (!fichero)   // comprobar si se puede abrir el fichero
				throw "No se puede abrir el fichero !!";

			// escribo en el fichero
			fichero << endl << "****************   EMPRESA 1   ****************" << endl << endl;
			for (int i = 0; i < empresa1.Tamanyo(); i++)
			{
				fichero << empresa1[i].GetNombre() << endl;
			}


			cout << endl << endl << "******************************"
				<< "CLIENTES DE LA EMPRESA GUARDADOS." <<
				"******************************" << endl << endl;
			cout << endl << "Pulsa para leer el fichero " << endl;
			system("pause"); cout << endl << endl;

			// Verificar la información almacenada en el fichero (leer)
			fichero.seekp(ios::beg);
			// leer el fichero caracter a caracter pag:458
			char car;
			while (fichero.get(car))
				cout << car;
			if (!fichero.eof())
				throw "Error al leer el fichero !!";

			fichero.close();  // cierro el fichero

			system("pause");
			break;
		}

		case 16:
			terminar = true;
			break;

		}
	} while (!terminar);

	}
	MemoryManager::dumpMemoryLeaks();
	//system("pause");
}


//  Constraseña evaluacion libre practicas:  g5esgft
