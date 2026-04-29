#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include "CHora.h"
#include "utils.h"
#include <conio.h>

using namespace std;

bool CHora::AsignarFormato(char* pszFormato) {
	if (pszFormato == nullptr)
		return false;

	int longitud;

	longitud = strlen(pszFormato); //Calculo longitud de cadena, no incluye el '/0'
	m_pszFormato = new (nothrow) char[(longitud + 1)];//Reservo memoria para el tamaño longitud + caracter '/0'

	if (m_pszFormato == nullptr)
		return false;

	strcpy(m_pszFormato, pszFormato); //Copia en m_pszFormato la cadena de pszFormato

	ConverMayus(m_pszFormato);//Convertir a mayuscula.

	return true;
}

bool CHora::Formato24() const {
	if (strcmp(m_pszFormato, "24 HORAS") == 0) //Si son iguales devuelve 0
		return true;

	return false;

}

bool CHora::EsHoraCorrecta() const {
	bool a;
	a = Formato24();
	if (a == true)
		if (24 > m_nHoras && m_nHoras > -1)
			if (60 > m_nMinutos && m_nMinutos > -1)
				if (60 > m_nSegundos && m_nSegundos > -1) {
					cout << "\n\n La hora introducida es correcta \n\n";
					return true;

				}

	if (strcmp(m_pszFormato, "AM") == 0) //Si son iguales devuelve 0
		if (13 > m_nHoras && m_nHoras > -1)
			if (60 > m_nMinutos && m_nMinutos > -1)
				if (60 > m_nSegundos && m_nSegundos > -1) {
					cout << "\n\n La hora introducida es correcta \n\n";
					return true;
				}

	if (strcmp(m_pszFormato, "PM") == 0) //Si son iguales devuelve 0
		if (13 > m_nHoras && m_nHoras > -1)
			if (60 > m_nMinutos && m_nMinutos > -1)
				if (60 > m_nSegundos && m_nSegundos > -1) {
					cout << "\n\n La hora introducida es correcta \n\n";
					return true;

				}
	cout << "\n\n La hora introducida es incorrecta \n\n";
	return false;

}

void CHora::Iniciar() {
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = nullptr;
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato) {

	bool a;
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;

	a = CHora::AsignarFormato(pszFormato);
	if (a == false)
		return false;

	a = EsHoraCorrecta();
	if (a == false)
		return false;

	return true;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const {
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	if (pszFormato == nullptr || m_pszFormato == nullptr)
		return;

	strcpy(pszFormato, m_pszFormato);//Copia el contenido de m_pszFormato en pszFormato

}

void CHora::Destruir() {

	delete[] m_pszFormato;
	m_pszFormato = nullptr;

}

CHora::CHora() {

	Iniciar();

}

CHora::~CHora() {

	if (m_pszFormato != nullptr)
		Destruir();

}
