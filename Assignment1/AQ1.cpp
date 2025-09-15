#include<iostream>
using namespace std;
int main(){
    int arr[100],n,choice;

    do{
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                cout <<"enter the number of elements: ";
                cin >> n;
                cout << "enter " << n<< " elements";
                for(int i=0 ; i < n ; i++){
                    cin >> arr[i];
                }
                break;
                }

            case 2: {
                
                cout << "Displaying Array: ";
                for(int i=0 ; i < n ; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                int pos, value;
                cout << "enter the position and value: ";
                cin >> pos >> value ;

                for(int i=n ; i >= pos ; i--){
                    arr[i] = arr[i-1];
                }
                arr[pos-1] = value;
                n++;
                break;
            }

            case 4: {

                int pos;
                cout << "enter the postion: ";
                cin >> pos;
                 for(int i=pos-1 ; i<n-1 ; i++){
                    arr[i] = arr[i+1];
                }
                n--;
                break;
            }

            case 5: {
                int ele,found=0;
                cout << "enter the element to be searched: ";
                cin >> ele;

                for( int i=0 ; i<n ; i++){
                    if(arr[i] == ele){
                        cout << "element found at position: "<< i+1 <<endl;
                        found = 1;
                        break;
                    }
                }
                if (!found) cout << "Not found\n";
                }

                case 6: {cout << "exiting...\n" ;
                break;}
                default: cout << "Invalid choice!\n";
            }
        }while(choice != 6);

        return 0;
    }

