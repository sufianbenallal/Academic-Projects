#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include "utils.h"


class CHora
{
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	char* m_pszFormato;
	bool AsignarFormato(char* pszFormato);
	bool Formato24() const;

protected:

public:
	CHora(int hh = 0, int mm = 0, int ss = 0, const char* ff = "24 HORAS");
	CHora(const CHora& H);
	CHora& operator=(const CHora& hora); //Operador de asignacion
	~CHora();//Destructor
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const;
	void Destruir();
	bool EsHoraCorrecta() const;

};