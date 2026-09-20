#include <iostream>
using namespace std;

int main(){
        int n;
 
    // Reading and validating n
    cout << "Enter number of students (1-10): ";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Error: n must be between 1 and 10." << endl;
        return 0;
    }
 
    int* marks = new int[n];
    cout << "Enter " << n << " marks:\n";
    for (int i = 0; i < n; i++)
        cin >> *(marks + i);
 
    int* newMarks = new int[n + 1];
 
    for (int i = 0; i < n; i++)
        *(newMarks + i) = *(marks + i);
 
    cout << "Enter the new student's mark: ";
    cin >> *(newMarks + n);
 
    delete[] marks;
 
    // Make the original pointer refer to the new block; update size
    marks = newMarks;
    n = n + 1;
    newMarks = nullptr;  

    cout << "\nUpdated marks list:\n";
    for (int i = 0; i < n; i++)
        cout << *(marks + i) << " ";
    cout << endl;

    delete[] marks;
    marks = nullptr;
 
    return 0;
}