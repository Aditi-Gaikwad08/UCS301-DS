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

void transposeSparse(int s[MAX][3], int t[MAX][3]) {
    int rows = s[0][0], cols = s[0][1], n = s[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = n;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[j][1] == i) {
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }
}

int main() {
    int r, c, mat[MAX][MAX], s[MAX][3], trans[MAX][3];

    cout << "Enter rows and cols of matrix: ";
    cin >> r >> c;

    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    createSparse(mat, r, c, s);
    cout << "\nSparse Matrix:\n";
    display(s);

    transposeSparse(s, trans);
    cout << "\nTranspose (Sparse):\n";
    display(trans);

    return 0;
}