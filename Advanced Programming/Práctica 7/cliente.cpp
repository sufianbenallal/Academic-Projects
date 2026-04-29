#include "cliente.h"
#include "MemoryManager.h"

void CCliente::Visualizar()		//redefinicion del metodo de CFicha
{
	if (this == nullptr)
	{
		return;
	}

	int nHoras, nMinutos, nSegundos;
	string pszFormato;
	ObtenerNacio().ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);	//igual que lo comentado en 'empleado.cpp'

	cout << "DNI: " << m_sDNI << endl
		<< "Nombre: " << ObtenerNombre() << endl
		<< "Edad: " << ObtenerEdad() << endl
		<< "Hora Nacio: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
}

CCliente* CCliente::clonar()
{
	return new CCliente(*this);
}
