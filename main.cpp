#include "matrix.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> readMatrixFromFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    int N;
    file >> N;
    vector<vector<int>> firstMatrix(N, vector<int>(N));
    vector<vector<int>> secondMatrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> firstMatrix[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> secondMatrix[i][j];
        }
    }
    file.close();
    return {firstMatrix, secondMatrix};
}

int main() {
    string filename = "matrix.txt";
    auto [matrix1, matrix2] = readMatrixFromFile(filename);

    Matrix bot(matrix1);
    Matrix tob(matrix2);
    bot+tob;
    bot*tob;
    bot.sum_diagonal_major();
    bot.sum_diagonal_minor();
    bot.swap_cols(1, 2);
    bot.swap_rows(1, 2);
    bot.set_value(1, 1, 0);
    return 0;
}

