#include <iostream>
using namespace std;

int main(){

    int sales[2][3];
    int (*rowPtr)[3] = sales;

    // Read six values
    for (int r = 0; r < 2; r++){
        for (int c = 0; c < 3; c++){
            cout << "Enter sales for branch " << r + 1 << ", day " << c + 1 << ": ";

            cin >> *(*(rowPtr + r) + c);

        }
    }

    cout << "\nSales Table: \n";

    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << *(*(rowPtr + r) + c) << "\t";
        }
    }

    cout << "\nBranch Totals:\n";

    for (int r = 0; r < 2; r++)
    {
        int total = 0;

        for (int c = 0; c < 3; c++)
        {
            total += *(*(rowPtr + r) + c);
        }

        cout << "Branch " << r + 1 << " = " << total << endl;
    }

    cout << "\nDay Totals:\n";

    for (int c = 0; c < 3; c++)
    {
        int total = 0;

        for (int r = 0; r < 2; r++)
        {
            total += *(*(rowPtr + r) + c);
        }

        cout << "Day " << c + 1 << " = " << total << endl;
    }
}