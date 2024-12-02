#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_lib.h"

struct Matrix {
    int height;
    int width;
    int** matrix;
};

void printMatrix(struct Matrix* matrix) {
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

struct Matrix* matrixAddition(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result) {
    for (int i = 0; i < matrix1->height; i++) {
        for (int j = 0; j < matrix1->width; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
    return result;
}

struct Matrix* matrixSubtraction(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result) {
    for (int i = 0; i < matrix1->height; i++) {
        for (int j = 0; j < matrix1->width; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
        }
    }
    return result;
}

struct Matrix* multiplyMatrix(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result) {
    for (int i = 0; i < matrix1->height; i++) {
        for (int j = 0; j < matrix2->width; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < matrix1->width; k++) {
                result->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
        }
    }
    return result;
}

struct Matrix* manualFilling(struct Matrix* matrix) {
    printf("Enter elements for the matrix:\n");
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            printf("matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix->matrix[i][j]);
        }
    }
    return matrix;
}

struct Matrix* randomFilling(struct Matrix* matrix) {
    int max_value;
    printf("Select the maximum value for the matrix elements: ");
    scanf("%d", &max_value);
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            matrix->matrix[i][j] = rand() % max_value + 1;
        }
    }
    return matrix;
}

void deleteMatrix(struct Matrix* matrix) {
    for (int i = 0; i < matrix->height; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

struct Matrix* createMatrix(int height, int width) {
    struct Matrix* matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
    matrix->height = height;
    matrix->width = width;
    matrix->matrix = (int**)malloc(matrix->height * sizeof(int*));
    for (int i = 0; i < matrix->height; i++) {
        matrix->matrix[i] = (int*)malloc(matrix->width * sizeof(int));
    }
    return matrix;
}

struct Matrix* fillingMatrix(struct Matrix* matrix) {
    int mode;
    printf("1 - manual filling\n2 - random filling: ");
    scanf("%d", &mode);
    if (mode == 1) {
        return manualFilling(matrix);
    } else {
        return randomFilling(matrix);
    }
}

struct Matrix* copyMatrix(struct Matrix* sourse) {
    struct Matrix* copy = createMatrix(sourse->height, sourse->width);

    for (int i = 0; i < sourse->height; i++) {
        for (int j = 0; j < sourse->width; j++) {
            copy->matrix[i][j] = sourse->matrix[i][j];
        }
    }

    return copy;
}

struct Matrix* transposeMatrix(struct Matrix* matrix) {
    struct Matrix* transposed = createMatrix(matrix->width, matrix->height);

    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            transposed->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return transposed;
}