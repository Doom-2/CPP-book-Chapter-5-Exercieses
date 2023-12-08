#include "std_lib_facilities.h";

// converts Celsius to Kelvin
double ctok(double c)
{
    double k = c + 273.15;
    return k;
}

class LowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature can't be less than -273.15\n";
    }
};

int main()
{
    double c = 0;
    try
    {
        cout << "Enter temperature in Celsius\n>";
        cin >> c;
        if (c < -273.15)
            throw LowTempError();
        double k = ctok(c);
        cout << "The temperature in Kelvin is " << k << '\n';
    }
    catch (LowTempError &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
