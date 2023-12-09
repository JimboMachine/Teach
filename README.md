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

2023/12/03 Doubly Linked List and Circular Linked List

2023/12/10 DP(Knapsack Problem)(補上)

--TBD--
12/24 上機考(2hr) 考題3~4題

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

## Dynamic Programming
https://web.ntnu.edu.tw/~algo/KnapsackProblem.html

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

## Double Linked List
跟 Singly linked list 幾乎一模一樣，唯一的差別是每個節點除了指向 next 的指標（pointer）以外，還有一個指向 previous 的指標。

### 與 Singly Linked List 差別
可以從 tail 往回推，而不用從 head 一個一個往下找

在做 reverse 的時候方便很多

DLL 比起 SLL 使用了更多的記憶體！但是更多的記憶體通常代表有更多的彈性，因此常常這是我們必須拿出來權衡的。

#### 創建
```
Node
    val
    next
    prev
```

###### Class Node
```
class Node {
    constructor(val) {
        this.val = val
        this.next = null
        this.prev = null
    }
}
```


#### DoublyLinkedList
```
head
tail
length
```
##### Class DoublyLinkedList
class DoublyLinkedList {
    constructor() {
        this.head = null
        this.tail = null
        this.length = 0
    }
}

#### Push：從 List 最後建立新節點
創建一個新 Node

如果 List head 為空（List 沒有節點），List 的 head 跟 tail 是 new Node

如果 List 有節點，設定 List tail 的 next 為 new Node，new Node 的 prev 是原來的 tail，tail 為 new Node

length 加一

##### Edge Case
如果原來 List 中只有一個節點，設定 head 跟 tail 為 null

#### Shift：移除 head
Shift 在 SLL 跟 DLL 都蠻單純的～

將原來的 head 存在變數裡

找到第二個 node，設定它為新 head

設定新 head 的 prev 為空

設定 old head 的 next 為空

長度減一

回傳 old head
##### Edge case
如果 list 本來就沒有節點，回傳 undefined

如果移除最後一個節點後，list 為空，將 list 的 head 跟 tail 都指定為 null
#### Unshift：從 List 的起始新增一個節點
設定（原來的） head 的 prev 為 new Node

設定 new Node 的 next 為 head

設定 head 為 new Node

list 長度加一

回傳整個 list
##### Edge case
如果 list 本來為空，指定 head 跟 tail 是 newNode。
#### Get：取得某個位置的資料
DLL 跟 SLL 最大的不同是我們可以根據 function input 的 index argument 來決定我們要從 head 還是 tail 開始往前／後找：

如果 index 小於 length / 2，從 head 開始遍歷 list 節點，直到找到指定的 index

如果 index 大於 length / 2，從 tail 開始遍歷 list 節點，直到找到指定的 index

回傳找到的節點（或其 value）
##### Edge case
如果 index 小於零或大於 list 的長度，回傳 null

#### Set：改變 list 中特定 index 節點的值為新值
set function 會有兩個 arguments，一個是指定的 index，一個是要更新的 value

因為前面我們已經寫好了 get method，所以我們可以使用 get 取得指定的 index node，然後重新給與它的 value 為 input value
##### Edge case
如果使用 get 沒有找到指定 index 的 node，回傳 null
#### Insert：在 list 中特定位置插入指定值
跟 Get 一樣，DLL 可以根據 index 來決定從 head 還是 tail 來做遍歷。

insert function 會有兩個 arguments，一個是指定的 index，一個是要建立的新 node 的 value

建立一個新 newNode，並且給與 input value

使用前面寫好的 get method，取得「index — 1」的 node，這邊先取名為 preNode

將 newNode 的前一個和後一個節點的 prev 和 next 設定好

list 的長度加一

回傳 true
##### Edge case
如果 index 小於零或大於 list 的長度，回傳 false

如果 index 就是 list 的長度，那我們可以直接使用 push，回傳 true

如果 index 是 0，可以直接使用 unshift，回傳 true
#### Edge case
如果 index 小於零或大於 list 的長度，回傳 false

如果 index 就是 list 的長度，那我們可以直接使用 push，回傳 true

如果 index 是 0，可以直接使用 unshift，回傳 true
##### Edge case
如果 index 小於零或大於 list 的長度，回傳 undefined

如果 index 等於 list length — 1，使用 pop

如果 index 等於 0，使用 shift
### Big O of Doubly Linked List
Insertion：O(1)

Removal：O(1)

Searching：O(n)，技術上來說 Searching 應該是 O(n/2)，不過常數不重要，所以還是 O(n)

Access：O(n)
#### DLL vs. SLL
DLL 跟 SLL 非常相像，差別只在於 DLL 多了一個 pointer。

在瀏覽器中，當我們在使用頁面的時候，它其實就是一種 DLL，因為每一個頁面都有上一頁和下一頁。

DLL 在搜尋上比 SLL 表現更好。

DLL 會用到更多的記憶體，因為它多了一個方向的 pointer。
## Stack
堆疊（Stack）是一種抽象的資料結構，並且必定遵循 LIFO（Last In First Out）的原則，最後進的先出。

LIFO 現實中的例子可以想像一落堆疊起來的盤子，我們需要從最上面開始拿；又或者像一台塞滿人的電梯，最後進的最靠門的人必須要先出去，

後面的人才能出去。
### Stack 通常被用在

函式的調用

Undo / Redo

Routing

有些演算法也是利用 Stack 和 Queue 來處理。

Array Implementation

有很多方法都能達成 Stack 的結構，因為 Stack 最重要的就是必須符合 LIFO 原則。最簡單的方式是利用陣列來達成，有些程式語言有自己

的 Stack 的處理方式，不過 JavaScript 沒有，但我們仍然可以利用陣列來達成它。
### Big O of Stack
Insertion：O(1)

Removal：O(1)

Searching：O(n)

Access：O(n)
最重要的是 insertion 和 removal，如果我們需要 search 或 access，我們可能會想使用其它更方便這麼做的資料結構。
## Queue
原則：FIFO（First In First Out）

現實世界常見：排隊、列印資料

Array Implementation
同樣可以利用陣列或自己寫一個 class 來達成 Queue。

因為 Singly linked list 中，如果要從尾巴移除的時候，一樣需要遍歷所有節點，所以我們採取的是 push & shift，從 tail 推進去、從 head 移除。

### Big O of Queue
Insertion：O(1)

Removal：O(1)

Searching：O(n)

Access：O(n)

跟 Stack 很像，最重要的是 insertion 和 removal，通常如果我們需要頻繁的 search 或 access，也不會優先考慮 Queue 的資料結構。

相較之下，如果我們使用陣列的資料結構，insertion 和 removal 都會是 O(n)，因為我們需要重新設定它的 index，但是陣列的 access 

會是 O(1)，這是陣列跟 Stack／Queue 的共同差異。
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