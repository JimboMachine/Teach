#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int>& friendList, vector<bool>& visited) {
    if (visited[node]) return; // dfs
    visited[node] = true;
    dfs(friendList[node], friendList, visited);
}


int countGroups(vector<int>& friendList, int N) {
    vector<bool> visited(N, false);
    int groups = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, friendList, visited);
            groups++;
        }
    }
    return groups;
}

int main() {
    int N;
    cin >> N;
    vector<int> friendList(N);
    for (int i = 0; i < N; i++) {
        cin >> friendList[i];
    }
    cout << countGroups(friendList, N) << endl;
    return 0;


    std::string s;
    cin >> s;
    for(auto)
    Hi[""]
}
