#include <iostream>
#include "CPolinomio.h"
#include "MemoryManager.h"

using namespace std;

int main()
{
	{
		{
			CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
			CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

			P << m1 << m2 << -m4 << m3;
			Q << m4 << m1 << m2 << -m3;
			R << m3 << m4 << -m2;
			S << m2 << m3 << m4 << -m2;
			T << -m2 << -m3 << -m4 << m3;
			U << m2 << m3 << m4 << -m4;
			V << m2 << m3 << m4 << -m2 << -m3 << -m4;
			W << m2 << m3 << -m2 << -m3;
			X << m2 << -m2;
			Y << m2 << m3 << m4 << m2;
			Z << -m2 << -m3 << -m4 << -m3;
			N << m2 << m3 << m4 << m4;

			cout << endl << "Probando el operador de insercion de monomios(<<)" << endl;
			cout << "P = " << P << endl
				<< "Q = " << Q << endl
				<< "R = " << R << endl
				<< "S = " << S << endl
				<< "T = " << T << endl
				<< "U = " << U << endl
				<< "V = " << V << endl
				<< "W = " << W << endl
				<< "X = " << X << endl
				<< "Y = " << Y << endl
				<< "Z = " << Z << endl
				<< "N = " << N << endl;

			cout << endl << "Probando constructor copia (A(P))" << endl;
			CPolinomio A(P);
			cout << "A = " << A << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando operador de asignacion (B=Q)" << endl;
			CPolinomio B;
			B = Q;
			cout << "B = " << B << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "CPolinomio P = P: (evitar auto-asignacion)" << endl;
			P = P;
			cout << "P: " << P << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando el constructor con un coef. y un exp." << endl;
			CPolinomio C(2.5, 0);
			cout << "C = " << C << endl;
			CPolinomio D(2.5, 5);
			cout << "D = " << D << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando el constructor con un monomio" << endl;
			CPolinomio E(m4);
			cout << "E = " << E << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando la funcion Grado" << endl;
			int grado;
			grado = U.Grado();
			cout << "U = " << U << endl;
			cout << "El grado de U es: " << grado << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando el constructor con vector<CMonomio>" << endl;
			vector<CMonomio> v(3);
			v[0] = m4;
			v[1] = m3;
			v[2] = m2;
			CPolinomio F(v);
			cout << "F = " << F << endl << endl;
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando el operador >" << endl;
			int grado1, grado2;
			bool comparador;
			cout << "P =" << P << endl;
			grado1 = P.Grado();
			cout << "U =" << U << endl;
			grado2 = U.Grado();
			comparador = (grado1 > grado2);
			if (comparador == 1)
			{
				cout << "P tiene mayor grado que U" << endl << endl;
			}
			else
			{
				cout << "P tiene menor grado que U" << endl << endl;
			}
			system("pause");
			cout << endl;
			//---------------------------------------------------------
			cout << "Probando el operador ==" << endl;
			cout << "P =" << P << endl;
			grado1 = P.Grado();
			cout << "Q =" << Q << endl;
			grado2 = Q.Grado();
			comparador = (grado1 == grado2);
			if (comparador == 1)
			{
				cout << "P tiene igual grado que Q." << endl << endl;
			}
			else
			{
				cout << "P no tiene el mismo grado que Q." << endl << endl;
			}
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador - unario" << endl;
			cout << "Q = " << Q << endl;
			cout << "-Q = " << -Q << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador +" << endl;
			cout << "N = " << N << endl;
			cout << "U = " << U << endl;
			CPolinomio suma = N + U;
			cout << "N + U = " << suma << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador - y +=" << endl;
			cout << "R = " << R << endl;
			cout << "S = " << S << endl;
			cout << "R - S = " << (R - S) << endl;
			cout << "R += S " << (R += S) << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador -=" << endl;
			cout << "N = " << N << endl;
			cout << "Y = " << Y << endl;
			cout << "N -= Y " << (N -= Y) << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador []" << endl;  //muestra el coef del termino con el exponente que se ha indicado
			cout << "P = " << P << endl;
			cout << "Coeficiente de P[4] = " << P[4] << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador ()" << endl; //polinomio al sistituir por numeros
			CPolinomio G;
			G << CMonomio(3, 2) << CMonomio(-2, 1);
			cout << "G = " << G << endl;
			double y, x = 0.5;
			y = G(x);
			cout << "G(" << x << ") = " << y << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador *" << endl;
			cout << "Q = " << Q << endl;
			cout << "S = " << S << endl;
			cout << "Q * S " << (Q * S) << endl << endl;
			system("pause");
			cout << endl;
			//----------------------------------------------------------
			cout << "Probando el operador *=" << endl;
			cout << "P = " << P << endl;
			cout << "Q = " << Q << endl;
			cout << "P *= Q " << (P *= Q) << endl << endl;
			system("pause");
		}
	}
	cout << endl;
	MemoryManager::dumpMemoryLeaks();
	cout << endl;
	system("pause");
	return 0;
}
