## 1. cấp phát bộ nhớ là gì
 - là tạo ra 1 vùng bộ nhớ chưa các dữ liệu
 - giống như c có 3 hàm: `malloc` cấp phát bộ nhớ, `calloc` cấp phát bộ nhớ và giá trị cấp phát trong bộ nhớ đó là 0, `realoc` mở rộng bộ nhớ được cấp phát
 - c++ cũng có và 2 hàm là `new` và `delete`
## 2. cú pháp
### 1, `new`

``` c++
int *p = new int;
```
1. `new int` yêu cầu cấp phát bộ nhớ đủ chứa một biến `int` trên heap.
2. Trả về địa chỉ vùng nhớ vừa cấp phát.
3. Gán địa chỉ đó cho con trỏ `p`.

``` c++
#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;

    *ptr = 100;

    cout << *ptr; // 100

    delete ptr;
    return 0;
}
```
- `ptr`: Chứa địa chỉ vùng nhớ.
- `*ptr`: Truy cập giá trị tại vùng nhớ đó.
- `delete ptr`: Giải phóng vùng nhớ đã cấp phát.
#### Khởi tạo giá trị ngay khi cấp phát

Ông có thể khởi tạo giá trị ngay trong lúc sử dụng `new`.

```c++
int *ptr = new int(100);
```

Hoặc:

```c++
int *ptr = new int{100};
```

Tương tự với mảng:

```c++
int *arr = new int[5]{1, 2, 3, 4, 5};
```

Lúc này:

- Cấp phát một vùng nhớ chứa 5 phần tử `int`.
- Khởi tạo lần lượt các phần tử bằng 1, 2, 3, 4, 5.

## 2.`delete`

Có hai cách giải phóng bộ nhớ tương ứng với cách cấp phát.

|Cấp phát|Giải phóng|
|---|---|
|`new int`|`delete ptr`|
|`new int[5]`|`delete[] arr`|

Ví dụ:

```c++
int *ptr = new int(100);
delete ptr;

int *arr = new int[5];
delete[] arr;
```

**Cực kỳ lưu ý:** Không được dùng `delete` để giải phóng mảng được cấp phát bằng `new[]`.

Sai:

```c++
int *arr = new int[5];
delete arr;
```

Đúng:

```c++
int *arr = new int[5];
delete[] arr;
```

## **4. Tránh Dangling Pointer**

Sau khi giải phóng bộ nhớ, con trỏ vẫn giữ địa chỉ cũ.

```c++
int *ptr = new int(100);

delete ptr;

// ptr vẫn chứa địa chỉ cũ
```

Nếu tiếp tục truy cập `*ptr`, chương trình có thể gặp Undefined Behavior.

Cách xử lý:

```
delete ptr;
ptr = nullptr;
```

`nullptr` biểu thị con trỏ không trỏ đến đối tượng nào.