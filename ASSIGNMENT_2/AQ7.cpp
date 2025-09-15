#include <iostream>
using namespace std;

int countInversions(int arr[], int n)
{
    int invCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                invCount++;
            }
        }
    }

    return invCount;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Total inversions: " << countInversions(arr, n) << endl;

    return 0;
}