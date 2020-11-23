#pragma once

#ifndef HARDSYSTEM_H
#define HARDSYSTEM_H

#include <iostream>
#include <math.h>
#include "TMatrix.h"

using namespace std;

class HardSystem
{
private:
	TMatrix<double> A, ReverseM;
	TVector<double> v;
	double x, h;
public:
	HardSystem(TMatrix<double> Am, TVector<double> V, double X, double H);
	TVector<double> ImplicitRunKut();
	double GetX() { return x; }
	double GetH() { return h; }
	TVector<double> GetV() { return v; }
};


#endif

