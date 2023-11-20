#include <iostream>

using namespace std;

int f1(int arg),f2(int arg);
int f1(int arg){
    cout << arg <<endl;
    if(arg <= 0)
        return 0;
    if(arg % 2 == 0)
        return arg*f2(arg-1);
    return -arg*f1(arg-1);
}
int f2(int arg){
    cout << arg <<endl;
    if(arg <= 1)
        return 1;
    if(arg % 2 == 0)
        return arg+f2(arg-1);
    return arg-f1(arg-1);
}

int main() {
    int N = 5,ans;
    ans = f1(5);
    cout << ans;
    return 0;
}