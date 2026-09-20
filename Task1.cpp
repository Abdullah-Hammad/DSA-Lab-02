#include <iostream>
using namespace std;

int main(){
    // Declaring variables
    int sales[5];
    int *p = sales;

    // Taking input from user
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter sales for day " << i + 1 << ": ";
        cin >> *(p + i);
    }

    int total = 0;
    
    // Adding 2 to the third entry with pointer
    *(p + 2) += 2;

    cout << "\nSales for each day: ";
    for (int i = 0; i < 5; i++){
        cout << *(p + i) << endl;
        total += *(p + i);
    }

    cout << "Total sales: " << total;

    return 0;
}