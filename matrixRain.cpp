#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <thread>    // For sleep_for
#include <chrono>    // For chrono::milliseconds
using namespace std;

// Dimensions of the matrix
const int ROWS = 20;
const int COLS = 40;

// Function to initialize the matrix
void initializeMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << (matrix[i][j] == 1 ? "1" : "0");
        }
        cout << endl;
    }
}

// Function to update the matrix for a falling effect
void updateMatrix(vector<vector<int>> &matrix) {
    for (int j = 0; j < COLS; ++j) {
        // Move the entire column down by one row
        for (int i = ROWS - 1; i > 0; --i) {
            matrix[i][j] = matrix[i - 1][j];
        }
        // Randomly assign 0 or 1 to the top row
        matrix[0][j] = rand() % 2;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    // Initialize the matrix with random 0s and 1s
    vector<vector<int>> matrix(ROWS, vector<int>(COLS, 0));
    initializeMatrix(matrix);

    // Simulate the falling binary matrix effect
    while (true) {
        printMatrix(matrix);
        updateMatrix(matrix);

        // Sleep for a short duration to create a falling effect
        this_thread::sleep_for(chrono::milliseconds(200));

        // Clear the console screen (platform-dependent)
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    return 0;
}

