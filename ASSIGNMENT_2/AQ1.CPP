#include<iostream>
using namespace std;

void binarySearch( int arr[] , int size , int target , int &idx){

    int left = 0 ;
    int right = size - 1;

    while (left <= right ){
        int mid = left + (right - left ) / 2 ;
        if( arr[mid] == target ){
            idx = mid;
            break;
        }else if( arr[mid] < target ){
            left = mid + 1;
        }else {
            right = mid - 1;
        }

    }

}
int main () {

    int arr[50];
    int size;
    cout<<"Enter the size of the array :";
    cin>>size;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    int target ;
    cout<<"enter the value of target :";
    cin>>target;
    int idx = -1;

    binarySearch(arr , size , target , idx);

    cout << idx;
    return 0;
}