#include <iostream>

using namespace std;

void f(int x, int y) {
    int tem = x;
    x = y;
    y = tem;
}
int main(){
    int x = 2, y = 3;
    f(x,y);
    cout << (x-y)*(x+y)/2;
    return 0;
}
