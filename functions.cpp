#include <iostream>

#include "functions.h"

using std::cout;
using std::endl;

void printArr(int *arr, unsigned size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "\t";
        cout << endl;
    }
}

void printMatrix(int **arr, unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << (j < cols - 1 ? ", " : "\n");
        }

    }
}

void printMatrixByRows(int *matrix[], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        cout << "row " << i + 1 << ": {";

        for (unsigned j = 0; j < cols; ++j) {
            cout << matrix[i][j] << ((j == cols - 1) ? "}" : ", ");
        }

        cout << ((i == rows - 1) ? "." : ", ") << endl;
    }
}

void printMatrixByCols(int *matrix[], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < cols; ++i) {
        cout << "col[" << i + 1 << "]=(";

        for (unsigned j = 0; j < rows; ++j) {
            cout << matrix[j][i] << ((j == rows - 1) ? ")" : ", ");
        }

        cout << ((i == cols - 1) ? "." : "; ") << endl;
    }
}

void initIntDynArr(int **dynArray, unsigned rows, unsigned columns) {
    for (unsigned int i = 0; i < rows; ++i) {
        dynArray[i] = new int[columns];

    }
}

void deleteMatrix(int **matrix, unsigned rows) {
    for (unsigned i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    matrix = NULL;

    delete matrix;
}

bool isPrime(int number)
{
    int i;
    for (i=2; i<number; i++)
    { if(number % i==0)
            return false;
    }

    return true;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}


void fillArrWithRingElements(int *arr, unsigned n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
}

int modularAddition(int a, int b, int mod) {
//    int result = a + b;
//    return result >= mod ? result - mod : result;

    return (a + b) % mod;
}

int modularSubtraction(int a, int b, int mod) {
//    int res = a - b;
//    return res >= 0 ? res : res + mod;

    return (a - b + mod) % mod;
}

long long modularMultiplication(int a, int b, int mod) {
    return ((long long) a * b) % mod;
}

unsigned countPairs(int *ring, int mod) {
    unsigned pairs = 0;
    for (int i = 0; i < mod; ++i) {
        for (int j = 0; j < mod; ++j) {

            if (modularMultiplication(ring[i], ring[j], mod) == 1) {
                pairs++;
            }
        }
    }

    return pairs;
}

void findPairs(int *ring, int mod, int **resultMatrix) {

    unsigned pairsCounter = 0;
    for (int i = 0; i < mod; ++i) {
        for (int j = 0; j < mod; ++j) {

            if (modularMultiplication(ring[i], ring[j], mod) == 1) {
                resultMatrix[0][pairsCounter] = ring[i];
                resultMatrix[1][pairsCounter++] = ring[j];
            }
        }
    }


    printMatrix(resultMatrix, 2, pairsCounter);

}

int fastPow(int num, int pwr, int mod) {
    int ret = 1;
    for (; pwr > 0; pwr >>= 1) {
        if (pwr & 1)
            ret = ((long long) ret * num) % mod;
        num = ((long long) num * num) % mod;
    }
    return ret;
}

int modInverse(int b, int m)
{
    int x, y;
    int g = gcdExtended(b, m, &x, &y);

    if (g != 1)
        return -1;

    return (x%m + m) % m;
}

long long modularDivision1(int a, int b, int mod) {
    return modularMultiplication(a, fastPow(b, mod - 2, mod), mod);
}

int modularDivision2(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1) {
        return inv;
    }
    else {
        return (inv * a) % m;
    }
}

bool isRingField(int mod) {
    return isPrime(mod);
}

