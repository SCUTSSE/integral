#ifndef INTEGRAL_H
#define INTEGRAL_H

#include<string>
#include "RBTree.h"
using namespace std;

class integral
{
private:
	RBTree termdata;
	double upper;
	double lower;
public:
	integral(){};
	void input(string polyString);
	void input2(string polyString);
	string OriginFunction();
	double CalcuValue();
	string DifFunction();
};

#endif
