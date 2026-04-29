#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
	: m_NumSerie(NumSerie), m_Descripcion(Desc), m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato invocando al operador de asignacion
CContrato::CContrato(const CContrato& c)
{
	*this = c;		//llama a operador asignacion
}


// CContrato& CContrato::operator=(const CContrato &c)
CContrato& CContrato::operator=(const CContrato& c)
{
	if (this == &c)
		return *this;  // comprobamos si los objetos son iguales

	this->~CContrato();		//vaciar contrato antes de rellenarlo

	m_NumSerie = c.m_NumSerie;
	m_Descripcion = c.m_Descripcion;
	m_FechaFin = c.m_FechaFin;
	m_Poliza = c.m_Poliza;
	m_ValorCompra = c.m_ValorCompra;

	// apunto al pricipio de la lista de siniestros
	m_Siniestros.Restart();		//hace que 'actual' pase a apuntar al primero
	c.m_Siniestros.Restart();

	if (c.m_Siniestros.EstaVacia())	//si la lista esta vacia, no hay nada mas que copiar
		return *this;

	while (c.m_Siniestros.TieneMas()) // recorre la lista hasta que no haya mas elementos
	{
		m_Siniestros.AgregarObjeto(c.m_Siniestros.GetActual()->Clonar());	//agrega un objeto clonado de la lista de siniestros del objeto 'c' 
	}																		//clonar duplica el objeto para el cual es invocado
	m_Siniestros.Restart();
	c.m_Siniestros.Restart();

	return *this;
}


// PREGUNTA 4: AgregarSiniestro de la clase CContrato
void CContrato::AgregarSiniestro(const CSiniestro& s)
{
	this->m_Siniestros.AgregarObjeto(s.Clonar()); // AgregarObjeto es de la plantilla CLista; clonar() es de CSiniestro
}

void CContrato::BorrarSiniestros()
{
	m_Siniestros.Restart(); // apuntamos al primer elemento
	while (m_Siniestros.TieneMas()) // hasta que llegue al final de la lista
		delete m_Siniestros.GetActual(); // borra el elemento apuntado y referencia al siguiente automaticamente
}


CContrato::~CContrato()
{
	BorrarSiniestros();
}

// void CContrato::BorrarSiniestros()



void CContrato::MostrarSiniestros(ostream& os)
{
	if (this->m_Siniestros.EstaVacia())
		os << "Contrato sin siniestros." << endl;

	else		//va mostrando todos los contratos del cliente 'c' usando 'os'
	{
		this->m_Siniestros.GetPrimero()->Mostrar(os);
		while (this->m_Siniestros.TieneMas()) // hasta que llegue al final de la lista
			this->m_Siniestros.GetActual()->Mostrar(os);
	}
}


// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os, CContrato& c)
{
	os << "Numero de serie: " << c.m_NumSerie << endl
		<< "Descripcion: " << c.m_Descripcion << endl
		<< "Fecha finalizacion contrato: " << c.m_FechaFin << endl
		<< "Poliza: " << c.m_Poliza << endl
		<< "Valor de compra: " << c.m_ValorCompra << endl;
	//le pasamos 'os' como argumento al metodo MostrarSiniestros() de 'c'
	c.MostrarSiniestros(os);
	return os;
}
