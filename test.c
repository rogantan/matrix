#include <stdio.h>
#include "s21_matrix.h"

int main() {
    matrix_t matrix;
    s21_create_matrix(2, 2, &matrix);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            matrix.matrix[i][j] += 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%lf\t", matrix.matrix[i][j]);
        }
        printf("\n");
    }
    s21_remove_matrix(&matrix);
    return 0;
}