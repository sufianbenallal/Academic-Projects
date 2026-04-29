#if !defined(_LISTA_CPP)
#define _LISTA_CPP
#include "CLista.h"
#include "CIndiceIncorrecto.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

//template<class T>
//CLista<T>::CLista() //iniciador
template<class T> CLista<T>::CLista() : m_Ultimo(NULL), m_Actual(NULL), m_Primero(NULL)
{}

//template <class T>
//CLista<T>::CLista(const CLista<T> &Lista)
template<class T> //constructor
CLista<T>::CLista(const CLista<T>& lista)
{
    *this = lista;
}

template <class T>
CLista<T>& CLista<T>::operator=(const CLista<T>& Lista)
{
    if (this == &Lista)
    {
        exit(1);   // compara si los objetos son iguales
    }

    Vaciar();
    if (!Lista.EstaVacia()) //si lista no vacia
    {
        m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
        while (Lista.TieneMas()) //mientars no lleguemos al final de la lista
        {
            m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
            m_Ultimo = m_Actual = m_Actual->GetSigNodo();
        }
    }
    return *this;
}

// AgregarObjeto()
template <class T>
void CLista<T>::AgregarObjeto(const T& Obj)
{
    if (EstaVacia())
        m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj); //el primero es el ultimo o el actual y le creamos memoria

    else
    {
        m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj)); // crea el objeto al final de la lista
        m_Ultimo = m_Ultimo->GetSigNodo();
    }
}

// GetActual()
template <class T>
T& CLista<T>::GetActual() const
{
    CNodoLista<T>* temp = m_Actual;
    const_cast<CLista<T>*>(this)->m_Actual = m_Actual->GetSigNodo(); // convertimos "const" a "NO const"
    return temp->GetDato();
}

// GetPrimero()
template <class T>
T& CLista<T>::GetPrimero() const
{
    // PREGUNTA 11
    const_cast<CLista<T>*>(this)->m_Actual = m_Primero->GetSigNodo(); // convertimos "const" a "NO const"
    return m_Primero->GetDato();
}


// PREGUNTA 2: operator[] de CLista. Lanza excepcion CIndiceIncorrecto.
template <class T>
CNodoLista<T>& CLista<T>::operator[](int i) const throw(CIndiceIncorrecto) // lanza excepcion de tipo CIndiceIncorrecto
{
    const_cast<CLista*>(this)->m_Actual = m_Primero; // convertimos "const" a "NO const"

    for (int j = 0; j < i; j++)
    {
        const_cast<CLista*>(this)->m_Actual = m_Actual->GetSigNodo();
        if (!TieneMas())
            throw CIndiceIncorrecto("El indice no existe.");
    }
    CNodoLista<T>* aux = m_Actual; // creo aux para devolver
    Restart();
    return *aux;
}



// PREGUNTA 1: Vaciar()

template<class T> void CLista<T>::Vaciar()
{
    CNodoLista<T>* pun;     //creamos puntero a CNodoLista
    if (EstaVacia())
        return;     //Si la lista esta vacia, no hay nada que vaciar

    if (!EstaVacia())     //si no esta vacia, comenzamos a vaciarla
    {
        m_Actual = m_Primero;    //comenzamos por el primer nodo de la lista
        while (m_Actual)      //mientras m_Actual no sea NULL
        {
            pun = m_Actual;    //'pun' apunta a 'actual'
            m_Actual = pun->GetSigNodo();      //'actual' pasa a apuntar al siguiente (metodo CNodoLista)
            delete pun;        //borramos el nodo apuntado por 'pun'
        }
        m_Ultimo = NULL;
        m_Actual = NULL;
        m_Primero = NULL;
    }
}


// Restart()
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
