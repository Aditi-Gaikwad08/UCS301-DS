#include<iostream>
using namespace std;

int main() {
    int m, p, n;
    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter rows and columns of first matrix (m p): ";
    cin >> m >> p;
    cout << "Enter rows and columns of second matrix (p n): ";
    cin >> p >> n;

    cout << "Enter first matrix: \n";
    for(int i=0; i<m; i++)
        for(int j=0; j<p; j++)
            cin >> A[i][j];

    cout << "Enter second matrix: \n";
    for(int i=0; i<p; i++)
        for(int j=0; j<n; j++)
            cin >> B[i][j];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            C[i][j] = 0;
            for(int k=0; k<p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix: \n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
