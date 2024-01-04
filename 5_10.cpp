#include "std_lib_facilities.h"

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
    vector<double> nums;
    vector<double> diffs;
    int num, sum = 0;
    cout << "Enter the number of summands\n>";
    num = cin_positive_int();
    cout << "Enter doubles through space. Terminate input with '|'\n>";
    try
    {
        for (double i; cin >> i;)
        {
            nums.push_back(i);
        }

        if (num > nums.size())
            throw VectorSizeOverflow();

        for (int i = 0; i < num; ++i)
        {
            sum += nums[i];
            if (i > 0)
                diffs.push_back((nums[i] >= nums[i-1]) ? (nums[i] - nums[i-1]) : abs(nums[i] - nums[i-1]));
        }
        cout << "The sum of the first " << num << " values is " << sum << endl;
        cout << "Differences between adjacent values are\n";
        for (double diff : diffs)
            cout << diff << endl;
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
