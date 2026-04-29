#pragma once
#if !defined(_CFICHA_H)
#define _CFICHA_H

#include <string>
#include "CHora.h"

using namespace std;


class CFicha
{
private:
	string m_sNombre;
	int m_nEdad;
	CHora m_horaNacio;

public:
	CFicha(const string& sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 00, int nSegundos = 00, const string& sFormato = "AM")
		: m_sNombre(sNombre), m_nEdad(nEdad), m_horaNacio(nHoras, nMinutos, nSegundos, sFormato) {};

	void AsignarNombre(const string& sNombre)
	{
		m_sNombre = sNombre;
	}

	string ObtenerNombre() const
	{
		return  m_sNombre;
	}

	void AsignarEdad(int nEdad)
	{
		m_nEdad = nEdad;
	}

	int ObtenerEdad() const
	{
		return m_nEdad;
	}

	bool AsignarNacio(int nHoras, int nMinutos, int	nSegundos, const string& sFormato)
	{
		return m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato);
	}

	CHora ObtenerNacio() const
	{
		return m_horaNacio;
	}

	/*
	* Se añadirá a la clase CFicha un método virtual 'Visualizar'
	* y se redefinirá en cada una de las clases derivadas ('CCliente' y 'CEmpleado')
	* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
	*/

	virtual void Visualizar() = 0;	//indicar que CFicha es una clase abstracta. Ponemos '= 0' en cualquier metodo virtual
									//metodo 'virtual' que redefiniremos en CEmpleado y en CCliente

	/*
	* Añada también un destructor virtual y declare esta clase abstracta.
	*/
	virtual ~CFicha() {};

	// Metodo virtual clonar
	virtual CFicha* clonar() = 0;
};
#endif
