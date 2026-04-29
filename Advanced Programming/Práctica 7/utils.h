#pragma once
#include <string>
using namespace std;

namespace utils
{
	class CUtils
	{
	public:

		static bool LeerInt(int& dato);
		static bool LeerFloat(float& dato);
		static bool LeerDouble(double& dato);
		static int CrearMenu(const char* opciones_menu[], int num_opciones);
		static bool LeerDato(string& dato);
		static bool LeerDato(char* dato);
		static char* ConverMayus(char* str);
		static string& ConverMayus(string& str);
	};
};
