#pragma once
#include<iostream>
#include<stdlib.h>
#include <string>
#include <limits>

using namespace std;
namespace utils
{
	class CUtils
	{
	public:
		static int CrearMenu(char* opciones_menu[], int num_opciones);
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(double& dato);
		static bool LeerDato(string& dato);
		static bool LeerDato(char* dato, int n);
		static char* ConverMayus(char* str);
		static string& ConverMayus(string& str);
	};
}

