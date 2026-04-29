#pragma once
#include "CTermino.h"
#include <vector>
#include <iostream>

class CPolinomio
{
private:
	CTermino* m_pCabecera;	// Primer termino (de mayor grado)
	//vector<CTermino> m_Terminos;

public:
	void setCabecera(CTermino* pCabecera)
	{
		m_pCabecera = pCabecera; // Modifica el puntero al primer termino de nuestro polinomio
	}

	CTermino* getCabecera()
	{
		return m_pCabecera; // Constructor con la cabecera como parametro
	}

	//CPolinomio (CTermino* cabecera) : m_pCabecera(cabecera) {}

	// 1. Constructor sin parametros que inicia m_pCabecera a null
	CPolinomio() :
		m_pCabecera(nullptr) {} //nullptr es como un NULL que se aplica solo a punteros

	// 2. Constructor 'copia' que copia(valga la redundancia) un polinomio
	CPolinomio(const CPolinomio& polinomio) //nuestro polinomio
	{
		//m_pCabecera = nullptr;
		//*this = poli;		
		// Llama a operador asignacion (punto 7)

		CTermino* pPos = polinomio.m_pCabecera;
		if (!(m_pCabecera = new(nothrow)CTermino))
		{
			cout << "La memoria es insuficiente. /n";
		}

		this->~CPolinomio(); //destructor que libera la memoria dinamica del polinomio
		m_pCabecera = nullptr;
		do
		{
			*this << pPos->GetMono();
			pPos = pPos->GetSig();
		} while (pPos);
	}

	// 3. Constructor que recibe un coeficiente y un exponente para construir un polinomio con un termino
	CPolinomio(double dCoef, int nExp = 0) : m_pCabecera(nullptr) //iniciador
	{
		if (!dCoef)
		{
			m_pCabecera = nullptr;			//Si no existe coeficiente, monomio 0 y m_pCabecera NULL
		}

		else
		{
			m_pCabecera = new CTermino;		//Si el coeficiente no es nulo reservamos memoria para un termino apuntado por m_pCabecera
			m_pCabecera->SetCoef(dCoef);	//Coeficiente del termino igual a dCoef
			m_pCabecera->SetExp(nExp);		//Exponente del termino igual a nExp
			m_pCabecera->SetSig(nullptr);	//m_pSig NULL porque no apunta a ningun otro de momento
		}
	}

	// 4. Constructor que recibe un vector<CMonomio>, y construye un polinomio formado por los monomios contenidos en el vector
	CPolinomio(vector<CMonomio> ListaMonomios)
	{
		CTermino* termino = new CTermino(ListaMonomios[0]);
		m_pCabecera = termino;
		for (int i = 1; i < ListaMonomios.size(); i++)
		{
			CTermino* termino2 = new CTermino(ListaMonomios[i]);
			termino->SetSig(termino2);
			termino = termino->GetSig();
		}
	}

	// 5. Constructor que recibe un monomio para construir un polinomio con un solo termino
	CPolinomio(CMonomio Monomio)
	{
		if (!Monomio.GetCoef())
		{
			m_pCabecera = nullptr; //Si el coeficiente de nuestro monomio es 0, m_pCabecera será NULL.
		}
		else
		{
			m_pCabecera = new CTermino(Monomio);
		}
	}

	// 6. Destructor que libera la memoria dinamica del polinomio
	~CPolinomio()
	{
		if (m_pCabecera == nullptr)
		{
			return;
		}

		CTermino* dirTerm = m_pCabecera;		// dirTerm apunta al primer termino del polinomio
		do
		{
			dirTerm = m_pCabecera->GetSig();	// dirTerm toma el valor del siguiente termino del polinomio
			delete m_pCabecera;				// Se libera la memoria apuntada por m_pCabecera
			m_pCabecera = dirTerm;			//m_pCabecera apunta al siguiente termino del polinomio
		} while (dirTerm);

	}

	// 7. Operador asignación que copia un polinomio:
	CPolinomio operator=(const CPolinomio poli)
	{
		if (this == &poli)
		{
			return *this;
		}

		this->CPolinomio::~CPolinomio();
		m_pCabecera = NULL;
		CTermino* pPos = poli.m_pCabecera;

		while (pPos != NULL)
		{
			*this << pPos->GetMono();
			pPos = pPos->GetSig();	// pPos toma el valor de la siguiente posicion 
		}
		return *this;
	}

	bool operator==(const CPolinomio polinomio);
	bool operator>(const CPolinomio polinomio);
	CPolinomio operator-();
	CPolinomio operator+(const CPolinomio polinomio);
	CPolinomio operator-(const CPolinomio polinomio);
	CPolinomio operator+=(const CPolinomio polinomio);
	CPolinomio operator-=(const CPolinomio polinomio);
	CPolinomio operator*(const CPolinomio polinomio);
	CPolinomio operator*=(const CPolinomio polinomio);
	double operator[](int nExp);
	double operator()(double x);


	int Grado() const;

	// Operador asignacion
	void MostrarPoli(ostream& os) const;
	CPolinomio& operator<<(const CMonomio& mono);	// sirve para la introduccion de datos en un polinomio

};

ostream& operator<<(ostream& os, const CPolinomio& Poli);	// Para enviar un polinomio a un flujo (cout)


