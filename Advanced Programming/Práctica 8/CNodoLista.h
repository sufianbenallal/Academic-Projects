#if !defined(_NODOLISTA_H)
#define _NODOLISTA_H

#include "CLista.h"

// Declaración anticipada de CLista:
template<class T> class CLista;

template<class T>
class CNodoLista
{
	friend class CLista<T>;
private:
	T m_Dato;
	CNodoLista<T>* m_pSigNodo;
public:
	CNodoLista() { m_pSigNodo = NULL; }
	CNodoLista(const CNodoLista<T>& NodoLista);
	CNodoLista(const T& Obj, CNodoLista<T>* pNodo = NULL);
	CNodoLista<T>& operator=(const CNodoLista<T>& NodoLista);
	CNodoLista<T>* GetSigNodo() const { return m_pSigNodo; }
	T& GetDato() { return m_Dato; }
	void SetSigNodo(CNodoLista<T>* pNodo) { m_pSigNodo = pNodo; }
};

#include "CNodoLista.cpp"
#endif