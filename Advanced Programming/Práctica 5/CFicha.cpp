#include "CFicha.h"
#include "utils.h"
#include "CHora.h"
#include <string>
#include <iostream>
#include "MemoryManager.h"
using namespace std;

void CFicha::AsignarNombre(const string& sNombre)
{
	m_sNombre = sNombre;
}
string CFicha::ObtenerNombre() const
{
	return m_sNombre;
}
void CFicha::AsignarEdad(int nEdad)
{
	m_nEdad = nEdad;
}
int CFicha::ObtenerEdad() const
{
	return m_nEdad;
}
bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& sFormato)
{
	return m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato);
}
CHora CFicha::ObtenerNacio() const
{
	return m_horaNacio;
}

/*CHora CFicha::ObtenerNacio() const;*/
/*CHora& CFicha::ObtenerNacio()
{
	return m_horaNacio;
}
*/