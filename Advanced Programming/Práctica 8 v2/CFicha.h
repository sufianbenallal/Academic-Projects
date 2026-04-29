#if !defined(_CFICHA_)
#define _CFICHA_

#include<string>
#include "CHora.h"

class CFicha
{
private:
	std::string m_sNombre;
	int m_nEdad;
	CHora m_horaNacio;  //CLase CHora practica 4 version string

public:

	CFicha::CFicha(const std::string sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 0, int nSegundos = 0, const std::string sFormato = "AM");
	void AsignarNombre(const std::string sNombre);
	std::string ObtenerNombre() const;
	void AsignarEdad(int nEdad);
	int ObtenerEdad() const;
	bool AsignarNacio(int nHoras, int nMinutos, int nSegunos, const std::string& sFormato);
	CHora ObtenerNacio() const;
	void Destruir();

	// ------VIRTUAL------
	virtual CFicha* Clonar(); // Constructor Copia Virtual de CFicha
	virtual ~CFicha() {};  // Destructor Virtual CFicha
	virtual void Visualizar();
};
#endif //CFICHA