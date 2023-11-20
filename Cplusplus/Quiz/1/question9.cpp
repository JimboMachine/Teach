#include <iostream>

using namespace std;

int main(){
    int k = 4;
    int m = 1;
    for (int i=1; i<=5; i=i+1) {
        for (int j=1; j<=k; j=j+1) {
            cout << " ";
        }
        for (int j=1; j<=m; j=j+1) {
            cout << "*";
        }
        cout << endl;
        k = k - 1;
        m = m + 2;
    }
    return 0;
}