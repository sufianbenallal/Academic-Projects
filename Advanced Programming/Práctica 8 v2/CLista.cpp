#if !defined(_LISTA_CPP)
#define _LISTA_CPP

#include "CIndiceIncorrecto.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "CLista.h"
using namespace std;

//template<class T>
//CLista<T>::CLista()
template<class T> CLista<T>::CLista() : m_Ultimo(NULL), m_Actual(NULL), m_Primero(NULL)
{}



//template <class T>
//CLista<T>::CLista(const CLista<T> &Lista)
template<class T>
CLista<T>::CLista(const CLista<T>& lista)
{
    *this = lista;
}




template <class T>
CLista<T>& CLista<T>::operator=(const CLista<T>& Lista)
{
    Vaciar();
    if (!Lista.EstaVacia())
    {
        m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
        while (Lista.TieneMas())
        {
            m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
            m_Ultimo = m_Actual = m_Actual->GetSigNodo();
        }
    }
    return *this;
}

template <class T>
void CLista<T>::AgregarObjeto(const T& Obj)
{
    if (EstaVacia())
        m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj);
    else
    {
        m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj));
        m_Ultimo = m_Ultimo->GetSigNodo();
    }
}

template <class T>
T& CLista<T>::GetActual() const
{
    CNodoLista<T>* temp = m_Actual;
    const_cast<CLista<T>*>(this)->m_Actual = m_Actual->GetSigNodo();
    return temp->GetDato();
}

template <class T>
T& CLista<T>::GetPrimero() const
{
    // PREGUNTA 11
    const_cast<CLista<T>*>(this)->m_Actual = m_Primero->GetSigNodo();
    return m_Primero->GetDato();
}


// PREGUNTA 2: operator[] de CLista. Lanza excepcion CIndiceIncorrecto.

template <class T>
CNodoLista<T>& CLista<T>::operator[](int i) const throw(CIndiceIncorrecto) // lanza excepcion de tipo CIndiceIncorrecto
{
    const_cast<CLista*>(this)->m_Actual = m_Primero;

    for (int j = 0; j < i; j++)
    {
        const_cast<CLista*>(this)->m_Actual = m_Actual->GetSigNodo();
        if (!TieneMas())
            throw CIndiceIncorrecto("No existe el indice !!");
    }
    CNodoLista<T>* aux = m_Actual; // creo aux para devolver
    Restart();
    return *aux;
}



// PREGUNTA 1: 

template<class T> void CLista<T>::Vaciar()
{
    CNodoLista<T>* pun;
    if (EstaVacia()) return;
    if (!EstaVacia())
    {
        m_Actual = m_Primero;

        while (m_Actual) // mientras m_Actual no sea NULL
        {
            pun = m_Actual;
            m_Actual = pun->GetSigNodo();
            delete pun;
        }
        m_Ultimo = NULL;
        m_Actual = NULL;
        m_Primero = NULL;
    }
}





template<class T> void CLista<T>::Restart() const
{
    const_cast<CLista*>(this)->m_Actual = m_Primero;
}

template<class T>
CLista<T>::~CLista()
{
    Vaciar();
}

#endif
