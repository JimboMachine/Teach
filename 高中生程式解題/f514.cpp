#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findCards(string &S, const string &T) {
    vector<int> positions;
    for (char ch : T) {
        size_t pos = S.find(ch);
        if (pos != string::npos) {
            positions.push_back(pos + 1);
            S[pos] = ' ';
        } else {
            positions.push_back(-1);
        }
    }
    return positions;
}

int main() {
    string S, T;
    cin >> S >> T;

    vector<int> positions = findCards(S, T);

    for (int pos : positions) {
        if (pos == -1) {
            cout << "X ";
        } else {
            cout << pos << " ";
        }
    }
    cout << endl;

    return 0;
}


/*
{'t','c','a'} -> 線性
{'c','a','t'} -> 線性
i = 0
x[0] => 't'
if(x[i] == y[j] && words[j] == -1){
    words[j] = i+1;
}

*/