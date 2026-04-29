#pragma once
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <limits>

using namespace std;

class CHora {
private:
	int m_nHoras;			// AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos;			// AM/PM/24 HORAS: 0 a 59
	int m_nSegundos;		// AM/PM/24 HORAS: 0 a 59
	char* m_pszFormato;		//almacena los valores "AM", "PM" o "24 HORAS"

	bool AsignarFormato(char* pszFormato);
	// Verifica que pszFormato no es nulo.
	// Copia en m_pszFormato el formato dado por pszFormato,
	// asignando la cantidad de memoria necesaria, y lo convierte
	// a mayúsculas. Si fuera necesario, previamente se liberará
	// la memoria que hubiera asignada. Devuelve true si la
	// operación se realiza con éxito y false en caso contrario.
	bool Formato24() const;
	// Devuelve true si el formato es "24 HORAS".
	// En otro caso, devuelve false.

protected:
	bool EsHoraCorrecta() const;
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.
public:
	void Iniciar();
	// Será invocada cada vez que se defina un objeto.
	// Pone a 0 todos los atributos de CHora.
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato);
	// Recibe 4 argumentos, correspondientes a una hora,
	// y los almacena en las variables
	// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
	// correspondientes al objeto que recibe el mensaje.
	// Invoca a AsignarFormato y a EsHoraCorrecta.
	// Devuelve false si no pudo ser asignado el formato
	// o el valor retornado por EsHoraCorrecta.
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const;
	// Obtener una hora. Permite obtener los datos hora,
	// minutos, segundos y formato correspondientes
	// al objeto que recibe el mensaje.
	void Destruir();
	// Libera la memoria reservada dinámicamente para un objeto y
	// pone el puntero m_pszFormato a cero.
	CHora();
	~CHora();
};
