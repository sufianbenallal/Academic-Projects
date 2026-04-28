#define _CMATFLOAT_H_


class CMatFloat // parecida a la estructura, pero en este caso aparte de tener detalles como punteros, filas y columnas, podemos añadir funciones 
	//dentro de la clase, que se aplicaran par cada "objeto" creado para dicha clase 
	//La clase equivale a la generalizacion de un tipo especifico de objetos que crearemos luego en el main
	// cada objeto que creemos de nuestra clase tednra luego sus propios datos
{
private:

	float** m_ppDatosF;			//Apunta a los datos de la matriz
	int m_nFilas;				//Numero de filas
	int m_nColumnas;			//Numero de columnas

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
	bool Existe();
	// Devuelve true si m_ppDatosF es distinto de NULL
	// (la matriz existe); en otro caso, devuelve false.

};
