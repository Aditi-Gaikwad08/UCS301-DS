#include<iostream>
using namespace std;
int main(){

    int n,arr[50];
    cout <<"enter the number of elements: ";
    cin >> n;
    cout << "enter " << n << " elements: ";
    for(int i=0 ; i < n ; i++){
    cin >> arr[i];
    }

    for( int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i] == arr[j]){

                for( int k=j ; k<n-1 ; k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

                
                
}