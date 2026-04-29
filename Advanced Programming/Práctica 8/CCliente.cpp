#include "CCliente.h"
#include <iostream>
#include "MemoryManager.h"
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente

void CCliente::AgregarContrato(const CContrato& c)
{
	this->m_Contratos.AgregarObjeto(c);

}

// PREGUNTA 5: operator << para resolver: cout << unCliente
ostream& operator<<(ostream& os, CCliente& c)
{
	while (c.m_Contratos.TieneMas())
	{
		os << "Nombre cliente: " << c.m_Nombre << endl	//muestra el nombre del cliente
			<< "Contratos: " << endl;
		c.m_Contratos.GetActual().MostrarSiniestros(os);	//coge la lista de contratos del cliente 'c' 
															//y muestra todos los sinestros de cada contrato.
		os << endl;		//Con GetActual() el puntero 'actual' apunta al siguente contrato automaticamente												
						//necesitas el flujo de 'CContrato' para añadirlo al de 'CCliente'
	}

	c.m_Contratos.Restart(); //apuntamos al primer elemento de la lista de contratos
	return os;
}

// PREGUNTA 9: total += seguros[i]

CCliente::operator long()
{
	long contador = 0;
	this->m_Contratos.Restart(); // apunto al primero contrato del objeto CCliente

	while (m_Contratos.TieneMas()) // mientras no lleguemos al final
	{
		m_Contratos.GetActual(); // apunta al siguiente contrato automaticamente
		contador++; // incrementa la variable 'contador' por cada contrato encontrado
	}
	return contador;
}