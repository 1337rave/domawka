#include <iostream>

const int MAX_M = 100; // Maximum number of rows
const int MAX_N = 100; // Maximum number of columns

// Function to fill a matrix with values
void fillMatrix(int matrix[][MAX_N], int M, int N) {
    int value = 1;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = value++;
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][MAX_N], int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to perform cyclic shift of rows in the specified direction
void cyclicShiftRows(int matrix[][MAX_N], int M, int N, int shifts, bool leftDirection) {
    for (int i = 0; i < M; ++i) {
        for (int shift = 0; shift < shifts; ++shift) {
            int temp = leftDirection ? matrix[i][0] : matrix[i][N - 1];

            for (int j = 0; j < N - 1; ++j) {
                if (leftDirection) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                else {
                    matrix[i][N - 1 - j] = matrix[i][N - 2 - j];
                }
            }

            if (leftDirection) {
                matrix[i][N - 1] = temp;
            }
            else {
                matrix[i][0] = temp;
            }
        }
    }
}

// Function to perform cyclic shift of columns in the specified direction
void cyclicShiftColumns(int matrix[][MAX_N], int M, int N, int shifts, bool upDirection) {
    for (int j = 0; j < N; ++j) {
        for (int shift = 0; shift < shifts; ++shift) {
            int temp = upDirection ? matrix[0][j] : matrix[M - 1][j];

            for (int i = 0; i < M - 1; ++i) {
                if (upDirection) {
                    matrix[i][j] = matrix[i + 1][j];
                }
                else {
                    matrix[M - 1 - i][j] = matrix[M - 2 - i][j];
                }
            }

            if (upDirection) {
                matrix[M - 1][j] = temp;
            }
            else {
                matrix[0][j] = temp;
            }
        }
    }
}

int main() {
    int M, N;

    std::cout << "Enter the number of rows (M): ";
    std::cin >> M;

    std::cout << "Enter the number of columns (N): ";
    std::cin >> N;

    int matrix[MAX_M][MAX_N];

    fillMatrix(matrix, M, N);

    std::cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, M, N);

    int shifts;
    std::cout << "\nEnter the number of shifts: ";
    std::cin >> shifts;

    char direction;
    std::cout << "Enter the direction of shift (L/R/U/D for left/right/up/down): ";
    std::cin >> direction;

    switch (direction) {
    case 'L':
        cyclicShiftRows(matrix, M, N, shifts, true);
        break;
    case 'R':
        cyclicShiftRows(matrix, M, N, shifts, false);
        break;
    case 'U':
        cyclicShiftColumns(matrix, M, N, shifts, true);
        break;
    case 'D':
        cyclicShiftColumns(matrix, M, N, shifts, false);
        break;
    default:
        std::cout << "Invalid direction\n";
        return 1;
    }

    std::cout << "\nMatrix after cyclic shift:\n";
    printMatrix(matrix, M, N);

    return 0;
}
