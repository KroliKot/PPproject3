#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

std::string TEST()
{
return "napis";
}

PYBIND11_MODULE(Project3, yes)
{
    yes.def("TEST", &TEST, "TESTUJE");
}