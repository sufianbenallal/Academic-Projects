#include "CSiniestroNormal.h"
#include "MemoryManager.h"
using namespace std;

float CSiniestroNormal::m_CosteHoraMO = 2.5;

// PREGUNTA 10
CSiniestroNormal* CSiniestroNormal::Clonar() const
{
	return new CSiniestroNormal(*this);
}

void CSiniestroNormal::Mostrar(ostream& os) const
{
	cout << "-----SINIESTRO NORMAL-----" << endl;
	CSiniestro::Mostrar(os);
	os << " Coste de la hora de mano de obra: " << m_CosteHoraMO << endl << endl;
}

// PREGUNTA 7
void CSiniestroNormal::Presupuestar(float Horas, float Piezas)
{
	m_HorasMO = Horas;
	m_CostePiezas = Piezas;
	m_Coste = m_HorasMO * m_CosteHoraMO + m_CostePiezas;
}

float CSiniestroNormal::GetPresupuesto() const
{
	return m_Coste;
}
