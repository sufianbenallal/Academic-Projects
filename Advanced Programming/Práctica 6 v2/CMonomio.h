#pragma once
#include <ostream>

using namespace std;

class CMonomio
{
private:
	double m_dCoeficiente;
	int m_nExponente;

public:
	// Valores por defecto del constructor CMonomio (0, 0)
	CMonomio(double dCoef = 0, int nExp = 0) : m_dCoeficiente(dCoef), m_nExponente(nExp) {}	// Lista de iniciadores
	double GetCoef() const { return m_dCoeficiente; }	// Devuelve el coeficiente del monomio
	int GetExp() const { return m_nExponente; }	// Devuelve el exponente del monomio
	void SetCoef(double dCoef) { m_dCoeficiente = dCoef; }	// Modificar coeficiente del monomio
	void SetExp(int nExp) { m_nExponente = nExp; }	// Modificar exponente del monomio

	CMonomio operator-() const	//sobrecarga del operador menos unario del monomio (cambio de signo)
	{
		return CMonomio(-m_dCoeficiente, m_nExponente);	// Devuelve un monomio igual al que le hemos pasado pero con el coef. cambiado de signo
	}
};

ostream& operator<<(ostream& os, const CMonomio& Mono);	//sobrecarga del operador de insercion para mostrar el monomio

