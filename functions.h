#ifndef MODULAR_ARITHMETIC_FUNCTIONS_H
#define MODULAR_ARITHMETIC_FUNCTIONS_H

void printArr(int *arr, unsigned size);

void printMatrix(int **arr, unsigned rows, unsigned cols);

void printMatrixByRows(int *matrix[], unsigned rows, unsigned cols);

void printMatrixByCols(int *matrix[], unsigned rows, unsigned cols);

void initIntDynArr(int **dynArray, unsigned rows, unsigned columns);

void deleteMatrix(int **matrix, unsigned rows);

bool isPrime(int number);

int gcdExtended(int a, int b, int *x, int *y);

void fillArrWithRingElements(int *arr, unsigned n);

int modularAddition(int a, int b, int mod);

int modularSubtraction(int a, int b, int mod);

long long modularMultiplication(int a, int b, int mod);

unsigned countPairs(int *arr, int mod);

void findPairs(int *arr, int mod, int **resultMatrix);

int modInverse(int b, int m);

long long modularDivision1(int a, int b, int mod);

int modularDivision2(int a, int b, int mod);

int fastPow(int num, int pwr, int mod);

bool isRingField(int mod);

#endif //MODULAR_ARITHMETIC_FUNCTIONS_H
