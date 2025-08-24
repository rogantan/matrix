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
                result->matrix[i][j] = 0;
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
    int res = 1;
    if (!A.matrix || A.columns < 1 || A.rows < 1) {
        res = 0;
    }
    printf("h");
    return res;
}

int s21_is_eq_size(matrix_t A, matrix_t B) {
    int res = 1;
    printf("eee");
    if (!(A.rows == B.rows && A.columns == B.columns)) {
        res = 0;
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
        printf("rfh");
        return 2;
    }
    
    int res = 0;
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            if (!isfinite(result->matrix[i][j])) {
                res = 2;
            }
        }
    }
    return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!(s21_is_correct_matrix(*A) && s21_is_correct_matrix(*B) && result != NULL)) {
        return 1;
    }
    else if (!s21_is_eq_size(*A, *B)) {
        return 2;
    }
    int res = 0;
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            if (!isfinite(result->matrix[i][j])) {
                res = 2;
            }
        }
    }
    return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    if (!(s21_is_correct_matrix(*A) && result != NULL)) {
        return 1;
    } 
    else if (!isfinite(number)) {
        return 2;
    }
    int res = 0;
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] * number;
            if (!isfinite(result->matrix[i][j])) {
                res = 2;
            }
        }
    }
    return res;
}