#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "ERROR" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}