#pragma once
#include "CMonomio.h"

class CTermino
{
private:
	CMonomio m_Monomio;	// Monomio contenido en el termino
	CTermino* m_pSig;	// Puntero al siguiente termino

public:
	// Constructores:

	CTermino(double dCoef = 0, int nExp = 0, CTermino* pSig = nullptr) : m_Monomio(dCoef, nExp), m_pSig(pSig)
	{
		/*m_Monomio.SetCoef(dCoef);
		m_Monomio.SetExp(nExp);
		m_pSig = pSig;*/
	}

	// Construir a partir de un objeto CMonomio y un puntero al siguiente termino
	CTermino(const CMonomio& Monomio, CTermino* pSig = nullptr) : m_Monomio(Monomio), m_pSig(pSig) {}

	// Construir a partir de otro objeto CTermino (copiamos su atributo m_Monomio) y un puntero al siguiente termino
	CTermino(const CTermino& Termino, CTermino* pSig = nullptr) : m_Monomio(Termino.m_Monomio), m_pSig(pSig) {}

	// Metodos Get:
	double GetCoef() const
	{
		return m_Monomio.GetCoef(); // Llama al metodo GetCoef de la clase CMonomio
	}

	int GetExp() const
	{
		return m_Monomio.GetExp(); // Llama al metodo GetExp de la clase CMonomio
	}

	CMonomio GetMono() const
	{
		return m_Monomio;
	}

	CTermino* GetSig() const
	{
		return m_pSig;
	}

	// Metodos Set:
	void SetCoef(double dCoef)
	{
		m_Monomio.SetCoef(dCoef); // Llama al metodo SetCoef de la clase CMonomio
	}

	void SetExp(int nExp)
	{
		m_Monomio.SetExp(nExp); // Llama al metodo SetExp de la clase CMonomio
	}

	void SetMono(const CMonomio& mono)
	{
		m_Monomio = mono;
	}

	void SetSig(CTermino* pSig)
	{
		m_pSig = pSig;
	}
};
