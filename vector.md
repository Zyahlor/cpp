# 28 - 11 -2026
## 1. vector là gì?
- à mảng động trong c++,có khả năng tự thay đổi kích thước trong quá trình chạy chương trình
- Khác với mảng thông thường:

```c++
int a[5];       // Mảng có kích thước cố định
vector<int> v;  // Vector có kích thước linh hoạt
```

Để sử dụng vector, cần khai báo thư viện:

```c++
#include <vector>
```

## **2. Các cách khởi tạo vector**

```c++
vector<int> v;                 // Vector rỗng
vector<int> v1 = {1, 2, 3};     // Có sẵn 3 phần tử
vector<int> v2(5);              // 5 phần tử bằng 0
vector<int> v3(5, 10);          // 5 phần tử bằng 10

vector<string> names;          // Vector chứa chuỗi
vector<double> scores;         // Vector chứa số thực
```
## **3. Các hàm quan trọng cần nhớ**

| Cú pháp          | Công dụng              |
| ---------------- | ---------------------- |
| `v.push_back(x)` | Thêm x vào cuối        |
| `v.pop_back()`   | Xóa phần tử cuối       |
| `v.size()`       | Số lượng phần tử       |
| `v[i]`           | Truy cập phần tử thứ i |
| `v.front()`      | Lấy phần tử đầu        |
| `v.back()`       | Lấy phần tử cuối       |
| `v.empty()`      | Kiểm tra vector rỗng   |
| `v.clear()`      | Xóa toàn bộ phần tử    |
| `v.insert()`     | Chèn phần tử           |
| `v.erase()`      | Xóa phần tử tại vị trí |
| `v.resize(n)`    | Thay đổi kích thước    |
## 4. code
 ### **Ví dụ 1: Thêm, xóa và truy cập phần tử**

```

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);
    v.push_back(50);

    v.pop_back();

    v[0] = 100;

    cout << "Kich thuoc: " << v.size() << endl;
    cout << "Phan tu dau: " << v.front() << endl;
    cout << "Phan tu cuoi: " << v.back() << endl;

    return 0;
}
```

Kết quả:

```
Kich thuoc: 4
Phan tu dau: 100
Phan tu cuoi: 40
```

### **Ví dụ 2: Duyệt vector**

Có 3 cách phổ biến.

**Cách 1: Vòng lặp for thông thường**

```
vector<int> v = {10, 20, 30, 40};

for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

**Cách 2: Range-based for**

```
for (int x : v) {
    cout << x << " ";
}
```

**Cách 3: Iterator**

```
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

Cả 3 đều cho kết quả:

```
10 20 30 40
```

### **Ví dụ 3: Nhập vector từ bàn phím**

```

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
```

Input:

```
5
12 34 56 78 90
```

Output:

```
12 34 56 78 90
```

Bạn cũng có thể khởi tạo trước kích thước rồi nhập trực tiếp:

```
int n;
cin >> n;

vector<int> v(n);

for (int i = 0; i < n; i++) {
    cin >> v[i];
}
```

**Lỗi người mới thường gặp:**

```
vector<int> v;
v[0] = 10; // Sai: vector chưa có phần tử nào
```

Cách đúng:

```
vector<int> v;
v.push_back(10);
```