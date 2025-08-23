#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
    int res = 1;
    if (result && rows >= 1 && columns >= 1) {
        res = 0;
        result->columns = columns;
        result->rows = rows;
        result->matrix = (double**)malloc(rows * sizeof(double*));
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = (double*)malloc(columns * sizeof(double));
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result->matrix[i][j] = 1;
            }
        }
    }
    return res;
}

void s21_remove_matrix(matrix_t* A) {
    if (A != NULL && A->matrix != NULL) {
        free(A->matrix);
        A->matrix = NULL;
    }
}

int s21_is_correct_matrix(matrix_t A) {
    int res = 0;
    if (!A.matrix || A.columns < 1 || A.rows < 1) {
        res = 1;
    }
    return res;
}

int s21_is_eq_size(matrix_t A, matrix_t B) {
    int res = 0;
    if (!(A.rows == B.rows && A.columns == B.columns)) {
        res = 1;
    }
    return res;
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
    
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!(s21_is_correct_matrix(*A) && s21_is_correct_matrix(*B) && result != NULL)) {
        return 1;
    }
    else if (!s21_is_eq_size(*A, *B)) {
        return 2;
    }
    int res = 0;
    res = s21_create_matrix(A->rows, A->columns, result);

}