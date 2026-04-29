#include "registro.h"
#include "MemoryManager.h"

// constructor con num. de elementos como argumento
CRegistroDiario::CRegistroDiario(int ElementosMax)
{
	if (ElementosMax <= 0)		//si elementos <= 0 lanzamos una excepcion
	{
		throw invalid_argument("\nEl numero de elementos es <= 0.\n");
	}
	personas.reserve(ElementosMax);
}

// destructor
CRegistroDiario::~CRegistroDiario()
{
	if (!personas.empty()) //si personas no esta 'vacio'
	{
		for (int i = 0; i < personas.size(); i++)
		{
			delete personas[i];
		}
		personas.clear();
	}
}

// Constructor copia
CRegistroDiario::CRegistroDiario(const CRegistroDiario& registro)
{
	*this = registro;		// llamamos a operador asignacion
}

// sobrecarga del operador asignacion
CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& registro)
{
	if (personas.size())	//si el registro destino tiene algo dentro, lo primero que haremos es borrarlo
	{
		this->~CRegistroDiario(); //llamamos al destructor y lo borramos
	}

	// luego copiamos el registro origen en el destino
	for (int i = 0; i < registro.personas.size(); i++)
	{
		personas.push_back(registro.personas[i]->clonar());
		/* Llamamos a 'clonar' de la clase derivada (empleado o cliente).
		*  Retornamos un puntero apuntando a un nuevo objeto de la clase derivada
		*  que ha sido inicializado con los atributos del objeto origen
		*  y lo ponemos al final de la lista con 'push_back'
		*/
	}
	return *this;
}

/*// sobrecarga del operador '==' para comparar dos objetos de 'CRegistroDiario'
bool CRegistroDiario::operator==(const CRegistroDiario registro)
{
	if (nElementosMax != registro.nElementosMax)
	{
		return false;
	}

	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] != registro.personas[i])
			return false;
	}

	return true;
}*/

// Metodo AgregarPersona
void CRegistroDiario::AgregarPersona(CFicha* pers)
{
	personas.push_back(pers->clonar()); // Llamamos a 'clonar' de la clase derivada (empleado o cliente).
}

// Metodo VisualizarRegistro
void CRegistroDiario::VisualizarRegistro()
{
	if (personas.empty()) //si personas esta vacio, el resgistro estara vacío.
	{
		cout << "Registro vacio." << endl;
	}

	else
	{
		for (int i = 0; i < personas.size(); i++)
		{
			personas[i]->Visualizar(); //sino lo visualizamos
		}

	}
}

// Metodo EsEmpleado
bool CRegistroDiario::EsEmpleado(CFicha* pers)
{
	return dynamic_cast<CEmpleado*>(pers);
	//Intentamos hacer la conversion. Si ficha es un objeto CEmpleado devolvemos true, si no devolvemos un false.
}

// Metodo VisualizarEmpleados
void CRegistroDiario::VisualizarEmpleados()
{
	for (int i = 0; i < personas.size(); i++)	//recorremos el registro
	{
		if (EsEmpleado(personas[i]))	//si el elemento 'i' es de la clase CEmpleado, lo visualiza, si no continua
		{
			personas[i]->Visualizar();
		}
	}
}

// sobrecarga del operador indexacion
CFicha* CRegistroDiario::operator[](int i) const
{
	if (i >= 0 && i < personas.size()) // si 'i' esta dentro de los limites de la lista de personas
	{
		return personas[i];
	}

	else
	{
		return nullptr; //sino retornamos null
	}
}

void CRegistroDiario::BuscarPorNombre(string nombre) const
{
	for (int i = 0; i < personas.size(); i++)	// Recorremos la lista. Si un nombre coincide con el que buscamos, se visualiza
	{
		if (personas[i] != nullptr)
		{
			if (personas[i]->ObtenerNombre() == nombre) //si algun nonbre coincide, lo visualizamos
			{
				personas[i]->Visualizar();
				return;
			}
		}
	}
	cout << "Persona no encontrada." << endl;
}

int CRegistroDiario::NumPersonas()
{
	return personas.size();
}