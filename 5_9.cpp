#include "std_lib_facilities.h"
#include <climits>

class VectorSizeOverflow
{

public:
    const char *what()
    {
        return "\nError!\nNumber of summands exceeded the vector size\n";
    }
};

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
    vector<int> nums;
    int num, sum = 0;
    cout << "Enter the number of summands\n>";
    num = cin_positive_int();
    cout << "Enter integers through space. Terminate input with '|'\n>";
    try
    {
        for (int i; cin >> i;)
        {
            nums.push_back(i);
        }

        if (num > nums.size())
            throw VectorSizeOverflow();

        for (int i = 0; i < num; ++i)
        {
            if (i > 0 && nums[i] > INT_MAX - sum)
                throw overflow_error("\nOverflow error!\nThe limit value range for <Int> type was exceeded during sum calculation\n");
            sum += nums[i];
        }
        cout << "The sum of the first " << num << " values is " << sum << endl;
        return 0;
    }

    catch (VectorSizeOverflow &e)
    {
        cerr << e.what();
    }

    catch (overflow_error &e)
    {
        cerr << e.what();
    }
}
