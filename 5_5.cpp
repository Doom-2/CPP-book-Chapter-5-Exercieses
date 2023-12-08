#include "std_lib_facilities.h"

class CelsiusLowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature in Celsius can't be less than -273.15\n";
    }
};

class KelvinLowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature in Kelvin can't be less than 0\n";
    }
};

// converts Celsius to Kelvin
double ctok(double c)
{
    if (c < -273.15)
        throw CelsiusLowTempError();
    double k = c + 273.15;

    return k;
}

// converts Kelvin to Celsius
double ktoc(double k)
{
    if (k < 0)
        throw KelvinLowTempError();
    double c = k - 273.15;

    return c;
}

int main()
{
    double c = 0, k = 0;
    int conv_type = 0;
    try
    {
        cout << "Enter conversation type:\n"
             << "1: Celsius to Kelvin\n"
             << "2: Kelvin to Celsius\n>";
        cin >> conv_type;
        switch (conv_type)
        {
        case 1:
        {
            cout << "Enter temperature in Celsius\n>";
            cin >> c;
            double k = ctok(c);
            cout << "The temperature in Kelvin is " << k << '\n';
            break;
        }

        case 2:
        {
            cout << "Enter temperature in Kelvin\n>";
            cin >> k;
            double c = ktoc(k);
            cout << "The temperature in Celsius is " << c << '\n';
            break;
        }

        default:
        {
            cout << "Unknown value\n";
            break;
        }
        }
    }
    catch (CelsiusLowTempError &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    catch (KelvinLowTempError &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
