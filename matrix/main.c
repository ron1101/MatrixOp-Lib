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

    return 0;
}