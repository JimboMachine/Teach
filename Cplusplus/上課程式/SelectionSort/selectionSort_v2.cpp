#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    cout << "original: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    selectionSort(arr);
    cout << "sorted: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}