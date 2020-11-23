#include "HardSystem.h"


HardSystem::HardSystem(TMatrix<double> Am, TVector<double> V, double X, double H)
{
	A = Am;
	v = V;
	x = X;
	h = H;
	TMatrix<double> E(V.Size());
	E.SingleMatrix();
	cout << A << endl;
	cout << E << endl;
	ReverseM = (E - A * h*(3 + pow(3, 1 / 2)) / 6).ReverseMatrix();
	cout << ReverseM << endl;
}


TVector<double> HardSystem::ImplicitRunKut()
{
	int k = v.Size();
	TVector<double> res(k + 2), k1(k), k2(k);
	TMatrix<double> E = ReverseM * A;
	k1 = E * v;
	k2 = E * (v - k1 * h*pow(3, 1 / 2) / 3);
	v = v + (k1 + k2)*h / 2;
	x = x + h;
	for (int i = 0; i < k; i++)
		res[i] = v[i];
	//res[k] - значение координаты
	res[k] = x;
	//res[k + 1] - нзначение шага
	res[k + 1] = h;
	return res;
}

