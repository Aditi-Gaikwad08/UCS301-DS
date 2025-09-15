#include <iostream>
using namespace std;

int findMissing(int arr[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n;
}

int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int missing = findMissing(arr, n - 1, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}