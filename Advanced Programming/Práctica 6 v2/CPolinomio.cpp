#include "CPolinomio.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include"MemoryManager.h"
using namespace std;

// Constructor sin parametros que inicia m_pCabecera a null
CPolinomio::CPolinomio() {};

// Constructor que recibe un coeficiente, y un exponente para construir un polinomio con un solo termino
CPolinomio::CPolinomio(double dCoef, int nExp)
{
	if (!dCoef)
	{
		m_monomios.clear();			//Si no existe coeficiente, monomio 0 y m_pCabecera NULL
	}
	else
	{
		CMonomio m(dCoef, nExp);	//construimos un monomio con los parametros pasados
		*this << m;				//y lo insertamos en nuestro nuevo polinomio
	}
}
// Constructor que recibe un vector<CMonomio>, y construye un polinomio formado por los monomios contenidos en el vector
CPolinomio::CPolinomio(vector<CMonomio> v)
{
	for (int i = 0; i < v.size(); i++)	//insertamos el vector en el nuevo polinomio termino a termino
	{
		*this << v[i];
	}
}

//  Constructor que reciba un monomio para construir un polinomio con un solo termino
CPolinomio::CPolinomio(CMonomio monomio)
{
	if (!monomio.GetCoef())	//Si el coeficiente del monomio es 0, elimina el polinomio
	{
		m_monomios.clear();
	}
	else
	{
		*this << monomio;
	}
}

void CPolinomio::MostrarPoli(ostream& os) const
{
	if (!m_monomios.empty())   //si el polinomio no esta vacio, lo muestra
	{
		for (int i = 0; i < m_monomios.size(); i++)
		{
			os << m_monomios[i] << ' ';
		}
	}
	else   //si esta vacio muestra '0'
	{
		os << "0 ";
	}
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mono)	//añade un monomio al polinomio
{
	int  i = 0;

	if (mono.GetCoef())		//Si el coeficiente del monomio no es nulo
	{
		if (m_monomios.empty())			//y si el polinomio esta vacio
		{
			m_monomios.push_back(mono);  //insertamos el monomio en el polinomio (unico termino)
		}
		else	//Si no estaba vacio
		{
			//Avanzamos por el polinomio de mayor a menor exponente
			do
			{
				if (m_monomios[i].GetExp() == mono.GetExp())	//Si los monomios tienen igual expoente
				{
					m_monomios[i].SetCoef(m_monomios[i].GetCoef() + mono.GetCoef());	//Se suman los coeficientes
					if (m_monomios[i].GetCoef() == 0)		//Si el resultado de la suma es 0
					{
						m_monomios.erase(m_monomios.begin() + i);		//eliminamos dicho termino
					}
					return *this;
				}
				else if (m_monomios[i].GetExp() < mono.GetExp())	//Si el termino a incluir tiene mayor exponente que el actual
																	//(solo pasa para primer termino, o si hay un hueco en el polinomio)
				{
					m_monomios.insert(m_monomios.begin() + i, mono);
					return*this;
				}
				i++;	// Avanzamos otro termino a la der. del polinomio

			} while (i < m_monomios.size());	// Llegamos al final del polinomio

			// Se añade al final (el nuevo termino es menor que los demas)
			m_monomios.push_back(mono);
		}

	}
	return *this;
}


bool CPolinomio::operator==(const CPolinomio polinomio)	//compara el grado de los polinomios
{
	return (m_monomios.begin()->GetExp() == polinomio.m_monomios.begin()->GetExp());
}

bool CPolinomio::operator>(const CPolinomio polinomio)	//compara que polinomio tiene mayor grado
{
	return (m_monomios.begin()->GetExp() > polinomio.m_monomios.begin()->GetExp());
}

CPolinomio CPolinomio::operator-()	// unario, o cambia de signo
{
	CPolinomio copia = *this;	//copiamos el polinomio en 'copia'

	for (int i = 0; i < m_monomios.size(); i++)		//cambiamos de signo todos los monomios
	{
		copia.m_monomios[i].SetCoef(-(m_monomios[i].GetCoef()));
	}
	return copia;
}

CPolinomio CPolinomio::operator+(const CPolinomio polinomio)	//operador suma de polinomios
{
	int i = 0;
	CPolinomio suma = *this;	//copiamos en primer polinomio en 'suma'
	for (i = 0; i < polinomio.m_monomios.size(); i++)
	{
		//operador insercion. Si encuentra un termino en el polinomio 'suma' del mismo exponente que el termino a insertar los suma.
		//Sino, lo añade en la posicion correspondiente.
		suma << polinomio.m_monomios[i];
	}
	return suma;
}


CPolinomio CPolinomio::operator-(const CPolinomio polinomio)	//operador binario (resta de polinomios)
{
	CPolinomio resta(polinomio);	//copiamos el segundo polinomio en 'resta'

	return  *this + -resta;		//devolvemos la resta (el primero mas el segundo cambiado de signo)
}

CPolinomio CPolinomio::operator+=(const CPolinomio polinomio)
{
	return *this = *this + polinomio;	// Sumamos y lo pasamos al primer operando
}

CPolinomio CPolinomio::operator-=(const CPolinomio polinomio)
{
	return *this = *this - polinomio;		// Restamos y lo pasamos al primer operando
}

double CPolinomio::operator[](int nExp)		//Muestra el coeficiente del termino con el exponente que se ha indicado
{
	double coef;
	for (int i = 0; i < m_monomios.size(); i++)		//Buscamos el termino del exponente solicitado
	{
		if (nExp = m_monomios[i].GetExp())		//comparamos monomio a monomio
		{
			coef = m_monomios[i].GetCoef();
			return coef;
		}
	}
	//si no lo encuentra, imprime:
	cout << "El exponente no se ha encontrado. " << endl;
}

double CPolinomio::operator() (double x) //le damos un valor numerico a x, y mostramos el resultado del polinomio con numeros
{
	double resultado = 0;
	for (int i = 0; i < m_monomios.size(); i++)
	{
		resultado += (m_monomios[i].GetCoef()) * pow(x, m_monomios[i].GetExp());
	}
	return resultado;
}

CPolinomio CPolinomio::operator*(const CPolinomio polinomio)	//producto de polinomios
{
	CPolinomio resultado;
	int i = 0, j = 0;
	CMonomio aux;	//aqui es donde vamos a ir guardando el producto
	while (m_monomios.size() != i)	//multiplicamos a cada termino el segundo polinomio
	{
		j = 0;
		while (polinomio.m_monomios.size() != j)
		{
			aux.SetCoef(m_monomios[i].GetCoef() * polinomio.m_monomios[j].GetCoef()); //multiplicamos las bases
			aux.SetExp(m_monomios[i].GetExp() + polinomio.m_monomios[j].GetExp());	//sumamos los exponentes
			resultado << aux;
			j++;
		}
		i++;
	}
	return resultado;
}

CPolinomio CPolinomio::operator*=(const CPolinomio polinomio) //iguala el primer operando al producto de los polinomios
{
	return *this = *this * polinomio;
}

int CPolinomio::Grado() const	//Devuelve el grado del primer termino (es decir, el mayor)
{
	return(m_monomios.begin()->GetExp());
}

ostream& operator<<(ostream& os, const CPolinomio& polinomio)	//sirve para mostrar un polinomio
{
	polinomio.MostrarPoli(os);
	return os;
}