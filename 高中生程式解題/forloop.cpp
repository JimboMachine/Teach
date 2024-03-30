#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    /*
    N=5
            *
           ***
          *****
         *******
        *********
         *******
          *****
           ***
            *
    */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-i-1; j++){
            cout << " ";
        }
        for(int j = 0;j <=i;j++){
            cout <<"*";
        }
        cout << endl;
    }    
}