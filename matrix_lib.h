#ifndef MATRIXLIB_H
#define MATRIXLIB_H

struct Matrix {
    int height;
    int width;
    int** matrix;
};

void printMatrix(struct Matrix* matrix);
struct Matrix* matrixAddition(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result);
struct Matrix* matrixSubtraction(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result);
struct Matrix* multiplyMatrix(struct Matrix* matrix1, struct Matrix* matrix2, struct Matrix* result);
struct Matrix* manualFilling(struct Matrix* matrix);
struct Matrix* randomFilling(struct Matrix* matrix);
void deleteMatrix(struct Matrix* matrix);
struct Matrix* createMatrix(int height, int width);
struct Matrix* fillingMatrix(struct Matrix* matrix);
struct Matrix* copyMatrix(struct Matrix* sourse);
struct Matrix* transposeMatrix(struct Matrix* matrix);

#endif
