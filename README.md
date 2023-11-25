# 規劃


# 課程
2023/09/17: Function and Recursion

2023/09/24: Function and Recursion For Loop

2023/10/01: Vector and Array

2023/10/10: Buble Sort and Selection Sort

2023/10/22: Quick Sort, Insertion Sort and Merge Sort 

2023/10/29: Quiz1

2023/11/20 struct And Linked List

2023/11/26 Linked List

--TBD--

再兩次上課後的會進行一次上機考(代議)

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

### 插入排序法(Insertion sort)
https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2FS1tJMC35_

### 快速排序(Quick Sort)
https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2FB1SPnfRq_

### 合併排序法(Merge Sort)
https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2FHJgJ3hxkou

## struct
struct 結構用法與範例，struct 可以將不同資料類型集合在一起，通常將相關的變數類型放在同一個 struct 裡，也方便參數傳遞。

```cpp=
#include <iostream.h>
#include <string>
using namespace std;

struct student {
    int id;
    int age;
    char name[32];
};

int main() {
    struct student s1;
    s1.id = 10;
    s1.age = 18;
    strcpy(s1.name, "Tom");
    cout << s1.id << endl;
    cout << s1.age << endl;
    cout << s1.name << endl;

    struct student s2 = {11, 20, "Jerry"};
    cout << s2.id << endl;
    cout << s2.age << endl;
    cout << s2.name << endl;

    return 0;
}
```
C/C++ 經常使用 typedef 把某個 struct 取一個別名，以下示範用 typedef 將 struct student 取一個 student_t 別名，之後宣告時就可以使用新的 student_t 別名，就可以省去加上 struct，藉此達到簡化宣告語法，
```c++=
typedef struct student {
    int id;
    int age;
    char name[32];
} student_t;

int main() {
    student_t s1;
    s1.id = 123;
    s1.age = 20;
    cout << s1.id << " " << s1.age;
    return 0;
}
```
另外還可以把 struct 的定義跟 typedef 分開寫，像這樣寫，
```
struct student {
    int id;
    int age;
    char name[32];
};

typedef struct student student_t;
int main() {
    student_t s1;
    s1.id = 123;
    s1.age = 20;
    cout << s1.id << " " << s1.age;
    return 0;
}
```

## Linked list
簡介：Linked list
Linked list(連結串列)是一種常見的資料結構，其使用node(節點)來記錄、表示、儲存資料(data)，並利用每個node中的pointer指向下一個node，藉此將多個node串連起來，形成Linked list，並以NULL來代表Linked list的終點。

實際打開每個node的內部，至少會包含(1)data來代表資料，與(2)pointer指向下一個node
```
struct Node {
    int data;
    Node* next;
};
```
實際上你可以為這個資料結構寫一些常用的Function:
```
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
```

比較：Array與Linked list

Array(矩陣)也是常見的用來記錄一連串「具有相同形態的資料」的資料結構，以下便列舉Array與Linked list各自的優缺點，以及各自適合的問題情境。

### Array
#### 優點

random access：只要利用index即可在O(1)時間對Array的資料做存取。

較Linked list為節省記憶體空間：因為Linked list需要多一個pointer來記錄下一個node的記憶體位置。

假設node之data項目為1

byte的char，但是pointer項目卻要4bytes，這樣的資料結構就多花了4倍的記憶體空間在與真正要處理的資料無關的部分上，是個沒有效率的做法。

#### 缺點

新增/刪除資料很麻煩：若要在第一個位置新增資料，就需要O(N)時間把矩陣中所有元素往後移動。

同理，若要刪除第一個位置的資料，也需要O(N)時間把矩陣中剩餘的元素往前移動。

若資料數量時常在改變，要時常調整矩陣的大小，會花費O(N)的時間在搬動資料(把資料從舊的矩陣移動到新的矩陣)。
#### 適用時機
希望能夠快速存取資料。

已知欲處理的資料數量，便能確認矩陣的大小。

要求記憶體空間的使用越少越好。

### Linked list
#### 優點

新增/刪除資料較Array簡單，只要對O(1)個node(所有與欲新增/刪除的node有pointer相連的node)調整pointer即可，不需要如同Array般搬動其餘元素。

若是在Linked list的「開頭」新增node，只要O(1)。

若要刪除特定node，或者在特定位置新增node，有可能需要先執行O(N)的「搜尋」。

Linked list的資料數量可以是動態的，不像Array會有resize的問題。
#### 缺點

因為Linked list沒有index，若要找到特定node，需要從頭(ListNode *first)開始找起，搜尋的時間複雜度為O(N)。

需要額外的記憶體空間來儲存pointer。
#### 適用時機

無法預期資料數量時，使用Linked list就沒有resize的問題。

需要頻繁地新增/刪除資料時。

不需要快速查詢資料。
## 題目:
請查閱
```HW=
Cplusplus
    -Exam_info
    -hw_description
        hw...
    -hw_solution
    -Quiz
    -上課程式
```