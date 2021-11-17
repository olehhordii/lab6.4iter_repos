// llab6.4_iter.cpp
#include <iomanip>
#include <math.h>
#include <iostream>
using namespace std;

void CreateArray(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(int* a, const int size) {
    cout << " a[" << size << "] = " << "{";
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << " }" << endl;
}

int Dob(int* a, const int size) {
    int P = 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            P *= a[i];
        }
    }
    return P;
}
int IndexFirstNull(int* a, const int size) {
    int in = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            in = i;
            break;
        }
    }
    return in;

}
int IndexLastNull(int* a, const int size) {
    int ind = 0;
    for (int i = size; i > 0; i--) {
        if (a[i] == 0) {
            ind = i;
            break;
        }
    }
    return ind;

}
int SumNull(int* a, const int size) {
    int S = 0;
    int k = IndexFirstNull(a, size);
    int e = IndexLastNull(a, size);
    for (int i = k; i < e; i++) {
        S += a[i];

    }
    return S;

}
void SortMas(int* a, const int size) {
    for (int i = 0; i < size - 1; i++) // індекс початку невпорядкованої частини
    {
        int dod = a[i];
        int idod = i;
        for (int j = i + 1; j < size; j++)
            if (dod < a[j])
            {
                dod = a[j];
                idod = j;
            }
        a[idod] = a[i];
        a[i] = dod;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter length of array :  n = "; cin >> n;
    int* a = new int[n];
    int Low; cout << "Low = "; cin >> Low;
    int High; cout << "High = "; cin >> High;
    cout << "" << endl;


    CreateArray(a, n, Low, High);
    PrintArray(a, n);
    // cout << IndexFirstNull(a, n) << endl;
    // cout << IndexLastNull(a, n) << endl;
    cout << "Dobutok parniy nomer " << Dob(a, n) << endl;
    cout << "Sum from null to null = " << SumNull(a, n) << endl;
    SortMas(a, n);
    PrintArray(a, n);
    delete[]a;
    return 0;
}
