#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void Merge(vector<T> &Array, int front, int mid, int end) {
    vector<T> LeftSub(Array.begin() + front, Array.begin() + mid + 1);
    vector<T> RightSub(Array.begin() + mid + 1, Array.begin() + end + 1);
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

template<typename T>
void MergeSort(vector<T> &array, int front, int end){
    if (front < end) {
        int mid = (front+end)/2;
        MergeSort(array, front, mid);
        MergeSort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}

template<typename T>
void PrintArray(vector<T> &array){
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
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