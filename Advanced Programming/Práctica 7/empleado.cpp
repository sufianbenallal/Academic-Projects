#include "empleado.h"
#include "MemoryManager.h"

void CEmpleado::Visualizar()	//redefinicion del metodo de CFicha
{
	if (this == nullptr)
	{
		return;
	}

	int nHoras, nMinutos, nSegundos;
	string pszFormato;
	ObtenerNacio().ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);	//accede al atributo m_horaNacio de la clase base a traves del metodo,
																			//ya que la clase derivada no puede acceder a los miembros privados directamente
	cout << "Categoria: " << m_sCategoria << endl
		<< "Antiguedad: " << m_nAntiguedad << " Anyos" << endl
		<< "Nombre: " << ObtenerNombre() << endl							//accede al atributo 'm_sNombre' de la clase base
		<< "Edad: " << ObtenerEdad() << " Anyos" << endl					//accede al atributo 'm_nEdad' de la clase base
		<< "Hora Nacio: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
}

CEmpleado* CEmpleado::clonar()
{
	return new CEmpleado(*this);
}
