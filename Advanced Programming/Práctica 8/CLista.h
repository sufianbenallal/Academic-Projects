#if !defined (_LISTA_H)
#define _LISTA_H

#include "CNodoLista.h"
#include "CIndiceIncorrecto.h"

// Declaración anticipada de CNodoLista:
template<class T> class CNodoLista;

template <class T>
class CLista
{
private:
	CNodoLista<T>* m_Primero;  // punteros de tipo <T> a CNodoLista. NO SON ATRIBUTOS DE CNodoLista, SOLO PUNTEROS A OBJETOS
	CNodoLista<T>* m_Actual;
	CNodoLista<T>* m_Ultimo;

public:
	CLista();
	CLista(const T& Obj);
	CLista(const CLista<T>& Lista);
	~CLista();

	CLista<T>& operator=(const CLista<T>& Lista);
	bool EstaVacia() const { return m_Primero == NULL; }
	bool TieneMas() const { return	 m_Actual != NULL; }
	void AgregarObjeto(const T& Obj);
	void Vaciar();
	void Restart() const;
	T& GetPrimero() const;
	T& GetActual() const;
	CNodoLista<T>& CLista<T>::operator[](int i) const;

};

#include "CLista.cpp"

#endif
