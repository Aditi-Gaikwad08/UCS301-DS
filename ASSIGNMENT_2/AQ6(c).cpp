#include <iostream>
using namespace std;

#define MAX 100

void display(int mat[MAX][3]) {
    int n = mat[0][2];
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << "\n";
    }
}

void createSparse(int mat[MAX][MAX], int row, int col, int sparse[MAX][3]) {
    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = k - 1;
}

void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible!\n";
        return;
    }

    int m = a[0][0], n = a[0][1], p = b[0][1];
    int result[MAX][MAX] = {0};

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                result[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            if (result[i][j] != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = result[i][j];
                k++;
            }
        }
    }
    c[0][0] = m;
    c[0][1] = p;
    c[0][2] = k - 1;
}

int main() {
    int r1, c1, r2, c2;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int s1[MAX][3], s2[MAX][3], prod[MAX][3];

    cout << "Enter rows and cols of Matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter rows and cols of Matrix 2: ";
    cin >> r2 >> c2;
    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }

    createSparse(mat1, r1, c1, s1);
    createSparse(mat2, r2, c2, s2);

    cout << "\nSparse Matrix 1:\n";
    display(s1);

    cout << "\nSparse Matrix 2:\n";
    display(s2);

    multiplySparse(s1, s2, prod);
    cout << "\nMultiplication (Sparse):\n";
    display(prod);

    return 0;
}