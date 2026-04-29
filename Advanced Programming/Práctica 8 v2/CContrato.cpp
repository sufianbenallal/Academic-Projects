#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

//iniciadores
CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
	: m_NumSerie(NumSerie), m_Descripcion(Desc), m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato invocando al operador de asignacion
CContrato::CContrato(const CContrato& c)
{
	*this = c;
}


// CContrato& CContrato::operator=(const CContrato &c)
CContrato& CContrato::operator=(const CContrato& c)
{
	int i = 0;
	if (this == &c)
	{
		return *this;  // comprobar si los objetos son iguales
	}
	this->~CContrato();

	m_NumSerie = c.m_NumSerie;
	m_Descripcion = c.m_Descripcion;
	m_FechaFin = c.m_FechaFin;
	m_Poliza = c.m_Poliza;
	m_ValorCompra = c.m_ValorCompra;

	// apuntamos al principio de la lista de siniestros
	m_Siniestros.begin();
	c.m_Siniestros.begin();

	if (c.m_Siniestros.empty()) //si la lista de siniestros esta vacia
	{
		return *this;
	}

	while (c.m_Siniestros.empty()) // recorre la lista hasta que no haya mas elementos
	{
		m_Siniestros.push_back(c.m_Siniestros[i]->Clonar()); // agrega un objeto clonado de la lista de siniestros del objeto 'c' 
		i++;
	}
	m_Siniestros.begin();
	c.m_Siniestros.begin();
	return *this;
}

//PREGUNTA 4: AgregarSiniestro de la clase CContrato
void CContrato::AgregarSiniestro(const CSiniestro& s)
{
	this->m_Siniestros.push_back(s.Clonar()); // AgregarObjeto es de la plantilla CLista, clonar() es de CSiniestro
}

void CContrato::BorrarSiniestros()
{
	for (int i = 0; i < m_Siniestros.size(); i++)
	{
		delete m_Siniestros[i];
	}
}

CContrato::~CContrato()
{
	BorrarSiniestros();
}
// void CContrato::BorrarSiniestros()

void CContrato::MostrarSiniestros(ostream& os)
{
	os << "Numero de Serie: " << m_NumSerie << endl;
	os << "Descripcion: " << m_Descripcion << endl;
	os << "Fecha de Finalizacion: " << m_FechaFin << endl;
	os << "Poliza: " << m_Poliza << endl;
	os << "Valor de Compra: " << m_ValorCompra << endl;
	os << endl;

	for (unsigned int i = 0; i < m_Siniestros.size(); i++)
	{
		m_Siniestros[i]->Mostrar(os);
	}
}

// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os, CContrato& c)
{
	os << "Numero de serie:  " << c.m_NumSerie << endl
		<< " Descripcion:  " << c.m_Descripcion << endl
		<< "Fecha Fin:  " << c.m_FechaFin << endl
		<< "Poliza:  " << c.m_Poliza << endl
		<< "Valor de compra:  " << c.m_ValorCompra << endl; // me creo el objeto os y se lo paso como parametro a MostrarSiniestros() de 'c'

	c.MostrarSiniestros(os);
	return os;
}
