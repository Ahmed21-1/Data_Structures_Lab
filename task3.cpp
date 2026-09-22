#include <iostream>
using namespace std;
int main() {
    //Matrix addition
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int sum[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    // Display Matrix A
    cout << "Matrix A:\n";
    for (int i = 0; i <=2 ; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matA[i][j] << "  ";
        }
        cout << "\n";
    }

    // Display Matrix B
    cout << "\nMatrix B:\n";
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matB[i][j] << "  ";
        }
        cout << "\n";
    }

    // Display Sum Matrix
    cout << "\n\nSum of Matrix A and B:\n\n";
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <=2; j++) {
            cout << sum[i][j] << "  ";
        }
        cout << "\n";
    }

    return 0;
}
