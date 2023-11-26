#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &Array, int front, int mid, int end) {
    vector<int> LeftSub(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSub(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    int leftSize = LeftSub.size();
    int rightSize = RightSub.size();
    for (int i = front; i <= end; i++) {
        if (idxLeft < leftSize && (idxRight >= rightSize || LeftSub[idxLeft] <= RightSub[idxRight])) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else {
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &array, int front, int end){
    if (front < end) {
        int mid = (front+end)/2;
        MergeSort(array, front, mid);
        MergeSort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> array(arr, arr+sizeof(arr)/sizeof(int));
    cout << "original:\n";
    PrintArray(array);
    MergeSort(array, 0, 7);
    cout << "sorted:\n";
    PrintArray(array);
    return 0;
}