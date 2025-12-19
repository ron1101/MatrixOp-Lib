#include <stdio.h>
#include "matrix_op.h"

void print_m(const char* label, Matrix3x3 M) {
    printf("--- %s ---\n", label);
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) printf("%.2f\t", M.data[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    Matrix3x3 A = {{{1, 2, 3}, {0, 1, 4}, {5, 6, 0}}};
    Matrix3x3 B = {{{2, 0, 1}, {3, 0, 0}, {1, 2, 1}}};
    Matrix3x3 res;

    add_matrices(A, B, &res);
    print_m("1. Addition (A + B)", res);

    sub_matrices(A, B, &res);
    print_m("2. Subtraction (A - B)", res);

    elementwise_multiply(A, B, &res);
    print_m("3. Element-wise Multiply (A o B)", res);

    multiply_matrices(A, B, &res);
    print_m("4. Matrix Multiplication (AB)", res);

    transpose(A, &res);
    print_m("5. Transpose of A", res);

    float det = determinant(A);
    printf("6. Determinant of A: %.2f\n\n", det)

    adjoint(A, &res);
    print_m("7. Adjoint Matrix of A", res);

    if (inverse(A, &res)) {
        print_m("8. Inverse Matrix of A", res);
    } else {
        printf("8. Inverse: 無法計算 (行列式為 0)\n");
    }

    return 0;
}