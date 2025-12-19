#include "matrix_op.h"
#include <stdio.h>

void add_matrices(Matrix3x3 A, Matrix3x3 B, Matrix3x3 *res) {
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            res->data[i][j] = A.data[i][j] + B.data[i][j];
}
