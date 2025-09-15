#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of matrix :";
    cin >> n;

    int k = (n * (n + 1)) / 2;
    int arr[k];

    cout << "enter the elements in row major order :";
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                cout << arr[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}