#pragma once
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <limits>

using namespace std;

int LeerInt();
float LeerFloat();
int CrearMenu(char* opciones_menu[], int num_opciones);
void LeerCadena(char* c, int n);
char* ConverMayus(char* str);
string& ConverMayus(string& str);