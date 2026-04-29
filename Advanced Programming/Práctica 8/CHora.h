#if !defined(_CHORA_)
#define _CHORA_
#include <string>
using namespace std;

class CHora
{
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	std::string m_pszFormato; //almacena los valores de "AM","PM" o "24 HORAS"

	bool AsignarFormato(std::string pszFormato); //verifica que el formato no es nulo
	bool Formato24() const;

public:
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, std::string pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, std::string& pszFormato) const;
	CHora::CHora(int hh = 0, int mm = 0, int ss = 0, std::string ff = "AM"); //Constructor sobrecargado
	CHora::~CHora(); //Destructor
	bool EsHoraCorrecta() const;
	CHora& CHora::operator=(const CHora& hora); //OPERADOR DE ASIGNACION
	CHora(const CHora& hora); //CONSTRUCTOR COPIA
	void Destruir();
};


#endif // _CHORA_