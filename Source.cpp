#include <iostream>

const int MAX_SIZE = 100;

void deleteColumn(int array[][MAX_SIZE], int rows, int& cols, int columnNumber) {

    if (columnNumber < 0 || columnNumber >= cols) {
        std::cout << "Invalid column number\n";
        return;
    }

    for (int i = columnNumber; i < cols - 1; ++i) {
        for (int j = 0; j < rows; ++j) {
            array[j][i] = array[j][i + 1];
        }
    }

    --cols;
}

int main() {
    const int rows = 3;
    int cols = 3; 
    int myArray[rows][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    std::cout << "Original Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    int columnToDelete;
    std::cout << "Enter the column number to delete: ";
    std::cin >> columnToDelete;

    deleteColumn(myArray, rows, cols, columnToDelete);

    std::cout << "\nArray after deleting the column:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
