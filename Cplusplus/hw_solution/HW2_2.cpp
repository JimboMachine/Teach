#include <iostream>

using namespace std;

int ERROR_JudgeMent(int N){
    if (N <= 0) {
        cout << "ERROR" << endl;
        return -1;
    }
    else if(N % 2 == 0){
        cout << "ERROR" << endl;
        return -1;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;

    if(ERROR_JudgeMent(N) == -1) {
        return -1;
    }

    for (int i = 1; i <= N; i+=2) {
       int step = (N-i)/2;
        for(int j = 1; j <= step; j++) {
            cout << " ";
        }

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    int temp = N-2;
    for (int i = temp; i >= 1; i-=2) {
       int step = (N-i)/2;
        for(int j = 1; j <= step; j++) {
            cout << " ";
        }

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}