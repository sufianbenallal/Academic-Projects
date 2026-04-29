#pragma once
#include "CMonomio.h"
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

class CPolinomio
{
private:
	vector<CMonomio> m_monomios;	//vector donde guardaremos los monomios del polinomio

public:

	// 1. Constructor sin parametros que inicie m_pCabecera a null
	CPolinomio();

	// 2. Constructor copia que copie un polinomio
	//CPolinomio(const CPolinomio& polinomio);

	// 3. Constructor que reciba un coeficiente y un exponente para construir un polinomio con un solo termino
	CPolinomio(double dCoef, int nExp = 0);

	// 4. Constructor que reciba un vector<CMonomio> y construya un polinomio formado por los monomios contenidos en dicho vector
	CPolinomio(vector<CMonomio> v);

	// 5. Constructor que reciba un monomio para construir un polinomio con un solo termino
	CPolinomio(CMonomio monomio);

	// 6. Destructor que libere la memoria dinamica del polinomio
	//~CPolinomio();

	// 7. Operador asignación que copie un polinomio:
	//CPolinomio operator=(const CPolinomio polinomio);

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

	void MostrarPoli(ostream& os) const;
	CPolinomio& operator<<(const CMonomio& mono);	// Para la introduccion de datos en un polinomio

};

ostream& operator<<(ostream& os, const CPolinomio& polinomio);	// Para enviar un polinomio a un flujo (cout)