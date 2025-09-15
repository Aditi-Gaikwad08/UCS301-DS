#include <iostream>
using namespace std;

int findMissing(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1)
        {
            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }

    return left + 1;
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

    int missing = findMissing(arr, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}