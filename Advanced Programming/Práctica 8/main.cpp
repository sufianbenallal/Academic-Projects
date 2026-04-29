#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "CEmpresa.h"
#include "utils.h"
#include "CNodoLista.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
    {int i = 0;

    bool terminar = false;
   const char* OpMenu[] = { "1.  Vaciar() de CLista.",
                     "2.  Operador [] CLista.",
                     "3.  Constructor copia de CContrato.",
                     "4.  AgregarSiniestro() de CContrato.",
                     "5.  Operador << CCliente.",
                     "6.  m_pSigCodigo static.",
                     "7.  Presupuestar() de CSiniestro y derivadas",
                     "8.  AgregarContrato() de CCliente",
                     "9.  total += seguros[i]",
                     "10. Constructor CSiniestro y CSiniestroNormal",
                     "11. const_cast<CLista<T>*>(this)->",
                     "12. GetCoste()?",
                     "13. c.AgregarSiniestro()",
                     "14. Plantilla CEmpresa.",
                     "15. Guardar empresa.",
                     "16. Salir."
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
            CLista<string> miLista;  //creamos un objeto de la clase CLista
            string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
            "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
            try
            {
                // Rellenar la lista con nombres
                for (i = 0; i < 10; i++)
                {
                    miLista.AgregarObjeto(nombres[i]); // carga miLista con nombres[]
                }

                // Mostrar la lista. Preveer execepción CIndiceIncorrecto.
                while (miLista.TieneMas())     //hasta que lleguemos al final de la lista
                    cout << miLista.GetActual() << endl; // GetActual devuelve el nodo y apunta al siguiente
            }

            catch (CIndiceIncorrecto& e)
            {
                cout << e.what() << endl;
            }

            // Vaciar la lista y verificar después que está vacía.
            miLista.Vaciar();
            if (miLista.EstaVacia())
            {
                cout << "Lista vacia." << endl << endl;
            }

            cout << "No, no es necesario, porque ninguno de los metodos de la clase 'CLista'" << endl
                << "utiliza directamente ningun miembro de categoria 'private' de 'CNodoLista'." << endl
                << "En todo caso, se usaran metodos 'public' de 'CNodoLista'." << endl;
            system("pause");
            break;
        }

        case 2:
        {
            // Ejemplo operador [] con lista de enteros
            int numeros[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            // Crear un objeto lista que almacene 10 datos de tipo int
            CLista<int> listaint;  //creamos la lista de enteros
            for (i = 0; i < 10; i++)    //rellenamos la lista con los numeros
                listaint.AgregarObjeto(numeros[i]);

            // mostrar la lista de enteros
            /*while(listaenteros.TieneMas())
                cout << listaenteros.GetActual() << endl;*/

                // Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto
            int dato = 0;
            try
            {
                for (i = 0; i < 10; i++)
                    dato += listaint[i].GetDato();      //hacemos la suma de los 10 numeros
                cout << "La suma de la lista de los 10 enteros consecutivos(del 1 al 10) es: " << dato << endl << endl;
                cout << "Para hacer saltar la excepcion, pedimos el elemento 11 de la lista:" << endl;
                listaint[11].GetDato();
            }
            catch (CIndiceIncorrecto& e)
            {
                cout << e.what() << endl;
            }
            system("pause");
            break;
            //mirar Clista.cpp
        }

        case 3:
        {
            // Crear e iniciar objeto CContrato a copiar
            CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);

            // Rellenar objeto original
            TSituacion situacion = local;
            original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
            original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
            cout << " CONTRATO ORIGINAL: " << endl << endl << original;
            system("pause");

            cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
            CContrato copia(original);
            original = copia;
            cout << " CONTRATO COPIA: " << endl << endl << copia << endl;
            system("pause");
            break;
            //operador = CContrato
        }

        case 4:
        {
            CContrato prueba(12345);
            // Agregar a "prueba" un siniestro urgente y otro normal
            prueba.AgregarSiniestro(CSiniestroUrgente(nacional, "Siniestro 1")); // siniestro urgente
            prueba.AgregarSiniestro(CSiniestroNormal("Siniestro 2"));  // siniestro normal
            //agregarsiniestro de CContrato

            prueba.MostrarSiniestros();
            cout << endl;
            cout << "Respuesta a la pregunta:" << endl;
            cout << "Si, es necesario que el metodo 'Clonar' sea virtual en la clase" << endl;
            cout << "base('CSiniestro'), para que asi este metodo pueda ser redefinido en sus" << endl;
            cout << "clases derivadas, es decir, 'CSiniestroNormal' y 'CSiniestroUrgente'." << endl;
            system("pause");
            break;
        }

        case 5:
        {
            // Crear cliente
            CCliente cli("Juan");
            // Agregar un contrato con dos siniestros, urgente y normal, a cli
            CContrato con(12345);
            con.AgregarSiniestro(CSiniestroNormal("Siniestro 1"));
            con.AgregarSiniestro(CSiniestroUrgente(internacional, "Siniestro 2"));
            cli.AgregarContrato(con);

            // Mostrar datos
            cout << "\nDatos del cliente:\n" << cli << endl;
            system("pause");

            cout << "\nEscribimos de forma explicita la sentencia pedida:\n" << "operator<<(cout.operator<<(\"Datos del cliente: \\n\\n\"), cli).operator<<(endl)" << endl;
            system("pause");
            break;
        }

        case 6:
        {
            cout << "Respuestas a las preguntas: " << endl;
            cout << "1) La inicializacion debemos hacerla en la parte de arriba en CSiniestro.cpp, antes del constructor." << endl;
            cout << "2) Si, es imprescindible, ya que es un atributo de tipo static," << endl;
            cout << " y por tanto, debe tener algun valor que tomar aun sin haber objetos." << endl;
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

            cout << "1) En 1er lugar, si la variable m_Coste fuese privada en la funcion Presupuestar (), no tendrian acceso a ella las clases derivadas(CSiniestroNormal "
                << " y CSiniestroUrgente), luego no podriamos hacer lo que el enunciado pide. Pero, como es protected en este caso, si tienen acceso sus clases derivadas."
                << endl << endl
                << "2) En 2o lugar, en cuanto a 'GetCoste', el atributo 'm_Coste' si podria ser privado, ya que en este caso el metodo"
                << " de una clase si tiene acceso a los miembros private de su propia clase." << endl;
            system("pause");
            break;
        }

        case 8:
        {
            // Crear un cliente cli
            CCliente cli("Juan");
            CContrato con(12345);

            // Agregar a cli un contrato con siniestros
            con.AgregarSiniestro(CSiniestroNormal("Siniestro 1"));
            con.AgregarSiniestro(CSiniestroUrgente(nacional, "Siniestro 2"));
            cli.AgregarContrato(con);

            // Mostrar cli
            cout << "\nDatos del cliente: \n" << cli << endl << endl;
            //en CCliente.cpp

            system("pause");
            break;
        }

        case 9:
        {
            // Crear una matriz dinámica de tipo CCliente apuntada por "seguros"
            CCliente* seguros;      //creamos puntero a CCliente llamado 'seguros'
            seguros = new(nothrow) CCliente[MAX_CLIENTES];  //reservamos espacio de memoria para 10 clientes apuntado por 'seguros'

            if (seguros == NULL)
            {
                cout << "No hay memoria suficiente." << endl;
                system("pause");
                exit(1);
            }

            // Agregar contratos a los clientes de la matriz "seguros" (añadimos un contrato por cliente)
            for (i = 0; i < MAX_CLIENTES; i++)
            {
                seguros[i].SetNombre("Cliente nuevo");
                seguros[i].AgregarContrato(CContrato(i + 1));
                //construimos el contrato y se lo agregamos al cliente 'i'
            }

            // Contar el número total de contratos
            long total = 0;
            for (int i = 0; i < MAX_CLIENTES; i++)
                total += seguros[i];
            cout << "\n El numero total de contratos de los clientes asciende a: ";
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

            cout << "Respuesta a la pregunta: " << endl;
            cout << "\n 1) Llama al constructor de 'CSiniestroNormal' con parametros (argumentos string).";
            cout << "\n 2) Llama al constructor de 'CSiniestro', que es la clase base de 'CSiniestroNormal'.";
            cout << "\n 3) Se ejecuta 1o el constructor de la clase base 'CSiniestro',";
            cout << "\n y 2o se ejecuta el constructor de la clase derivada 'CSiniestroNormal'." << endl << endl;
            system("pause");
            break;
        }

        case 11:
        {
            cout << "Respuesta a la pregunta: " << endl;
            cout << "Como 'GetPrimero' es un metodo 'const', no puede modificar los atributos del objeto." << endl;
            cout << "Por tanto, si hace falta usar la conversion 'const_cast' para poder modificar" << endl;
            cout << "el atributo 'm_Actual'." << endl << endl;
            //El operador 'const_cast' se utiliza para poner o quitar el atributo 'const' a un objeto / variable / expresión.
            //'const' significa que la función no va a modificar los atributos del objeto

            system("pause");

            break;
        }

        case 12:
        {
            cout << "Respuesta a la pregunta: " << endl;
            cout << "Si, podriamos llamar a la funcion 'GetCoste' desde la funcion 'Mostrar'," << endl;
            cout << "ya que ambos son metodos publicos de la misma clase (CSiniestro)." << endl;
            system("pause");
            break;
        }

        case 13:
        {
            CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
            CSiniestroUrgente s(nacional, "Fallo general");
            c.AgregarSiniestro(s);

            cout << "Respuestas a las preguntas: ..." << endl;
            cout << " 1) Llama a CContrato::AgregarSiniestro" << endl
                << " 2) CSiniestroUrgente::Clonar() " << endl
                << " 3) CLista<T>::AgregarObjeto (de void CContrato::AgregarSiniestro) " << endl
                << " 4) EstaVacia() de Clista.cpp" << endl
                << " 5) CNodoLista<T>::CNodoLista de NodoLista.cpp \n\n";

            system("pause");
            break;
        }

        case 14:
        {
            // Crear empresa1
            CEmpresa<CCliente> empresa1;

            // Agregar elementos a la empresa
            CCliente cli1("Cliente 1: Marius");
            CCliente cli2("Cliente 2: Maria");
            CCliente cli3("Cliente 3: Cristina");
            empresa1.AgregarElemento(cli1);
            empresa1.AgregarElemento(cli2);
            empresa1.AgregarElemento(cli3);

            // Crear empresa2 como copia de empresa1
            CEmpresa <CCliente> empresa2(empresa1);
            empresa2 = empresa1;


            // Mostrar la empresa2
            cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;
            for (int i = 0; i < empresa2.Tamanyo(); i++)
            {
                cout << "Nombre: " << empresa2[i].GetNombre() << endl;
            }

            system("pause");
            break;
        }

        case 15:
        {
            // Crear empresa
            CEmpresa<CCliente> empresa1;

            // Rellenar empresa
            CCliente cli1("Cliente 1: Marius");
            CCliente cli2("Cliente 2: Maria");
            CCliente cli3("Cliente 3: Cristina");
            empresa1.AgregarElemento(cli1);
            empresa1.AgregarElemento(cli2);
            empresa1.AgregarElemento(cli3);

            // Guardar los nombres en un fichero (escribir)
            ofstream ficheroSalida("clientes.txt");    //'ofstream' permite definir flujos de salida vinculados con archivos.

            for (int i = 0; i < empresa1.Tamanyo(); i++)
            {
                ficheroSalida << empresa1[i].GetNombre() << endl;   //escribimos los nombres de clientes en diferentes lineas
            }
            ficheroSalida.close();      ///cerramos el archivo (clientes.txt) asociado al objeto 'ficheroSalida'

            cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n" << endl;

            // Verificar la informacion almacenada en el fichero (leer)
            cout << "\LEYENDO CLIENTES DE LA EMPRESA GUARDADOS:\n" << endl;
            ifstream ficheroEntrada("clientes.txt");    //'ifstream' permite definir flujos de entrada vinculados con archivos.
            string linea;                     //variable de tipo string donde iremos almacenando el contenido del fichero.
            if (ficheroEntrada.is_open())   //devuelve 'true' si el archivo esta abierto
            {
                while (getline(ficheroEntrada, linea))  //Leemos una cadena desde el fichero y la almacenamos en 'linea'.
                {
                    cout << linea << '\n';  //mostramos por pantalla el contenido de 'linea'
                }
                ficheroEntrada.close();     //cerramos el archivo (clientes.txt) asociado al objeto 'ficheroEntrada'
            }
            else cout << "No se puede abrir el archivo";

            system("pause");
            break;
        }

        case 16:
        {
            terminar = true;
            break;
        }
        }
    } while (!terminar);
    }
    MemoryManager::dumpMemoryLeaks();
}