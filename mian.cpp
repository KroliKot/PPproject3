#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <matplot/matplot.h>
#include <cmath>
#include <iostream>
using namespace std;
using namespace matplot;
using namespace pybind11;

void SIGNAL(int chart)
{
    vector<double> x = linspace(0, 10 * pi, 10000);
    vector<double> y;
if (chart == 1)  y = transform(x, [](auto x) { return sin(x); });
if (chart == 2)  y = transform(x, [](auto x) { return cos(x); });
if (chart == 3)  y = transform(x, [](auto x) { return (sin(x)>0) ? 1: -1; });
if (chart == 4) 
{
    x=linspace(0, 8, 10000);
    y=transform(x, [](auto x) { return x-floor(x); });
}
plot(x,y);
show();
}

void AUDIO(vector<double> audio, double duration)
{
    vector<double> x = linspace(0, duration, audio.size());
    plot(x,audio);
    show();
}

void BILINEAR(double x1, double y1, double newx, double newy)
{
    double heigh, width;
	width = x1/newx;
	heigh = y1/newy;
	for (int i=0; i<newy; i++)
    {
	    for (int j=0; j<newx; j++)
        {
            double a,b;
			a = i * heigh;
			b = j * width;
			double x_floor = floor(a);
			double x_ceil = ceil(a);
			double y_floor = floor(b);
			double y_ceil = ceil(b);		
        }
    }
}


PYBIND11_MODULE(Project3, yes)
{
    yes.def("SIGNAL", &SIGNAL, "generates signal");
    yes.def("AUDIO", &AUDIO, "generates audio");
    yes.def("BILINEAR", &BILINEAR, "interpolation, which does not work, but can be turnet into image resizing");
}