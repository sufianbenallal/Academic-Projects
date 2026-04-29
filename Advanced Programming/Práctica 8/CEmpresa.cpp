#include "CEmpresa.h"
#include "CIndiceIncorrecto.h"

// constructor copia
template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa<T>& a)
{
	*this = a;
}

// Operador =
template<class T>
CEmpresa<T>& CEmpresa<T>::operator=(const CEmpresa& a)
{
	if (this == &a)
		exit(1); // compara si los objetos son iguales

	m_nElem = a.m_nElem;

	if (m_pElem)
	{
		delete[] m_pElem;
		m_pElem = NULL;
	}

	m_pElem = new(nothrow) T[m_nElem];
	if (m_pElem == NULL) { cout << "No hay memoria suficiente !!" << endl; exit(1); }

	for (int i = 0; i < a.m_nElem; i++)
		m_pElem[i] = a.m_pElem[i];

	return *this;
}

// Destructor   --hay que implementarlo, sino da error al crear la empresa en main.c
template<class T>
CEmpresa<T>::~CEmpresa()
{
	if (m_pElem)
	{
		delete[] m_pElem;
		m_pElem = NULL;
	}
}


// AgregarElemento
template<class T>
void CEmpresa<T>::AgregarElemento(const T& elem) {
	T* aux = new (std::nothrow) T[++m_nElem];
	if (!aux)
		exit(-1);
	for (int i = 0; i < m_nElem - 1; i++)
		aux[i] = m_pElem[i];
	aux[m_nElem - 1] = elem;
	delete[] m_pElem;
	m_pElem = aux;
}


// GetElemento
template<class T>
T& CEmpresa<T>::GetElemento(int nElem) const
{
	if ((nElem < 0) || (nElem > m_nElem)) throw CIndiceIncorrecto::CIndiceIncorrecto();
	return m_pElem[nElem];
}


// Operador de indexación: []
/* template<class T>
T& CEmpresa<T>::operator[](int nElem) const throw(CIndiceIncorrecto)
{
	int i;
	if (Tamanyo() < nElem)
		throw CIndiceIncorrecto( "No existe el indice.");
	for(i = 0; i < nElem; i++);
	return m_pElem[i];
}*/
template<class T>
T& CEmpresa<T>::operator[](int nElem) const
{
	if ((nElem < 0) || (nElem > m_nElem)) throw CIndiceIncorrecto::CIndiceIncorrecto();
	return m_pElem[nElem];
}



