
#include <iostream>
#include "stdlib.h"
#include <cmath>
#include <math.h>
#include <fstream>
#include <stdio.h>

using namespace std;

double myDer(const double& x, const double& y)
{
    double f;
    f = (0.1 * y * y) + (3 * exp(-x));
    return f;
}

void stepEuler(double& x, double& y, const double& h)
{
    y += h * myDer(x, y);
    x += h;
}

void stepMidpoint(double& x, double& y, const double& h)
{
    double k1 = h * myDer(x, y);
    double k2 = h * myDer(x + h / 2.0, y + k1 / 2.0);
    x += h;
    y += k2;
}

void stepRK4(double& x, double& y, const double& h)
{
    double k1 = h * myDer(x, y);
    double k2 = h * myDer(x + h / 2.0, y + k1 / 2.0);
    double k3 = h * myDer(x + h / 2.0, y + k2 / 2.0);
    double k4 = h * myDer(x + h, y + k3);
    x += h;
    y += k1 / 6.0 + k2 / 3.0 + k3 / 3.0 + k4 / 6.0;
}

int main()
{
    double y(1.0);
    double x(0.0);
    double step(0.02);

    ofstream outfile("RK4-method.csv");
    if (!outfile)
    {
        cerr << "error: unable to open RK4-method.csv" << endl;
    }

std::cout << "Start RK4 method " << std::endl;
for (int i = 0; x < 2.0 && i < 100000; i++)
{
    stepRK4(x, y, step);
    std::cout << "x(" << i << ")= " << x << "   ";
    std::cout << "y(" << i << ")= " << y << std::endl;
    outfile << i << "," << x << "," << y << std::endl;
}
outfile.close();
system("pause");
return 0;
}