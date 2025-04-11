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
    string filename;
    cout << "Enter filename (with .txt): ";
    cin >> filename;
    pair<vector<vector<int>>, vector<vector<int>>> matrix = readMatrixFromFile(filename);
    Matrix bot(matrix.first);
    Matrix tob(matrix.second);
    bot+tob;
    bot*tob;
    cout << "major Diagonal: ";
    bot.sum_diagonal_major();
    cout << "minor diagonal: ";
    bot.sum_diagonal_minor();
    int matrix_check;
    while(true){
        cout << "which matrix do you want to manipulate for the rest of the program (1 or 2): ";
        cin >> matrix_check;
        if(!(matrix_check <= 2 && matrix_check >= 1)){cout << "Not a valid number, try again (1 or 2)" << endl;}
        else{break;}
    }
    while(true) {
        int col_one; int col_two; 
        cout << endl << "enter column 1 (starting at 0): ";
        cin >> col_one;
        cout << endl << "enter column 2 (starting at 0): ";
        cin >> col_two; cout << endl;
        int size = matrix_check == 1? bot.get_size() : tob.get_size();
        if(!(col_one >= 0 && col_two >= 0 && col_one < size && col_two < size)){cout << "Not a valid number, columns has to be greater than 0 and less than " << size << endl; continue;}
        if(matrix_check == 1){
            bot.swap_cols(col_one, col_two);
        }else{
            tob.swap_cols(col_one, col_two);
        }
        break;
    }
    while(true) {
        int row_one; int row_two; 
        cout << endl << "enter row 1 (starting at 0): ";
        cin >> row_one;
        cout << endl << "enter row 2 (starting at 0): ";
        cin >> row_two; cout << endl;
        int size = matrix_check == 1? bot.get_size() : tob.get_size();
        if(!(row_one >= 0 && row_two >= 0 && row_one < size && row_two < size)){cout << "Not a valid number, rows has to be greater than 0 and less than " << size << endl; continue;}
        if(matrix_check == 1){
            bot.swap_rows(row_one, row_two);
        }else{
            tob.swap_rows(row_one, row_two);
        }
        break;
    }
    while(true) {
        int pos_one; int pos_two; int value;
        cout << endl << "enter position i (starting at 0): ";
        cin >> pos_one;
        cout << endl << "enter position j (starting at 0): ";
        cin >> pos_two;
        cout << endl << "Enter value: ";
        cin >> value; cout << endl;
        int size = matrix_check == 1? bot.get_size() : tob.get_size();
        if(!(pos_one >= 0 && pos_two >= 0 && pos_one < size && pos_two < size)){cout << "Not a valid number, positions has to be greater than 0 and less than " << size << endl; continue;}
        if(matrix_check == 1){
            bot.set_value(pos_two, pos_one, value);
        }else{
            tob.set_value(pos_two, pos_one, value);
        }
        break;
    }
    return 0;
}

