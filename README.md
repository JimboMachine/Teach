# 規劃
Quiz1 will be held on 10/29

考試內容之前教過的知識點以及一些基礎演算法

考試以紙筆進行

模擬題我已放上再Exam_info的資料夾，再請多加練習

# 課程
2023/09/17: Function and Recursion

2023/09/24: Function and Recursion For Loop

2023/10/01: Vector and Array

2023/10/10: Buble Sort and Selection Sort

2023/10/22: Quick Sort, Insertion Sort and Merge Sort 

2023/10/29: Quiz1

--TBD--

再兩次上課後的11月會進行一次上機考(代議)

## Function
回傳回來的資料型態 函數名稱(傳入資料型態 參數名稱,...){
    do something...;
    return ...;
}

Example:
```
int add(int a, int b){
    return a + b;
}
```

也等於

```
int add(int a, int b){
    int c = a + b;
    return c;
}
```

C++中，函數主要有四種類型，根據它們的返回類型和參數列表的不同而區分。這四種類型是：

1.無返回值，無參數的函數：
這種函數不返回任何值，也不接受任何參數。它通常用於執行某些特定的任務或操作，而不涉及輸入或輸出。
```
void myFunction() {
    do something
}
```

2.有返回值，無參數的函數：
這種函數返回一個值，但不接受任何參數。它根據一些內部邏輯或計算返回一個值。
```
int getRandomNumber() {
    do something
}
```

3.無返回值，有參數的函數：
這種函數不返回任何值，但接受一個或多個參數。它通常用於執行需要輸入參數進行操作的任務。
```
void printMessage(const std::string& message) {
    do something
}
```

4.有返回值，有參數的函數：
這種函數既返回一個值，又接受一個或多個參數。它用於執行基於輸入參數的計算，並將結果返回。
```
int add(int a, int b) {
    return a + b;
}
```

那你也可以不用這樣分，依據你的需求在function裡面做你想要他做的事情，function有時是為了Reused，有時是為了Readability，有些是function設計

## Recursion
遞迴（Recursion）是一種在程式設計中常見的技巧，它指的是一個函數可以呼叫自己。遞迴通常用於解決可以分解為較小但相似的子問題的問題，例如數學中的遞迴關係或樹狀結構的操作。在C++中，你可以使用遞迴來實現這種功能。

以下是一個簡單的範例，顯示如何使用遞迴計算階乘（factorial）：
```
#include <iostream>

// 定義遞迴函數計算階乘
int factorial(int n) {
    if (n == 1 || n == 0)
        return 1;
    
    else if(n < 0)
        return -1; 
    
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    int result = factorial(num);
    if(result == -1)
        std::cout <<　"ERROR" << std::endl;
    else
        std::cout << "階乘 " << num << " = " << result << std::endl;
    return 0;
}
```
## Vector
vector 底層實現是一個連續記憶體空間，當容量不夠的時候就會重新申請空間，並把原本資料複製或搬移到新的空間。

vector 的容器大小可以動態增長，但是並不意味著每一次插入操作都進行 reallocate。記憶體的分配與釋放耗費的資源是比較大的，因此應該減少它的次數。這也就意味著容器的容量(capacity)與容器目前容納的大小(size)是不等的，前者應大於後者。

### vector 常用功能
以下為 C++ std::vector 內常用的成員函式，

push_back：把元素加到尾巴，必要時會進行記憶體配置

pop_back：移除尾巴的元素

insert：插入元素

erase：移除某個位置元素, 也可以移除某一段範圍的元素

clear：清空容器裡所有元素

size：回傳目前長度

empty：回傳是否為空

[i]：隨機存取索引值為i的元素，跟陣列一樣索引值從 0 開始

at(i)：隨機存取索引值為i的元素，跟上面 operator[] 差異是 at(i) 會作邊界檢查，存取越界會拋出一個例外

reserve()：預先配置大小

## Sort
### 泡沫排序法(Bubble Sort)
https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2FHyyCFRj9d

### 選擇排序法(Selection sort)
https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2FHy4Cwch9u

### 題目:
請查閱
```HW=
Cplusplus
    -Exam_info
    -hw_description
        hw...
    -hw_solution
```