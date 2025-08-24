#include <stdio.h>
#include "s21_matrix.h"

int main() {
    matrix_t matrix1, matrix2, matrix3;
    s21_create_matrix(2, 2, &matrix1);
    s21_create_matrix(2, 2, &matrix2);
    s21_create_matrix(1, 1, &matrix3);
    // for (int i = 0; i < matrix1.rows; i++) {
    //     for (int j = 0; j < matrix1.columns; j++) {
    //         matrix1.matrix[i][j] = i + j + 1;
    //     }
    // }
    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][1] = 3;
    matrix1.matrix[1][0] = 4;
    //printf("rrf");
    // for (int i = 0; i < matrix2.rows; i++) {
    //     for (int j = 0; j < matrix2.columns; j++) {
    //         matrix2.matrix[i][j] = 3;
    //     }
    // }
    for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix1.columns; j++) {
                printf("%lf\t", matrix1.matrix[i][j]);
            }
            printf("\n");
        }
        // for (int i = 0; i < matrix2.rows; i++) {
        //     for (int j = 0; j < matrix2.columns; j++) {
        //         printf("%lf\t", matrix2.matrix[i][j]);
        //     }
        //     printf("\n");
        // }
    if (s21_transpose(&matrix1, &matrix3)) {
        printf("Error");
    }
    else {
        for (int i = 0; i < matrix3.rows; i++) {
            for (int j = 0; j < matrix3.columns; j++) {
                printf("%lf\t", matrix3.matrix[i][j]);
            }
            printf("\n");
        }
    }
    s21_remove_matrix(&matrix1);
    s21_remove_matrix(&matrix2);
    s21_remove_matrix(&matrix3);
    return 0;
}