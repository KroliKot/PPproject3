#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <matplot/matplot.h>
#include <cmath>
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


PYBIND11_MODULE(Project3, yes)
{
    yes.def("SIGNAL", &SIGNAL, "generates signal");
    yes.def("AUDIO", &AUDIO, "generates audio");
}