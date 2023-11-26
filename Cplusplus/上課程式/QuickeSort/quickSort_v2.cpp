#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();
    std::cout << "Original array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    quicksort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
