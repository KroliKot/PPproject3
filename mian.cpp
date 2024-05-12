#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <matplot/matplot.h>
#include <cmath>
using namespace std;
using namespace matplot;
using namespace pybind11;

void TEST()
{
vector<double> x = linspace(0, 2 * pi, 1000);
vector<double> y = transform(x, [](auto x) { return sin(x); });
plot(x,y);
show();
}


PYBIND11_MODULE(Project3, yes)
{
    yes.def("TEST", &TEST, "TESTUJE");
}