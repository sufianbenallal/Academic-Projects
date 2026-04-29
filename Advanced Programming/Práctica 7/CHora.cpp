#include "CHora.h"

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, std::string pszFormato)
{
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	m_pszFormato = pszFormato;
	return EsHoraCorrecta();
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, std::string& pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	pszFormato = m_pszFormato;
}

bool CHora::Formato24() const
{
	return m_pszFormato == "24 HORAS";
}

bool CHora::EsHoraCorrecta() const
{
	bool check = ((Formato24() ? m_nHoras <= 24 : m_nHoras <= 12) && m_nHoras >= 0 && m_nMinutos < 60 && m_nMinutos >= 0 && m_nSegundos < 60 && m_nSegundos >= 0);
	bool formatoCorrecto = Formato24() || m_pszFormato == "AM" || m_pszFormato == "PM";

	if (!formatoCorrecto)
	{
		std::cout << "Formato incorrecto." << std::endl;
	}

	return check && formatoCorrecto;
}