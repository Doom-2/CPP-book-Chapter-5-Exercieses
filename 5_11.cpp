#include "std_lib_facilities.h"
#include <limits.h>

int cin_positive_int()
{
    int val;
    do
    {
        try
        {
            if (!(cin >> val))
                throw 1;
            if (cin.good() && val <= 0 && cin.peek() == '\n')
                throw 2;
            if (cin.peek() != '\n')
                throw 3;
        }
        catch (int i)
        {
            switch (i)
            {
            case 1:
            case 3:
                cerr << "Invalid input! Only integer is allowed.\n"
                     << ">";
                cin.clear();
                break;
            case 2:
                cerr << "Invalid input! An integer must be a positive.\n"
                     << ">";
                cin.clear();
                break;
            default:
                break;
            }
            while (cin.get() != '\n')
                ;
            continue;
        }
        break;
    } while (true);
    return val;
}

int main()
{
    vector<int> fib{};
    int num, max_index = 0;
    cout << "Enter the number of numbers\n>";
    num = cin_positive_int();
    cout << "The first " << num << " Fibonacci numbers\n>";
    try
    {
        for (int i = 0;; ++i)
        {
            if (i < 2)
            {
                fib.push_back(i);
                continue;
            }

            fib.push_back(fib[i - 2] + fib[i - 1]);
            if (fib[i] > INT_MAX - fib[i - 1])
            {
                max_index = i;
                break;
            }
        }

        cout << endl;
        cout << "The largest Fibonacci number that fits in an <int> is " << fib.back() << endl;

        for (int i = 0; i < num; ++i)
        {
            if (i > max_index)
                throw range_error("");
            cout << fib[i] << "  ";
        }
        cout << endl;
        return 0;
    }
    catch (range_error)
    {
        cerr << "\nRange error!\n"
                "The last element of current series does not fit into the <int>\n"
                "Maxumum number is "
             << max_index + 1 << endl;
    }
}
