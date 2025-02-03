#include<iostream>
using namespace std;
void maxNumber(int arr[] , int size){
    cout << "Enter " << size << " number: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    cout << "Maximun Number = " << max << endl;
}
int main(){
    static int size = 5;
    int arr[size];
    maxNumber(arr , size);
}
/*Time Complexity = 1 + n + n + 1 + n + n + n + 1 + 1 + 1
                  = 5n + 5;
                  = O(n) 
*/
                  