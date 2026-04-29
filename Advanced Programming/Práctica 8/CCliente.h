#if !defined(_CLIENTE_H)
#define _CLIENTE_H

#include <string>
#include <iostream>
#include "CLista.h"
#include "CContrato.h"

class CCliente
{
	friend ostream& operator<<(ostream& os, CCliente& c);
private:
	std::string m_Nombre;
	CLista<CContrato> m_Contratos;

public:
	CCliente(const std::string& Nom = "Sin Nombre") : m_Nombre(Nom) {};
	CCliente(const std::string& Nom, const CContrato& c);

	void SetNombre(const std::string& Nom) { m_Nombre = Nom; }
	std::string GetNombre() const { return m_Nombre; }
	void AgregarContrato(const CContrato& c);
	CLista<CContrato> GetContratos() const { return m_Contratos; }

	CCliente& operator<<(const CCliente& cli);
	operator long(); // sobrecarga del operador long
};

#endif