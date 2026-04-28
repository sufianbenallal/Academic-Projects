#include <iostream>
#include <vector>

using namespace std;

#define _CMATFLOAT_H_

class CMatFloat
{
private:
	vector<vector<float>> m_ppDatosF;	//Apunta a los datos de la matriz
	int m_nFilas;		//Numero de filas
	int m_nColumnas;	//Numero de columnas

public:

	void Iniciar();
	// Será invocada cada vez que se defina un objeto
   // Pone m_ppDatosF a NULL y m_nFilas y m_nColumnas a 0.
	void CrearMatriz2D(int nFilas, int nColumnas);
	// Asigna memoria para una matriz dinámica cuyas
   // dimensiones vienen dadas por los parámetros de tipo
	// entero que se le pasan y verifica que la asignación fue
	// correcta (en ningún caso deben quedar lagunas de memoria).
	// Pone la matriz a ceros. Asigna a los datos miembro
	// m_nFilas y m_nColumnas los valores adecuados.
	void CrearMatriz1D(int nElementos);
	// Método análogo al anterior pero para una dimensión.
	// Será implementado en función de CrearMatriz2D.
	void Introducir();
	// Establece los elementos de la matriz con los valores
	// que se introducen por teclado. Valida los datos introducidos
	// utilizando la funcionalidad proporcionada por utils.cpp.
	void Mostrar();
	// Vuelca en la pantalla los datos contenidos en la matriz.
	// Mostrar una fila debajo de otra, si procede.
	void Destruir();
	// Libera la memoria ocupada por los datos y llama a Iniciar.
};
