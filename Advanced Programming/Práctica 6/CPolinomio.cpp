#include "CPolinomio.h"
#include "MemoryManager.h"

void CPolinomio::MostrarPoli(ostream& os) const
{
	const CTermino* pPos = m_pCabecera; //apunta a la posicion de cabecera

	if (pPos)
	{
		do
		{
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig();
		} while (pPos);
	}
	else
	{
		os << "0 ";
	}
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mono)	//añadimos un monomio al polinomio
{
	if (mono.GetCoef())					//Siempre que el coeficiente del monomio no sea nulo
	{
		if (m_pCabecera == NULL)			//y m_pCabecera no apunte a nada
		{
			if (!(m_pCabecera = new (nothrow) CTermino)) //Reservamos memoria para lo apuntado por m_pCabecera
			{
				cout << "La memoria es insuficiente. " << endl;
				m_pCabecera = NULL;
				return *this;
			}

			else
			{
				m_pCabecera->SetMono(mono);		//el monomio es apuntado por m_pCabecera
				m_pCabecera->SetSig(NULL);		//m_pSig de m_pCabecera apunta a NULL
				return *this;
			}
		}
		else	//Si ya existe algun elemento apuntado por m_pCabecera
		{
			CTermino* antiguo = NULL, * nuevo = NULL, * actual = m_pCabecera;
			//vamos avanzando por el polinomio desde el mayor exponente al menor exponente.
			do
			{
				if (actual->GetExp() == mono.GetExp())		//Si el termino tiene igual exponente que el apuntado por m_pCabecera
				{
					actual->SetCoef(actual->GetCoef() + mono.GetCoef());	//Sumaremos los coeficientes
					if (!actual->GetCoef())									//Si el resultado de la suma es 0
					{
						if (!antiguo)										//Y no existe ningun termino anterior (es decir, es el primero)
						{
							m_pCabecera = actual->GetSig();					//m_pCabecera apuntará al termino siguiente (el segundo pasa a ser el primero)
						}
						else
						{
							antiguo->SetSig(actual->GetSig());	//si tenia otro elemento a la izquierda (es decir, no era el primero), el elem de su derecha pasa a la izq. para sustituirlo
						}
						delete actual;
					}
					return *this;
				}
				else if (actual->GetExp() < mono.GetExp())	//Si el termino actual a incluir tiene mayor exponente que el actual	
															//esto solo nos pasará para primer termino o si hay un hueco en el polinomio
				{
					if (!(nuevo = new (nothrow) CTermino))	//Reservamos memoria para el nuevo termino que introducimos apuntado por 'nuevo'
					{
						cout << "\nNo hay suficiente espacio de memoria.";
						return *this;
					}

					nuevo->SetMono(mono);			//Le damos valor al nuevo termino
					nuevo->SetSig(actual);			//'actual' pasa a estar a la derecha de 'nuevo'

					//comprobamos
					if (!antiguo)		//Si no existe un termino antiguo ('nuevo' es el primer termino)
					{
						m_pCabecera = nuevo;		//m_pCabecera apunta al nuevo termino
					}
					else
					{
						antiguo->SetSig(nuevo);		//pero si no es el primero, pasa a ser el 'm_pSig' del termino que ya hay a su izquierda.
					}
					return *this;
				}

				//m_pCabecera apuntara al termino mayor
				antiguo = actual;
				actual = actual->GetSig();	//avanzamos otro termino a la derecha del polinomio

			} while (actual != NULL);	// Llegamos al final del polinomio

			// Se añade al final (el nuevo termino es menor que los demas)
			if (!(nuevo = new (nothrow) CTermino))		// Reservamos memoria para el nuevo termino
			{
				cout << "\nNo hay suficiente espacio de memoria.";
				return *this;
			}
			nuevo->SetMono(mono);				//'nuevo' apunta al monomio
			antiguo->SetSig(nuevo);				//m_pSig de 'antiguo' apunta a 'nuevo'
			nuevo->SetSig(NULL);				//y m_pSig apuntado por 'nuevo' es nulo (final del polinomio)
		}
	}
	return *this;
}

bool CPolinomio::operator==(const CPolinomio pol)	//compara el grado de los polinomios
{
	if (m_pCabecera == nullptr)
	{
		return false;
	}
	else
	{
		return m_pCabecera->GetExp() == pol.m_pCabecera->GetExp();
	}
}

bool CPolinomio::operator>(const CPolinomio polinomio)
{
	return m_pCabecera->GetExp() > polinomio.m_pCabecera->GetExp();
}

CPolinomio CPolinomio::operator-()	// operador unario, o cambio de signo
{
	CPolinomio copia = *this;	//copiamos el polinomio en copia
	CTermino* pPos = copia.m_pCabecera;	// el puntero pPos empieza apuntando al primer termino del polinomio copia

	do
	{
		pPos->SetMono(-pPos->GetMono());	//Le cambiamos el signo al termino apuntado por pPos
		pPos = pPos->GetSig();				//pPos apunta al siguiente termino del polinomio 'copia'
	} while (pPos);	// el bucle durará hasta llegar al final del polinomio
	return copia;
}

CPolinomio CPolinomio::operator+(const CPolinomio polinomio)	//operador suma de polinomios
{
	int i = 0;
	CPolinomio suma = *this;	//copiamos en primer polinomio en 'suma'
	CTermino* pPos = polinomio.m_pCabecera;		// pPos apunta al primer termino del otro polinomio

	do		//sumamos termino a termino
	{
		//operador insercion: Si encuentra un termino en el polinomio 'suma', del mismo exponente que el termino a insertar, los suma. 
		//Si no, lo añade en la posicion correspondiente
		suma << pPos->GetMono();
		pPos = pPos->GetSig();	//pPos avanza al siguiete termino de 'polinomio'
	} while (pPos);	//el bucle dura hasta llegar al final de 'polinomio'
	return suma;
}

CPolinomio CPolinomio::operator-(const CPolinomio polinomio)	//operador binario (resta de polinomios)
{
	CPolinomio resta(polinomio);	//copiamos el segundo polinomio en 'resta'

	return  *this + -resta;		//devolvemos la resta (el primero mas el segundo cambiado de signo)
}

CPolinomio CPolinomio::operator+=(const CPolinomio polinomio)
{
	return *this = *this + polinomio;	// sumamos y lo pasamos al primer operando
}

CPolinomio CPolinomio::operator-=(const CPolinomio polinomio)
{
	return *this = *this - polinomio;		// restamos y lo pasamos al primer operando
}

double CPolinomio::operator[](int nExp)		//muestra el coef del termino con el exponente que se ha indicado
{
	CTermino* pPos = m_pCabecera;	//pPos apunta al primer termino del polinomio
	do
	{
		if (pPos->GetExp() == nExp)	//Buscamos el termino del exponente solicitado
		{
			return pPos->GetCoef();		//Devolvemos dicho coeficiente
		}
		else
		{
			pPos = pPos->GetSig();		//si no coincide, pPos avanzará al siguiete termino.
		}

	} while (pPos);		//el bucle dura hasta llegar al final del polinomio
	cout << " El exponente no se encontrado." << endl;
	return 0;	//si no encuentra nada retorna 0
}

double CPolinomio::operator() (double x) //damos un valor numerico a la x, y mostramos el resultado del polinomio al sistituir por numeros
{
	CTermino* pPos = m_pCabecera;		//pPos apunta al primer termino
	double resultado = 0;
	do
	{
		resultado += (pPos->GetCoef() * pow(x, pPos->GetExp())); //pow(3,3) = 3^3 = 81 es decir que pow retorna la base elevada al exp.
		pPos = pPos->GetSig();
	} while (pPos);  //el bucle dura hasta llegar al final del polinomio
	return resultado;
}

CPolinomio CPolinomio::operator*(const CPolinomio polinomio)	//operador de producto de polinomios
{
	CTermino* pPos = m_pCabecera;	//pPos apunta al primer termino del primer polinomio
	CTermino* pPos2 = polinomio.m_pCabecera;	////pPos2 apunta al primer termino del segundo polinomio

	CMonomio monomio;
	vector<CMonomio> monomios;

	do
	{
		pPos2 = polinomio.m_pCabecera;
		do
		{
			monomio.SetCoef(pPos2->GetCoef() * pPos->GetCoef()); //multiplica las bases de los 2 monomios
			monomio.SetExp(pPos2->GetExp() + pPos->GetExp()); //suma los exponentes de los 2 monomios
			monomios.push_back(monomio);
			pPos2 = pPos2->GetSig();
		} while (pPos2);
		pPos = pPos->GetSig();  //pPos2 avanza al siguiete termino de 'polinomio'
	} while (pPos);  //el bucle dura hasta llegar al final del polinomio

	CPolinomio polinomio2(monomios);
	return polinomio2;
}

CPolinomio CPolinomio::operator*=(const CPolinomio polinomio)
{
	return *this = *this * polinomio;
}

int CPolinomio::Grado() const
{
	return m_pCabecera->GetExp();
}

ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(os);
	return os;
}