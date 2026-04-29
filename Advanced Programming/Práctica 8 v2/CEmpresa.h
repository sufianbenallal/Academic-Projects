#if !defined(_EMPRESA_H)
#define _EMPRESA_H
#include "CCliente.h"

template <class T> class CEmpresa
{
private:
	T* m_pElem; // los elementos pueden ser de cualquier tipo
	int m_nElem;

public:
	CEmpresa() : m_nElem(0), m_pElem(NULL) {};  // constructor con parametros por omision
	CEmpresa(const CEmpresa& a);   // constructor copia
	CEmpresa& operator=(const CEmpresa& a);  // operador de asignacion
	~CEmpresa();
	void AgregarElemento(const T& elem);
	int Tamanyo() const { return m_nElem; }
	T& GetElemento(int nElem) const;
	T& operator[](int nElem) const; // operador de indexacion
};

#include "CEmpresa.cpp"
// PREGUNTA 14: plantilla para CEmpresa


#endif
