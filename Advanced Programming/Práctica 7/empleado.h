#pragma once
#if !defined(_EMPLEADO_H)
#define _EMPLEADO_H
#include <string>
#include "CFicha.h"

using namespace std;


class CEmpleado : virtual public CFicha // Hereda de CFicha (Practica 5)
{
private:
	string m_sCategoria;	// (ej.: "Administrativo", "Técnico"...)
	int m_nAntiguedad;	// (ej.: 3)

public:
	/*
	* Las clases CCliente y CEmpleado permitirán construir objetos iniciados con 0, 1, 2,… etc.,
	* valores pasados como argumentos, y la implementación de cada uno de los constructores
	* deberá utilizar una lista de iniciadores.
	*/

	/*
	* La cadena m_sCategoria estará vacía mientras no haya ninguna categoría especificada.
	* La antigüedad tomará inicialmente el valor 0.
	*/
	CEmpleado(string sCategoria = "", int nAntiguedad = 0, const string& sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 00, int nSegundos = 00, const string& sFormato = "AM")
		: m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad), CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato) {};
	~CEmpleado() {};

	void SetCategoria(const string& sCategoria)
	{
		m_sCategoria = sCategoria;
	};

	void SetAntiguedad(int nAntiguedad)
	{
		m_nAntiguedad = nAntiguedad;
	};

	/*
	* Se añadirá a la clase CFicha un método virtual `Visualizar`
	* y se redefinirá en cada una de las clases derivadas (`CCliente` y `CEmpleado`)
	* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
	*/

	void Visualizar();

	CEmpleado* clonar();
};
#endif
