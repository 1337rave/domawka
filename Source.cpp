#include <iostream>

const int MAX_SIZE = 100; 

void addColumn(int array[][MAX_SIZE], int rows, int cols, int position, int newColumn[]) {

    if (position < 0 || position > cols) {
        std::cout << "Invalid position\n";
        return;
    }

    for (int i = cols; i > position; --i) {
        for (int j = 0; j < rows; ++j) {
            array[j][i] = array[j][i - 1];
        }
    }

    for (int i = 0; i < rows; ++i) {
        array[i][position] = newColumn[i];
    }

    ++cols;
}

int main() {
    const int rows = 3;
    const int cols = 3;
    int myArray[rows][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int newColumn[rows] = { 10, 11, 12 };

    std::cout << "Original Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Add a new column at position 1
    addColumn(myArray, rows, cols, 1, newColumn);

    std::cout << "\nArray after adding a column:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
