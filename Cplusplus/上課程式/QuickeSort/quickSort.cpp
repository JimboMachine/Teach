#include <iostream>
#include <vector>
using namespace std;

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
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

void quicksort(std::vector<int>& arr, int low, int high) {
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
