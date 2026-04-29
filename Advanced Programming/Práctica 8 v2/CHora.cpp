#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include <iostream>
#include <cstring>
#include<cstdlib>
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

bool CHora::AsignarFormato(std::string pszFormato)
{
	if (m_pszFormato.empty())
	{
		return 0;
	}
	if (!m_pszFormato.empty())
		m_pszFormato.clear();  //borro la memoria antigua

	   //primero copio y luego paso a mayusculas
	m_pszFormato = pszFormato;
	CUtils::ConverMayus(m_pszFormato);

	return true;

}

bool CHora::Formato24() const//true->formato 24h  false->fomato 12h
{
	if (m_pszFormato == "24 HORAS")
	{
		return true;//cuando el formato es igual(correcto)
	}
	else
	{
		return false; //formato 12h
	}

}


bool CHora::EsHoraCorrecta() const//true si  es correcta->formato correcto (24,AM/PM)   false si no lo es //pag 113 return
{
	if ((m_pszFormato == "AM") || (m_pszFormato == "PM") || (m_pszFormato == "24 HORAS"))
	{
		if (Formato24() == false) //formato 12h
		{
			return (m_nHoras >= 0 && m_nHoras <= 12)
				&& (m_nMinutos >= 0 && m_nMinutos <= 59)
				&& (m_nSegundos >= 0 && m_nSegundos <= 59);

		}

		if (Formato24() == true)  //formato 24h
		{
			return(m_nHoras >= 0 && m_nHoras <= 23)
				&& (m_nMinutos >= 0 && m_nMinutos <= 59)
				&& (m_nSegundos >= 0 && m_nSegundos <= 59);
		}
		return true;
	}
	else
	{
		cout << "Formato no correcto" << endl;
		system("pause");
		return false;
	}
}


bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, std::string pszFormato)
{
	if (pszFormato.empty())
		return 0;

	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;

	AsignarFormato(pszFormato);
	return (EsHoraCorrecta());

}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, std::string& pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	pszFormato = m_pszFormato;


}




//CONSTRUCTOR & DESTRUCTOR
CHora::CHora(int hh, int mm, int ss, std::string ff) :
	m_nHoras(hh), m_nMinutos(mm), m_nSegundos(ss), m_pszFormato(ff)
{
}

CHora::~CHora()
{
	Destruir();
}


//OPERADOR DE ASIGNACION
CHora& CHora::operator=(const CHora& hora) /*devuelve una referencia al objeto
											resultante de la copia*/
{
	if (this == &hora)   //Comparo los valores para que no se me copie en mismo objeto (hora1=hora1;)
		return *this;

	if (hora.m_pszFormato.empty())
		exit(-1);

	m_nHoras = hora.m_nHoras;
	m_nMinutos = hora.m_nMinutos;
	m_nSegundos = hora.m_nSegundos;
	if (!AsignarFormato(hora.m_pszFormato))
		cout << "No es posible asignar formato";

	return (*this);
}

//CONSTRUCTOR COPIA
CHora::CHora(const CHora& hora) :
	m_nHoras(hora.m_nHoras), m_nMinutos(hora.m_nMinutos), m_nSegundos(hora.m_nSegundos), m_pszFormato(hora.m_pszFormato)
{
	AsignarFormato(hora.m_pszFormato);
}

void CHora::Destruir()
{
	m_pszFormato.clear();

}

