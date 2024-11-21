#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    int height, width;
    srand(time(NULL));

    printf("Creation of the first matrix\n");
    printf("Enter the size of the matrix (rows and columns):\n");
    scanf("%d %d", &height, &width);
    struct Matrix* matrix1 = createMatrix(height, width);
    matrix1 = fillingMatrix(matrix1);

    printf("Creation of the second matrix:\n");
    printf("Enter the size of the matrix (rows and columns):\n");
    scanf("%d %d", &height, &width);
    struct Matrix* matrix2 = createMatrix(height, width);
    matrix2 = fillingMatrix(matrix2);

    if (matrix1->width == matrix2->height) {
        struct Matrix* multiplicationResult = createMatrix(matrix1->height, matrix2->width);
        multiplyMatrix(matrix1, matrix2, multiplicationResult);
        printf("Result of multiplication:\n");
        printMatrix(multiplicationResult);
        deleteMatrix(multiplicationResult);
    } else {
        printf("Matrix multiplication is impossible.\n");
    }

    if (matrix1->height == matrix2->height && matrix1->width == matrix2->width) {
        struct Matrix* additionResult = createMatrix(matrix1->height, matrix1->width);
        matrixAddition(matrix1, matrix2, additionResult);
        printf("Result of addition:\n");
        printMatrix(additionResult);
        deleteMatrix(additionResult);

        struct Matrix* subtractionResult = createMatrix(matrix1->height, matrix1->width);
        matrixSubtraction(matrix1, matrix2, subtractionResult);
        printf("Result of subtraction:\n");
        printMatrix(subtractionResult);
        deleteMatrix(subtractionResult);
    } else {
        printf("Addition and subtraction of matrices is impossible.\n");
    }

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);

    return 0;
}
