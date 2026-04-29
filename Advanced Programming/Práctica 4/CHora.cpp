#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <limits>
#include "utils.h"

using namespace std;

bool CHora::AsignarFormato(char* pszFormato) {

	if (pszFormato == NULL)// Verifica que pszFormato contiene la direccion de la cadena
		return false;

	if (m_pszFormato != NULL)//Si fuera necesario, previamente se liberará la memoria que hubiera asignada
		delete[] m_pszFormato; //Aqui el error*/

	m_pszFormato = new (nothrow) char[strlen(pszFormato) + 1];//Reservo memoria
	if (m_pszFormato == NULL)//Compruebo si se ha reservado bien
	{
		cout << "No se ha podido reservar memoria para almacenar el formato";
		return false;
	}

	//if (m_pszFormato != 0 && pszFormato != 0)
	strcpy(m_pszFormato, pszFormato);

	m_pszFormato = utils::CUtils::ConverMayus(m_pszFormato);

	return true;
}
// Verifica que pszFormato no es nulo.
// Copia en m_pszFormato el formato dado por pszFormato,
// asignando la cantidad de memoria necesaria, y lo convierte
// a mayúsculas. Si fuera necesario, previamente se liberará
// la memoria que hubiera asignada. Devuelve true si la
// operación se realiza con éxito y false en caso contrario.


bool CHora::Formato24() const {
	if (strcmp(m_pszFormato, "24 HORAS") == 0)
		return true;// Devuelve true si el formato es "24 HORAS".

	return false;// En otro caso, devuelve false.
}

bool CHora::EsHoraCorrecta() const {

	if (Formato24()) {//Compruebo si el formato es true se ejecuta el if
		if (0 < m_nSegundos && m_nSegundos < 60)
			if (0 < m_nMinutos && m_nMinutos < 60)
				if (0 < m_nHoras && m_nHoras < 24) {
					cout << "\nLa hora introducida es valida\n\n";
					return true;
				}

				else
				{
					cout << "\n\La hora introducida no es correcta \n";
					return false;
				}

	}

	if (strcmp(m_pszFormato, "AM") == 0) {
		if (0 < m_nSegundos && m_nSegundos < 60)
			if (0 < m_nMinutos && m_nMinutos < 60)
				if (0 < m_nHoras && m_nHoras < 12) {
					cout << "\nLa hora introducida es valida\n\n";
					return true;
				}

				else {
					cout << "\nLa hora introducida no es valida\n\n";
					return false;
				}
	}

	if (strcmp(m_pszFormato, "PM") == 0) {
		if (0 < m_nSegundos && m_nSegundos < 60)
			if (0 < m_nMinutos && m_nMinutos < 60)
				if (0 < m_nHoras && m_nHoras < 12) {
					cout << "\nLa hora introducida es valida\n\n";
					return true;
				}

				else {
					cout << " \nLa hora introducida no es correcta\n\n";
					return false;
				}

	}
	cout << " \nLa hora introducida no es correcta\n\n";

	return false;
}
// Verifica si una hora es correcta:
// 1) verificar que el formato es 24 HORAS, AM o PM
// 2) y verificar que las horas, minutos y segundos están dentro
// de los límites según el formato sea o no 24 HORAS.
// Devuelve true si es correcta y false en otro caso.


/*bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato) {
	bool a;

	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	m_pszFormato = pszFormato;//Esto estaria mal

	a = AsignarFormato(m_pszFormato);
	if (a == false)
		return false;

	a = EsHoraCorrecta();
	if (a == true)
		return true;

	else
		return false;

	}
// Recibe 4 argumentos, correspondientes a una hora,
// y los almacena en las variables
 // m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
 // correspondientes al objeto que recibe el mensaje.
// Invoca a AsignarFormato y a EsHoraCorrecta.
// Devuelve false si no pudo ser asignado el formato
// o el valor retornado por EsHoraCorrecta.
*/


void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato)const {

	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	strcpy(pszFormato, m_pszFormato);

}// Obtener una hora. Permite obtener los datos hora,e
// minutos, segundos y formato correspondientes
// al objeto que recibe el mensaje.


CHora::CHora(int hh, int mm, int ss, const char* ff)//Constructor
{
	m_nHoras = hh;
	m_nMinutos = mm;
	m_nSegundos = ss;

	if (m_pszFormato != nullptr)
		delete[] m_pszFormato;


	if (ff != nullptr) {
		m_pszFormato = new (nothrow) char[strlen(ff) + 1];
		if (m_pszFormato == nullptr) {
			cout << "Error en la reserva de memoria\n";
			exit(0);
		}
		strcpy(m_pszFormato, ff);
	}

	else {
		m_pszFormato = new (nothrow) char[strlen("24 HORAS") + 1];
		if (m_pszFormato == nullptr) {
			cout << "Error en la reserva de memoria\n";
			exit(0);
		}

		strcpy(m_pszFormato, "24 HORAS");
	}
	cout << "Ha sido invocado el constructor \n\n";
}

CHora::CHora(const CHora& H) : m_nHoras(H.m_nHoras), m_nMinutos(H.m_nMinutos), m_nSegundos(H.m_nSegundos)
{
	if (m_pszFormato != nullptr) {
		delete[] m_pszFormato;
	}

	AsignarFormato(H.m_pszFormato);
	cout << "Se ha invocado al constructor de copia\n\n";
}

CHora& CHora::operator=(const CHora& hora)
{
	cout << "Se ha invocado al operador asignación de CHora\n";
	m_nHoras = hora.m_nHoras;
	m_nMinutos = hora.m_nMinutos;
	m_nSegundos = hora.m_nSegundos;
	if (m_pszFormato != nullptr) {
		delete[] m_pszFormato;
	}
	AsignarFormato(hora.m_pszFormato);
	//strcpy(m_pszFormato, hora.m_pszFormato);
	return *this;
}

CHora::~CHora() {
	if (m_pszFormato != NULL)
		delete[] m_pszFormato;
}