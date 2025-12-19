#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

typedef struct {
    float data[SIZE][SIZE];
} Matrix3x3;

void add_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res);

#endif