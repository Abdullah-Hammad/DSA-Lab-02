#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    // Read and validate rows
    while (true){
        cout << "Enter number of students (rows): ";
        cin >> rows;
        if (rows > 0)
            break;
        cout << "Invalid number. Try again.\n";
    }
    // Read and validate columns
    while (true){
        cout << "Enter number of subjects (columns): ";
        cin >> cols;
        if (cols > 0)
            break;

        cout << "Invalid number. Try again.\n";
    }
    // Allocate array of row pointers
    int** marks = new int*[rows];
    // Allocate columns for each row
    for (int i = 0; i < rows; i++){
        marks[i] = new int[cols];
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << "Enter mark for student " << r + 1
                 << ", subject " << c + 1 << ": ";

            cin >> *(*(marks + r) + c);
        }
    }

    int highestTotal = -1;
    int highestStudent = 0;

    for (int r = 0; r < rows; r++)
    {
        int total = 0;

        for (int c = 0; c < cols; c++)
        {
            total += *(*(marks + r) + c);
        }

        cout << "Student " << r + 1 << " total = " << total << endl;

        if (total > highestTotal)
        {
            highestTotal = total;
            highestStudent = r + 1;
        }
    }
    cout << "\nStudent with highest total: Student " << highestStudent << endl;
    cout << "Highest total: " << highestTotal << endl;

    for (int r = 0; r < rows; r++)
    {
        delete[] marks[r];
    }

    // Delete the row-pointer array
    delete[] marks;

    // Set pointer to nullptr
    marks = nullptr;

    return 0;
}