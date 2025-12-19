#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

typedef struct {
    float data[SIZE][SIZE];
} Matrix3x3;

void add_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res);
void sub_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res);
void elementwise_multiply(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res);

void multiply_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res);
void transpose(Matrix3x3 A, Matrix3x3 *res);

float determinant(Matrix3x3 A);
void adjoint(Matrix3x3 A, Matrix3x3 *res);
int inverse(Matrix3x3 A, Matrix3x3 *res);

#endif