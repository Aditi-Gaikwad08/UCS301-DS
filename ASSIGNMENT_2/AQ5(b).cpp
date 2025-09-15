#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of matrix :";
    cin >> n;

    int arr[3 * n - 2];
    cout << "enter the numbers in row major order :";
    for (int i = 0; i < (3 * n - 2); i++)
    {
        cin >> arr[i];
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {

                cout << arr[k++] << " ";
            }
            else if (i == j + 1)
            {

                cout << arr[k++] << " ";
            }
            else if (j == i + 1)
            {

                cout << arr[k++] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}