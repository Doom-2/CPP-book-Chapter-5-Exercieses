#include "std_lib_facilities.h"
#include <limits.h>

class NotDigitError
{

public:
    const char *what()
    {
        return "\nError!\nNot a digit\n";
    }
};

class DigitMismatchError
{

public:
    const char *what()
    {
        return "\nError!\nThe number of digits are mismatched\n";
    }
};

class NumberUniqueError
{

public:
    const char *what()
    {
        return "\nError!\nDigits in the number are not unique\n";
    }
};

// Executes <cin> with a check for positive integers. Throws an error otherwise
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

// Checks if string contains only digits or not
bool IsAllDigits(string s)
{
    return regex_match(s, regex("\\d+"));
}

// Checks if the digits in the number are unique or not
bool IsNumberUnique(string num)
{
    string sorted_num = num;
    sort(sorted_num);
    for (int i = 0, cur_reps = 1; i < sorted_num.size(); i++)
    {
        if (i < sorted_num.size() - 1 && sorted_num[i] == sorted_num[i + 1])
            return false;
    }
    return true;
}

// Counts the number of character matches by index in 2 strings
int bull(string s1, string s2)
{
    int matches_num = 0;
    if (!IsAllDigits(s1) || !IsAllDigits(s2))
        throw NotDigitError();

    else if (s1.size() != s2.size())
        throw DigitMismatchError();

    else if (!IsNumberUnique(s1))
        throw NumberUniqueError();

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] == s2[i])
            matches_num++;
    return matches_num;
}

// Counts the number of character matches in different positions of 2 strings
int cow(string s1, string s2)
{
    int matches_num = 0;
    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i] && s1.find(s2[i]) != string::npos)
            matches_num++;
    return matches_num;
}

int main()
{
    string s1, s2;
    int seed, d;
    while (true)
    {
        s2 = {};
        cout << "Enter 1 digit for seed value and press Enter\nTo exit the program press Ctrl+C (Linux, Mac) or Ctrl+D (Windows)\n>";
        seed = cin_positive_int();
        srand(seed);
        cout << "Enter 4 different digits and press Enter\n>";
        cin >> s1;

        // generate 4 digits and add them sequentially to the string 
        for (int i = 0; i < 4; i++)
        {
            d = rand() % 10;
            auto s = to_string(d);
            s2 += s;
        }
        
        try
        {
            cout << s2 << " - random" << endl;
            cout << bull(s1, s2) << " bull(s) " << cow(s1, s2) << " cow(s)" << endl;
        }
        catch (NotDigitError &e)
        {
            cerr << e.what() << '\n';
        }

        catch (DigitMismatchError &e)
        {
            cerr << e.what() << '\n';
        }

        catch (NumberUniqueError &e)
        {
            cerr << e.what() << '\n';
        }

        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }
}
