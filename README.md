# 規劃
看情況調整

# 課程
2023/09/17: Function Recursion

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

以下是一個簡單的示例，顯示如何使用遞迴計算階乘（factorial）：
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
### 題目:
1.GPA