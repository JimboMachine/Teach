#include <iostream>

using namespace std;

int A[8] = {8,7,6,5,4,3,2,1};
int main () {
    int i, j;
    for (i=0; i<8; i=i+1){
        for (j=i; j<7; j=j+1){
            if (A[j] > A[j+1]){
                A[j] = A[j] + A[j+1];
                A[j+1] = A[j] - A[j+1];
                A[j] = A[j] - A[j+1];
            }   
        }
    }
    for(i=0; i<8; i=i+1){
        cout << A[i] << " ";
    }
}
