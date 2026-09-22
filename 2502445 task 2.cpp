#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int ROWS = 4;
    const int COLS = 5;

    // 1. Create and initialize 2D array (0 = Empty, 1 = Occupied)
    int parking[ROWS][COLS] = {
        {1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int occupiedCount = 0;
    int emptyCount = 0;

    // 2. Display complete parking layout and count occupancy
    cout << "=========================================================\n";
    cout << "               PARKING MANAGEMENT SYSTEM                 \n";
    cout << "=========================================================\n\n";
    cout << "Layout (0 = Empty, 1 = Occupied):\n\n";
    
    cout << "          Column 1   Col 2   Col 3   Col 4   Col 5\n";
    cout << "---------------------------------------------------------\n";

    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << (i + 1) << "  ";
        for (int j = 0; j < COLS; j++) {
            if (parking[i][j] == 1) {
                cout << setw(8) << "[ 1 ]";
                occupiedCount++; // 3. Count occupied spaces
            } else {
                cout << setw(8) << "[ 0 ]";
                emptyCount++;    // 4. Count empty spaces
            }
        }
        cout << "\n";
    }
    cout << "=========================================================\n\n";

    // 7. Display total parking capacity and current occupancy metrics
    int totalCapacity = ROWS * COLS;
    double occupancyRate = (static_cast<double>(occupiedCount) / totalCapacity) * 100;

    cout << "--- Parking Summary Statistics ---\n";
    cout << "Total Parking Capacity : " << totalCapacity << " spaces\n";
    cout << "Total Occupied Spaces  : " << occupiedCount << "\n";
    cout << "Total Empty Spaces     : " << emptyCount << "\n";
    cout << "Occupancy Rate         : " << fixed << setprecision(1) << occupancyRate << "%\n\n";

    // 5 & 6. Interactive lookup for specific space status
    int selectedRow, selectedCol;
    cout << "--- Check Space Availability ---\n";
    cout << "Enter Row number (1-" << ROWS << "): ";
    cin >> selectedRow;
    cout << "Enter Column number (1-" << COLS << "): ";
    cin >> selectedCol;

    // Validate 1-based user input against 0-based array indices
    if (selectedRow >= 1 && selectedRow <= ROWS && selectedCol >= 1 && selectedCol <= COLS) {
        int rIndex = selectedRow - 1;
        int cIndex = selectedCol - 1;

        if (parking[rIndex][cIndex] == 1) {
            cout << "\nStatus: Row " << selectedRow << ", Column " << selectedCol 
                 << " is OCCUPIED (1).\n";
        } else {
            cout << "\nStatus: Row " << selectedRow << ", Column " << selectedCol 
                 << " is AVAILABLE/EMPTY (0).\n";
        }
    } else {
        cout << "\nError: Invalid Row or Column input. Please select values within bounds.\n";
    }

    return 0;
}
