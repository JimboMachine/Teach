#include <iostream>

using namespace std;

int a(int i) {
    if (i>0)
        if (((i/2)%2)==0)
            return a(i-2)*i;
        else
            return a(i-2)*(-i);
    else
        return 1;
}

int main(){
    cout << a(10) << endl;
}
