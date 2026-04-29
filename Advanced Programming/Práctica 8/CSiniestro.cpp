#include "CSiniestro.h"
#include "MemoryManager.h"

using namespace std;

// PREGUNTA 6: iniciar m_SigCodigo
int CSiniestro::m_SigCodigo = 1; //el primer objeto creado tendrá m_SigCodigo = 1

/*CSiniestro::CSiniestro(const std::string& desc) :
	m_Codigo(0), m_Descripcion(desc), m_HorasMO(0.0), m_CostePiezas(0.0), m_Coste(0.0) // constructor con parametros por omision
{m_SigCodigo++;}*/


// PREGUNTA 10: CSiniestroNormal s("Rotura de tambor");
CSiniestro::CSiniestro(const std::string& desc)
{
	m_Codigo = 0;
	m_SigCodigo++;
	m_Descripcion = desc;
	m_HorasMO = 0;
	m_CostePiezas = 0;
	m_Coste = 0;
}



// PREGUNTA 12: GetCoste
void CSiniestro::Mostrar(ostream& os) const
{
	os << " Codigo del siniestro: " << m_Codigo << endl
		<< " Objetos creados hasta ahora : " << m_SigCodigo << endl
		<< " Descripcion de la averia: " << m_Descripcion << endl
		<< " Horas de mano de obra: " << m_HorasMO << endl
		<< " Coste de las piezas: " << m_CostePiezas << endl
		<< " Coste total de reparacion: " << m_Coste << endl;
}
