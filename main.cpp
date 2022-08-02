#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    cout << "Enter mod" << endl;
    unsigned mod;
    cin >> mod;

    int *ring = new int[mod];
    fillArrWithRingElements(ring, mod);

    cout << "Enter a" << endl;
    int a;
    cin >> a;

    cout << "Enter b" << endl;
    int b;
    cin >> b;

    cout << "Modular addition: "  << modularAddition(a, b, mod) << endl;

    cout << "Modular subtraction: " << modularSubtraction(a, b, mod) << endl;

    cout << "Modular multiplication :" << modularMultiplication(a, b, mod) << endl;

    cout << "Pairs: " << endl;
    int **matrix = new int *[2];
    unsigned pairsCount = countPairs(ring, mod);
    initIntDynArr(matrix, 2, pairsCount);

    findPairs(ring, mod, matrix);

    cout << "Modular division: " << modularDivision2(432, 10, 7) << endl;

    cout << "Fast pow: " << fastPow(5, 2, mod) << endl;

    cout << "Is Ring Field: " << isRingField(mod) << endl;

    ring = NULL;
    delete[] ring;

    matrix = NULL;
    deleteMatrix(matrix, 2);

    return 0;
}