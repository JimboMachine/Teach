#include <iostream>
#include <vector>
using namespace std;

void forOps() {
    int i = 1;
    vector<string> myList = {"asm", "python", "C++", "Java", "iOS", "perl", "C#"};
    for (const string& index : myList) {
        if (index == "Java" || index == "python") {
            cout << i << " " << index << ", ";
        } else if (i % 2 != 0) {
            cout << i << " " << index << ", ";
            i = i + 1;
        } else {
            i = i + 1;
        }
    }
}

int main() {
    forOps();
    return 0;
}