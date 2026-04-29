#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include "utils.h"
#include"CFicha.h"
#include "MemoryManager.h"

; using namespace std;
using namespace utils;

//CONSTRUCTOR 
CFicha::CFicha(const std::string sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const std::string sFormato) :
	m_sNombre(sNombre), m_nEdad(nEdad), m_horaNacio(nHoras, nMinutos, nSegundos, sFormato)
{
}


void CFicha::AsignarNombre(const std::string sNombre)
{
	if (!sNombre.empty()) //si la lisat de nombres esta vacia
	{
		m_sNombre = sNombre;
	}

}
std::string CFicha::ObtenerNombre() const
{
	if (!m_sNombre.empty())
	{
		string nombre;
		nombre = m_sNombre;
		nombre[0] = toupper(nombre[0]); //primera en mayus
		return nombre;
	}
	else
		return " ";
}
void CFicha::AsignarEdad(int nEdad)
{
	if (nEdad > 0)
	{
		m_nEdad = nEdad;
	}
}

int CFicha::ObtenerEdad() const
{
	if (m_nEdad > 0)
	{
		return m_nEdad;
	}
	else
	{
		cout << "Edad no valida." << endl;
		system("pause");
		return 0;
	}

}
bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const std::string& sFormato)
{
	return(m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato)); // copia la hora introducida por el usuario

}

CHora CFicha::ObtenerNacio()const
{
	return(m_horaNacio);

}

void CFicha::Destruir()
{
	m_horaNacio.Destruir();
}

void CFicha::Visualizar()
{
	// no se va a visualizar ningun elemento CFicha
}

CFicha* CFicha::Clonar()

{
	return new CFicha(*this);
}