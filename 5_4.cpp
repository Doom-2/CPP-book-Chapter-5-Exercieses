#include "std_lib_facilities.h";


class LowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature can't be less than -273.15\n";
    }
};


// converts Celsius to Kelvin
double ctok(double c)
{
    if (c < -273.15) throw LowTempError();
    double k = c + 273.15;
    return k;
}


int main()
{
    double c = 0;
    try
    {
        cout << "Enter temperature in Celsius\n>";
        cin >> c;
        double k = ctok(c);
        cout << "The temperature in Kelvin is " << k << '\n';
    }
    catch (LowTempError &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
