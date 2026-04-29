#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include "CHora.h"
#include "utils.h"
#include <conio.h>

using namespace std;

/*bool CHora::AsignarFormato(char* pszFormato) {
	if (pszFormato == nullptr)
		return false;

	int longitud;

	longitud = strlen(pszFormato); //Calculo longitud de cadena, no incluye el '/0'
	m_pszFormato = new (nothrow) char[(longitud + 1)];//Reservo memoria para el tamaño longitud + caracter '/0'

	if (m_pszFormato == nullptr)
		return false;

	strcpy(m_pszFormato,pszFormato); //Copia en m_pszFormato la cadena de pszFormato

	ConverMayus(m_pszFormato);//Convertir a mayuscula.

	return true;
}*/

bool CHora::Formato24() const {
	if (m_sFormato == "24 HORAS") //Si son iguales devuelve 0
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

	if (m_sFormato == "AM") //Si son iguales devuelve 0
		if (13 > m_nHoras && m_nHoras > -1)
			if (60 > m_nMinutos && m_nMinutos > -1)
				if (60 > m_nSegundos && m_nSegundos > -1) {
					cout << "\n\n La hora introducida es correcta \n\n";
					return true;
				}

	if (m_sFormato == "PM") //Si son iguales devuelve 0
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
	m_sFormato = "vacio";
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato) {

	bool a;
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	m_sFormato = pszFormato;

	m_sFormato = ConverMayus(m_sFormato);

	a = EsHoraCorrecta();
	if (a == true)
		return true;

	else
		return false;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const {
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	pszFormato = m_sFormato;
}

void CHora::Destruir() {


}

CHora::CHora() {

	Iniciar();

}

CHora::~CHora() {

	Destruir();

}
