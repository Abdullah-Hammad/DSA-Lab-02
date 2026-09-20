#include <iostream>
using namespace std;

int main(){

    int n;

    while(true) {
        cout << "Enter the number of students: ";
        cin >> n;

        if (n <= 0){
            cout << "Invalid. Number must be greater than 0\n";
        }
        else {
            break;
        }
    }

    int* marks = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> *(marks + i);
    }
    int total = 0;
    int passed = 0;

    cout << "\nMarks: ";

    for (int i = 0; i < n; i++)
    {
        cout << *(marks + i) << ", ";

        total += *(marks + i);

        if (*(marks + i) >= 50)
        {
            passed++;
        }
    }

    // Calculate average
    double average = static_cast<double>(total) / n;

    cout << "\nTotal: " << total << "; Average: " << average << "; Pass Count: " << passed;

    delete[] marks;
    marks = nullptr;

    return 0;
}