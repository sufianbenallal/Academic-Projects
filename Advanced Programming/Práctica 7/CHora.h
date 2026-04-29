#pragma once
#if !defined(_CHORA_H)
#define _CHORA_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class CHora {
private:
	int m_nHoras;       // AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos;     // AM/PM/24 HORAS: 0 a 59
	int m_nSegundos;    // AM/PM/24 HORAS: 0 a 59
	std::string m_pszFormato; // almacena los valores "AM", "PM" o "24 HORAS"

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

public:
	bool EsHoraCorrecta() const;
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.

	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, std::string pszFormato);
	// Recibe 4 argumentos, correspondientes a una hora,
	// y los almacena en las variables
	// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
	// correspondientes al objeto que recibe el mensaje.
	// Invoca a AsignarFormato y a EsHoraCorrecta.
	// Devuelve false si no pudo ser asignado el formato
	// o el valor retornado por EsHoraCorrecta.

	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, std::string& pszFormato) const;
	// Obtener una hora. Permite obtener los datos hora,
	// minutos, segundos y formato correspondientes
	// al objeto que recibe el mensaje.

	CHora operator = (CHora const hora)
	{
		CHora hora2;
		hora2.AsignarHora(hora.m_nHoras, hora.m_nMinutos, hora.m_nSegundos, hora.m_pszFormato);
		return hora2;
	}

	CHora(int hh = 0, int mm = 0, int ss = 0, std::string ff = "24 HORAS")
	{
		//std::cout << "Constructor invocado" << std::endl;

		m_nHoras = hh;
		m_nMinutos = mm;
		m_nSegundos = ss;
		m_pszFormato = ff;
	};

	//Constructor copia de Chora
	CHora(const CHora& hora)
	{
		m_nHoras = hora.m_nHoras;
		m_nMinutos = hora.m_nMinutos;
		m_nSegundos = hora.m_nSegundos;
		m_pszFormato = new char[10];
		m_pszFormato = hora.m_pszFormato;
		//std::cout << "Constructor Copia invocado." << std::endl;
	}

	//Destructor de Chora
	~CHora()
	{
		//std::cout << "Destructor invocado." << std::endl;
		m_pszFormato = "0";
	}
};

#endif
