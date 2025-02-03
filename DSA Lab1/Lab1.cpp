#include<iostream>
using namespace std;
int main(){
    int num = 10;
    int *p;
    p = &num;
    *p = 15;
    cout << "Value of Num = " << num << endl;
    cout << "Value of P = " << *p << endl;
}