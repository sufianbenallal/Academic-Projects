#include "cliente.h"
#include "registro.h"
#include <iomanip>
#include "utils.h"
#include "MemoryManager.h"

using namespace utils;


int main()
{
	{
		CRegistroDiario* registro = new CRegistroDiario(10), * registroCopia = nullptr;

		int opcion = 0, edad = 0, antiguedad = 0, existe_copia = 0;
		string nombre, categoria, DNI = "";

		static const char* opciones[] =
		{
			"Introducir Empleado", "Introducir Cliente", "Buscar por nombre", "Mostrar registro diario",
			"Mostrar empleados", "Copia de seguridad del registro diario", "Restaurar copia de seguridad", "Salir"
		};

		const int num_opciones = sizeof(opciones) / sizeof(char*);

		do
		{
			opcion = CUtils::CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
				//Introducir Empleado
			case 1:
				cout << "\nNombre: ";
				CUtils::LeerDato(nombre);
				cout << "\nEdad: ";
				utils::CUtils::LeerInt(edad);
				cout << "\nCategoria: ";
				CUtils::LeerDato(categoria);
				cout << "\nAntiguedad: ";
				utils::CUtils::LeerInt(antiguedad);

				registro->AgregarPersona(&CEmpleado(categoria, antiguedad, nombre, edad)); //creamos objeto CEmpleado y lo pasamos al registro usando 'AgregarPersona'
				break;

				//Introducir Cliente
			case 2:
				cout << "\nNombre: ";
				CUtils::LeerDato(nombre);
				cout << "\nEdad: ";
				utils::CUtils::LeerInt(edad);
				cout << "\nDNI: ";
				CUtils::LeerDato(DNI);
				registro->AgregarPersona(&CCliente(DNI, nombre, edad));
				break;

				//Buscar por nombre
			case 3:
			{
				cout << "Introduce nombre: " << endl;
				CUtils::LeerDato(nombre);
				registro->BuscarPorNombre(nombre);
				break;
			}

			//Mostrar registro diario
			case 4:
				registro->VisualizarRegistro();
				break;

				//Mostrar empleados
			case 5:
				registro->VisualizarEmpleados();
				break;

				//Copia de seguridad del registro diario
			case 6:
				if (((*registro)[0] == nullptr))	//si registro vacio, no se hace copia
				{
					cout << "\nRegistro vacio.\n";
					break;
				}

				if (existe_copia)	//si ya existe copia: no se hace copia
				{
					cout << "\nYa existe una copia de seguridad.\n";
					break;
				}
				registroCopia = new CRegistroDiario(*registro);
				existe_copia = 1;
				break;

				//Restaurar copia de seguridad
			case 7:
				if (registroCopia != nullptr)
				{
					delete registro;
					registro = nullptr;
					registro = new CRegistroDiario(*registroCopia);
					delete registroCopia;
					registroCopia = nullptr;
					existe_copia = 0;
				}
				break;
			}
			system("pause");
		} while (opcion != num_opciones);

		cout << "\n\n////////////// Probamos constructor copia //////////////\n\n";
		CRegistroDiario rdNuevo(*registro);
		rdNuevo.VisualizarRegistro();
		system("pause");

		cout << "\n\n////////////// Probamos personas <= 0 //////////////\n\n";
		CRegistroDiario* registroprueba;
		try
		{
			registroprueba = new CRegistroDiario(-20);
		}
		catch (invalid_argument e)
		{
			cout << e.what() << endl;
			system("pause");
		}
		delete registro;
		delete registroCopia;
	}

	MemoryManager::dumpMemoryLeaks();
	system("pause");
	return 0;
}
