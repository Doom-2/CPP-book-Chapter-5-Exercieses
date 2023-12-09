#include "std_lib_facilities.h"

class CelsiusLowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature in Celsius can't be less than -273.15\n";
    }
};

class FahrenheitLowTempError
{

public:
    const char *what()
    {
        return "\nError!\nThe temperature in FahrenheitLowTempError can't be less than -459.67\n";
    }
};

// rounds a value to n decimal places according to the precision, using the rounding rule of natural numbers
double round_d(double var, int precision = 2)
{
    if (precision < 0)
        precision = 0;
    return round(var * pow(10, precision)) / pow(10, precision);
}

// converts Celsius to Kelvin
double ctof(double c)
{
    if (c < -273.15)
        throw CelsiusLowTempError();
    double f = 9.0 / 5 * c + 32;

    return f;
}

// converts Kelvin to Celsius
double ftoc(double f)
{
    if (f < -459.67)
        throw FahrenheitLowTempError();
    double c = (f - 32) * 5 / 9;

    return c;
}

int main()
{
    double c = 0, f = 0;
    int conv_type = 0;
    try
    {
        cout << "Enter conversation type:\n"
             << "1: Celsius to Fahrenheit\n"
             << "2: Fahrenheit to Celsius\n>";
        cin >> conv_type;
        switch (conv_type)
        {
        case 1:
        {
            cout << "Enter temperature in Celsius\n>";
            cin >> c;
            double f = ctof(c);
            cout << "The temperature in Fahrenheit is " << round_d(f) << '\n';
            break;
        }

        case 2:
        {
            cout << "Enter temperature in Fahrenheit\n>";
            cin >> f;
            double c = ftoc(f);
            cout << "The temperature in Celsius is " << round_d(c) << '\n';
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
        cerr << ex.what() << '\n';
    }

    catch (FahrenheitLowTempError &ex)
    {
        cerr << ex.what() << '\n';
    }
}
