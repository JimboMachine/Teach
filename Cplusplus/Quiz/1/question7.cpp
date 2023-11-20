#include <iostream>

using namespace std;

int f(int n) {
    if (n < 2) {
        return n;
    }
    else {
        return (n + f(n/2));	//(A)
    }
}

int main(){
    cout << f(14) << endl;  //25
    cout << f(10) << endl;  //18
    cout << f(6) << endl;   //10
    return 1;
}