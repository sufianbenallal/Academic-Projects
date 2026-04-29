#include "CCliente.h"
#include <iostream>
#include "MemoryManager.h"
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente
void CCliente::AgregarContrato(const CContrato& c)
{
	this->m_Contratos.push_back(c);
}

// PREGUNTA 5: operator insercion << para resolver: cout << unCliente
ostream& operator<<(ostream& os, CCliente& c)
{
	os << "Nombre: " << c.GetNombre() << endl;
	unsigned int i = 0;
	while (i < c.GetContratos().size())
	{
		os << "Numero de serie: " << c.GetContratos()[i].GetNumSerie() << endl;
		os << "Descripcion: " << c.GetContratos()[i].GetDescripcion() << endl;
		os << "Fecha de finalizacion de contrato: " << c.GetContratos()[i].GetFechaFin() << endl;
		os << "Poliza: " << c.GetContratos()[i].GetPoliza() << endl;
		os << "Valor de compra: " << c.GetContratos()[i].GetValorCom() << endl;
		os << "Siniestros : " << endl << endl;
		c.GetContratos()[i].MostrarSiniestros(os);
		i++;
		os << endl;
	}
	return os;
}


// PREGUNTA 9: total += seguros[i]
CCliente::operator long()
{
	return m_Contratos.size();
}