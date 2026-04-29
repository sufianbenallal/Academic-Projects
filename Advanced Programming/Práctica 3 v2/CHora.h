#pragma once
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <limits>

using namespace std;

class CHora {
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	string m_sFormato;

	//bool AsignarFormato(char* pszFormato);
	bool Formato24() const;

protected:
	bool EsHoraCorrecta() const;

public:
	void Iniciar();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const;
	void Destruir();
	CHora();
	~CHora();
};
