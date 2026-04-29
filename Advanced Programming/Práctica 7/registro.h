#pragma once
#if !defined(_REGISTRO_H)
#define _REGISTRO_H
#include "empleado.h"
#include <vector>

class CRegistroDiario
{
private:
	// vector de personas
	vector <CFicha*> personas;

public:
	// constructor con num. de elementos como argumento
	CRegistroDiario(int ElementosMax);

	// destructor
	~CRegistroDiario();

	// Constructor copia
	CRegistroDiario(const CRegistroDiario& registro);

	// sobrecarga del operador asignación
	CRegistroDiario& operator=(const CRegistroDiario& registro);

	//bool operator==(const CRegistroDiario registro);

	// Metodo AgregarPersona
	void AgregarPersona(CFicha* pers);

	// Metodo VisualizarRegistro
	void VisualizarRegistro();

	// EsEmpleado
	static bool EsEmpleado(CFicha* pers);

	// Metodo VisualizarEmpleados
	void VisualizarEmpleados();

	// Operador indexacion
	CFicha* operator[] (int) const;

	/*// RegistroLleno
	bool RegistroLleno() const { return personas[nElementosMax] != nullptr; }

	// GetNumElemMax
	int GetNumElementosMax() const { return nElementosMax; }*/

	void BuscarPorNombre(string) const;

	int NumPersonas();

	void Delete()
	{
		CRegistroDiario::~CRegistroDiario();
	}
};
#endif