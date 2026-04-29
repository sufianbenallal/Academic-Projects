#if !defined(UTILS_H)
#define UTILS_H
#include "CHora.h"
#include"CFicha.h"
#include <iostream>
#include<cstring>
#include<cstdlib>
; using namespace std;

namespace utils
{
	class CUtils
	{
		//METODOS
	public:
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(double& dato);
		static bool LeerDato(string& dato);
		static bool LeerDato(char* dato, int n);
		static char* ConverMayus(char* str);//convertir cadena a mayusculas
		static std::string& ConverMayus(std::string& str);
		static int menu(char* opciones[], int numOpciones);
	};
};

void VisualizarHora(const CHora& horaVisu);
void VisualizarFicha(CFicha& ficha);


#endif // UTILS_H