#include "matrix_op.h"
#include <stdio.h>

void add_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res) {
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            res->data[i][j] = A.data[i][j] + B.data[i][j];
}

void sub_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            res->data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
}

void elementwise_multiply(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            res->data[i][j] = A.data[i][j] * B.data[i][j];
        }
    }
}

void multiply_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            res->data[i][j] = 0;
            for(int k=0; k<SIZE; k++)
                res->data[i][j] += A.data[i][k] * B.data[k][j];
        }
    }
}

void transpose(Matrix3x3 A, Matrix3x3 *res) {
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            res->data[j][i] = A.data[i][j];
}

float determinant(Matrix3x3 A) {
    float a = A.data[0][0], b = A.data[0][1], c = A.data[0][2];
    float d = A.data[1][0], e = A.data[1][1], f = A.data[1][2];
    float g = A.data[2][0], h = A.data[2][1], i = A.data[2][2];
    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

void adjoint(Matrix3x3 A, Matrix3x3 *res) {
    Matrix3x3 cofactor;
    float (*m)[SIZE] = A.data;
    
    cofactor.data[0][0] =  (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    cofactor.data[0][1] = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    cofactor.data[0][2] =  (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    
    cofactor.data[1][0] = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
    cofactor.data[1][1] =  (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
    cofactor.data[1][2] = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);
    
    cofactor.data[2][0] =  (m[0][1]*m[1][2] - m[0][2]*m[1][1]);
    cofactor.data[2][1] = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);
    cofactor.data[2][2] =  (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
    
    transpose(cofactor, res);
}

int inverse(Matrix3x3 A, Matrix3x3 *res) {
    float det = determinant(A);
    if (det == 0) return 0;
    
    Matrix3x3 adj;
    adjoint(A, &adj);
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            res->data[i][j] = adj.data[i][j] / det;
    return 1;
}