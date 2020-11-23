#include <iostream>
#include "TMatrix.h"
#include "HardSystem.h"


using namespace std;


int main()
{
	system("chcp 1251");
	system("cls");
	int n, k = 2;
	TMatrix<double> A(2);
	A[0][0] = -500.005;
	A[0][1] = 499.995;
	A[1][0] = A[0][1];
	A[1][1] = A[0][0];
	TVector<double> v(k);
	double x, h;
	cout << "Введите начальные значения функций \n";
	cin >> v;
	cout << "Введите начальную координату \n";
	cin >> x;
	cout << "Введите шаг \n";
	cin >> h;
	HardSystem method(A, v, x, h);
	cout << "Введите количество шагов \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		v = method.ImplicitRunKut();
		cout << "i = " << i << ", x = " << v[k] << ", h = " << v[k + 1] << ", ";
		cout << "v1 = " << v[0] << ", v2 = " << v[1] << endl;
	}

	system("pause");

	return 0;
}

