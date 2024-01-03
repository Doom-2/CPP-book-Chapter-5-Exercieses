#include <std_lib_facilities.h>

// Flushes the cin buffer
void flush_cin()
{
    while (cin.get() != '\n');
    cin.clear();
}


// Checks for positive integers, throws an error othewise.
// Returns an integer on success.
int cin_int()
{
    int val;
    do {
        try {
            if (!(cin >> val)) throw 1;
            if (cin.peek() != '\n') throw 2;
        }
        catch (int i) {
            if (i == 1) cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input! Only integer value is allowed.\n>";
            continue;
        }
        break;
    } while (true);
    return val;
}

int main()
{
    vector<string> days_of_the_week = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    vector<int> sunday_vals,
                monday_vals,
                tuesday_vals,
                wednesday_vals,
                thursday_vals,
                friday_vals,
                saturday_vals;
    vector<vector<int>> vals_by_day = 
    {
        sunday_vals,
        monday_vals,
        tuesday_vals,
        wednesday_vals,
        thursday_vals,
        wednesday_vals,
        thursday_vals,
        friday_vals,
        saturday_vals
    };
    string user_day{};
    int user_val, num_rejected{};

    const string GREETINGS = "\nEnter day of the week ignoring case and any integer value separated by a space, such as 'Wednesday 16' or 'monday -5'\n"
                             "You can enter the day shortened to 3 chars, e.g. 'Sun' instead of 'Sunday'\n"
                             "Terminate input with 'q'\n";
    const string INVALID_DAY_INPUT = "Error! The day of the week must contain at least 1 letter character (a-zA-Z)\n";

    cout << GREETINGS;

    while (true)
    {
        bool success = false;
        cout << ">";
        cin >>  user_day;
        // Check if the string contains at least one letter
        if (!any_of(user_day.begin(), user_day.end(), ::isalpha))
        {
            cout << INVALID_DAY_INPUT;
            flush_cin();
            continue;
        }

        if (user_day == "q" || user_day == "Q") { flush_cin(); break; }

        user_val = cin_int();

        // convert string to lower case
        for (int i = 0; i < user_day.size(); i++)
            user_day[i] = tolower(user_day[i]);

        // check if the entered day value matches the value from the vector, including common synonims like 'Sun' or 'Wed',
        // simultaneously count the number of rejected strings
        for (int i = 0; i < days_of_the_week.size(); i++)
             if (days_of_the_week[i].substr(0, 3) == user_day || days_of_the_week[i] == user_day)
             {
                success = true;
                cout << "Success!" << endl;
                vals_by_day[i].push_back(user_val);
                break;
             }

        if (!success)
            num_rejected += 1;
    cout << "Enter new pair (day of the week, value)" << endl;
    }

    // print out the results for each day of the week
    for (int i = 0; i < days_of_the_week.size(); i++)
    {
        int sum = 0;
        cout << endl << days_of_the_week[i] << endl;

        if (vals_by_day[i].size())
            for (int j = 0; j < vals_by_day[i].size(); j++)
            {
                sum += vals_by_day[i][j];
                cout << vals_by_day[i][j] << "  ";
            }
        else
            cout << "empty";

        cout << endl;

        if (sum)
            cout << "sum is " << sum << endl;
    }

    cout << endl << "Number of rejected values is " << num_rejected << endl;
    return 0;
}
