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

void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible!\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        } else {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }
    c[0][2] = k - 1;
}

int main() {
    int r, c, mat1[MAX][MAX], mat2[MAX][MAX];
    int s1[MAX][3], s2[MAX][3], sum[MAX][3];

    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter Matrix 1:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter Matrix 2:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat2[i][j];
        }
    }

    createSparse(mat1, r, c, s1);
    createSparse(mat2, r, c, s2);

    cout << "\nSparse Matrix 1:\n";
    display(s1);

    cout << "\nSparse Matrix 2:\n";
    display(s2);

    addSparse(s1, s2, sum);
    cout << "\nAddition (Sparse):\n";
    display(sum);

    return 0;
}