#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include "utils.h"

using namespace std;

class CHora
{
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	string m_sFormato;
	bool AsignarFormato(string pszFormato);
	bool Formato24() const;

protected:

public:
	CHora(int hh = 0, int mm = 0, int ss = 0, const string ff = "24 HORAS");
	CHora(const CHora& H); //Constructor copia
	CHora& operator=(const CHora& hora); //Operador de asignacion
	~CHora();//Destructor
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const;
	bool EsHoraCorrecta() const;

};