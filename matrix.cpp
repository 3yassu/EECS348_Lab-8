#include "matrix.hpp"
using namespace std;
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    vector<int> row (N);
    matrix_vector = vector<vector<int>>(N, row);
}
Matrix::Matrix(vector<vector<int>> nums){
    matrix_vector = nums;
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << (matrix_vector)[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}
Matrix Matrix::operator*(const Matrix &rhs) const {
    int size = matrix_vector.size();
    vector<vector<int>> matrix_return(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int dot_prod = 0;
            for(int k = 0; k < size; k++){
                dot_prod += matrix_vector[i][k]*rhs.get_value(k, j);
            }
            matrix_return[i][j] = dot_prod;
        }
    }
    Matrix returner(matrix_return);
    returner.print_matrix();
    return returner;
}
Matrix Matrix::operator+(const Matrix &rhs) const {
    int size = matrix_vector.size();
    vector<vector<int>> matrix_return(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix_return[i][j] = (matrix_vector[i][j] + (rhs.get_value(i, j)));
        }
    }
    Matrix returner(matrix_return);
    returner.print_matrix();
    return returner;
}
void Matrix::set_value(std::size_t i, std::size_t j, int n){
    std::size_t size = matrix_vector.size();
    if (i < size && j < size) {matrix_vector[i][j] = n;}
    print_matrix();
}
int Matrix::get_value(std::size_t i, std::size_t j) const {
    std::size_t size = matrix_vector.size();
    if (i < size && j < size) {return (matrix_vector)[i][j];}
    else{throw out_of_range("out_of_bounds");}
}
int Matrix::get_size() const{
    return matrix_vector.size();
}
int Matrix::sum_diagonal_major() const{
    int adder = 0; int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        adder += (matrix_vector)[i][i];
    }
    cout << adder << endl;
    return adder;
}
int Matrix::sum_diagonal_minor() const{
    int adder = 0; int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        adder += (matrix_vector)[i][size-i-1];
    }
    cout << adder << endl;
    return adder;
}
void Matrix::swap_rows(std::size_t r1, std::size_t r2){
    std::size_t size = matrix_vector.size();
    if (r1 < size && r2 < size) {
        vector<int> temp = matrix_vector[r1];
        matrix_vector[r1] = matrix_vector[r2];
        matrix_vector[r2] = temp;
    }
    print_matrix();

}
void Matrix::swap_cols(std::size_t c1, std::size_t c2){
    int size = matrix_vector.size();
    std::size_t sizet = matrix_vector.size();
    if (c1 < sizet && c2 < sizet) {
        vector<int> temp1 = {}; vector<int> temp2 = {};
        for(int i = 0; i < size; i++){
            temp1.push_back((matrix_vector)[i][c1]);
            temp2.push_back((matrix_vector)[i][c2]);
        }
        for(int j = 0; j < size; j++){
            (matrix_vector)[j][c1] = temp2[j];
            (matrix_vector)[j][c2] = temp1[j];
        }
    }
    print_matrix();
}