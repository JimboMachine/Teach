#include <iostream>

using namespace std;

double get_area(double length, double width = 3, double height = 2) {
    return length * width * height;
}

int main() {
    double result1 = get_area(5);
    double result2 = get_area(5, 6);

    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;

    return 0;
}