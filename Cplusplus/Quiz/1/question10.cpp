#include <iostream>

using namespace std;

int q10(int n, int m) {
    if (n < 10) {
        if (m < 10) {
            return n + m ;
        }
        else {
            return q10(n, m-2) + m ;
        }
    }
    else {
        return q10(n-1, m) + n ;
    }
}

int main(){
    cout << q10(13,15);
    return 0;
}