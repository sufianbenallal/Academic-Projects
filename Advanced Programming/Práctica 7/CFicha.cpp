#include "CFicha.h"
#include "MemoryManager.h"


void CFicha::Visualizar()
{
	if (this == nullptr) //si this apunta a null
	{
		return;	// no hay nada que mostrar
	}

	int nHoras, nMinutos, nSegundos;
	string pszFormato;
	m_horaNacio.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	cout << "Nombre: " << m_sNombre << endl
		<< "Edad: " << m_nEdad << endl
		<< "Hora Nacio: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
}
