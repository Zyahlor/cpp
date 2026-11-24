# 4 - 10 - 2026

## 1. typedef and alliases (using)
- đều dùng để đặt tên khác cho 1 kiểu dữ liệu có sẵn,ko tạo kiểu mới, chỉ đổi tên cho gọn, dễ đọc

```cpp
#include<iostream>
using namespace std;
using money = double; // thay vì gõ double là kiểu dữ liệu, dùng tên khác phù hợp với ngữ cảnh chương trình
typedef int age; // đây cũng vậy nhưng nó là cách cũ
int main(){
    money a = 10;cũ // khai báo như bình thường
    money b = 20;
    age bao = 20;
    cout<<"hello,world!\n";
    cout<<"tien cua nguoi A la:["<<a<<"]\n";
    cout<<"tien cua nguoi B:["<<b<<"]\n";
    cout<<"tuoi cua bao la:["<<bao<<"]\n";
    return 0;
}
```
## 2. namespace
- họ -  thư mục cho tên, giúp tránh trùng tên

Ví dụ trên trường có 2 bạn cùng tên "An", một bạn lớp A, một bạn lớp B. Muốn phân biệt thì gọi **"An lớp A"** và **"An lớp B"**. Namespace làm đúng việc đó cho code:

```cpp
#include <iostream>

namespace lopA {
    int diem = 8;
}

namespace lopB {
    int diem = 5;
}

int main() {
    std::cout << lopA::diem << "\n";  // 8
    std::cout << lopB::diem << "\n";  // 5
}
```

Hai biến đều tên `diem` mà không đụng nhau, vì mỗi cái nằm trong "lớp" riêng. Dấu `::` đọc là **"nằm trong"**: `lopA::diem` = "`diem` nằm trong `lopA`".

**Vậy `std::` là gì?** `std` là namespace của thư viện chuẩn C++. Mọi thứ như `cout`, `string`, `vector` đều nằm trong "lớp `std`":

```cpp
std::cout << "hi";   // ✅ cout nằm trong std
```

Còn `using namespace std;` là bảo máy: "mọi tên cứ tìm trong `std` luôn, khỏi cần ghi `std::`".

**Vì sao dự án thật ít dùng `using namespace std;`?** Vì có thể trùng tên:

```cpp
using namespace std;

int count = 5;   // ❌ std cũng có thứ tên "count" → dễ lỗi mơ hồ
```

Nhớ 3 ý là đủ:

- ✅ Namespace = nhóm tên, tránh trùng
- ✅ `::` = "nằm trong"
- ✅ `std` = nhóm của thư viện chuẩn

# 5 - 10 - 2026

## 3. TERNARY CONDITION
- là viết tắt của điều kiệu
- thông thường, chúng ta sẽ viết cấu trúc if - else 
- ternary cho phép chúng ta viết gọn hơn
``` c++
int age = 19;
if(age >= 18) cout<<"nguoi lon!\n";
else cout<<"tre con!\n";

// ternary
cout<<(tuoi >= 19 ? "nguoi lon!\n":"tre con!\n");
```
> cấu trúc: `điều kiện` ? `đúng` : `sai`

- TERNARY lồng:
- như if - else if - else

``` c++
int diem = 9;
cout<<(diem >= 8 ? "gioi!\n" : (diem >= 5 ? "trung binh!\n" : "kem!\n" ));

if(diem >= 8)cout<<"gioi!\n";
else if(diem >= 5)cout<<"trung binh!\n";
else cout<<"kem!\n";
```

## 4. bitwise
- **Bitwise = thao tác trực tiếp trên từng bit của số.**

|Số|Dạng bit|
|---|---|
|1|`001`|
|3|`011`|
|5|`101`|
|6|`110`|
Toán tử thường (`+`, `-`) làm việc với **cả con số**. Toán tử bitwise làm việc với **từng bit một**, so cột với cột.

**Vì sao cần học?** Vì nó nhanh, gọn, và dùng rất nhiều trong:

- ✅ Bảo mật (mã hóa XOR, mask, flag quyền)
- ✅ Mạng (subnet mask, địa chỉ IP, cờ TCP)
- ✅ Lập trình hệ thống, đọc exploit

**Các toán tử chính (chỉ cần biết tên trước):**

| Toán tử   | Tên      | Luật                           |
| --------- | -------- | ------------------------------ |
| `&`       | AND      | Ra 1 khi **cả hai** đều là 1   |
| `\|`      | OR       | Ra 1 khi **ít nhất một** là 1  |
| `^`       | XOR      | Ra 1 khi **hai bit khác nhau** |
| `~`       | NOT      | Đảo 0 thành 1, 1 thành 0       |
| `<<` `>>` | Dịch bit | Đẩy bit sang trái/phải         |
- `AND` - so 2 số, nếu cả 2 có cùng bit 1 sẽ ra 1, còn lại là 0
- lọc,kiểm tra bit

```text
(6&3)
6 = 110
3 = 011

  110
&
  011
  ----
  010  = 2
#giải thích
ta tính từng hàng
0&1 = 0 vì hàng này ko cùng số 1 
1&1 = 1 hàng này cùng 1 nên ra 1
1&0 = 0 hàng này như hàng đầu
```

| Số thường | Máy viết |
| --------- | -------- |
| 0         | 000      |
| 1         | 001      |
| 2         | 010      |
| 3         | 011      |
| 4         | 100      |
| 5         | 101      |
| 6         | 110      |
| 7         | 111      |
- tính nhị phân
- mỗi cột sang trái thì giá trị **nhân đôi** so với cột bên phải nó
- mặc định đứng ở hàng đơn vị nếu là số 1 là 1, 0 thì ko để tâm
- nói cách khác - mỗi giá trị đứng ở vị trí đều là 2 mũ giá trị dứng ở đó từ phải sang trái, n <- 0

```text
ví dụ: 1101
1 =1 x 2 ^ 0 = 1
0 = 0 x 2 ^ 1 = 0
1 = 1 x 2 ^ 2 = 4
1 = 1 x 2 ^3 = 8
1101 = 1 + 0 + 4 + 8 = 13
```

- `OR` - có ít nhất 1 bit là 1 thì ra 1, chỉ khi cả 2 là 0 thì ra 0
- tức hơi ngược lại của `AND` và thêm ít nhất là 1 thì ra 1
- bật thêm bit
```text
ví dụ :  7 | 5
7 = 111
5 = 101

  111
 |
  101
  111 = 7
  
1 | 1 = 1 vì cả 2 đề là 1
1 | 0 = 1 vì có ít nhất 1 số 1
1 | 1 = 1 như câu đầu
```

- `XOR` (^) 2 bit khác nhau thì ra 1,giống ra 0
- dùng cho mã hóa/đảo bit
- tính chất : (a^key) ^ key  = a

```text
ví dụ: 6 ^ 3
6 = 110
3 = 011

  110
^
  011
  101
0 ^ 1 = 1 vì 2 bit khác nhau
1 ^ 1 = 0 vì 2 bit giống nhau
1 ^ 0 = 1 như câu đầu
```

- `NOT` - đảo hết bit - tức 1 -> 0, 0->1
- chỉ cần 1 số

```text
5 = 0101
-5 = 1010
```
máy thường dùng nhiều bit hơn nên đảo hêt bit ra số âm
công thức nhớ nhanh:
> ~n = -n -1
```text
-5 = 1010 -1 = -6
```

- dịch bit `<<` , `>>`
- `<<` dịch trái: đẩy bit sang trái,bên phải bên 0
- `>>` dịch phải: đẩy sang phải, bit cuối bên mất
- mỗi lần dịch là nhân đôi cho `<<` và chia đôi cho `>>`

|Phép|Ý nghĩa|
|---|---|
|`n << k`|`n × 2^k`|
|`n >> k`|`n ÷ 2^k` (bỏ phần dư)|
```text
5 << 1
5 = 101 => 5 << 1 = 1010 = 10 đẩy bit sang trái, thêm 0 bên phải
20 >> 2
20 = 10100 => 20  >> 2 = 101 = 5 bỏ cả 2 bit bên trái

#
kết luậtn
<< = thêm bit 0 bên trái
>> = bỏ bit bên trái - cắt bớt
```

## 5. `sizeof()`
- toán tử trả về kích thước của kiểu dữ liệu,biến,được tính từ lúc biên dịch.kiểu trả về là size_t.

``` c++
int a = 10;
int arr[10];

cout<<"so byte cua int:"<<sizeof(int)<<endl; // 4 byte
cout<<"so byte cua a:"<<sizeof(a)<<endl; // 4 byte
cout<<"so byte cua arr:"<<sizeof(arr); // 40 (10 * 4 ) 10 = số phần tử mảng
cout << sizeof(arr)/sizeof(arr[0]) << endl; // 10 → đếm số phần tử }
```

### Kích thước các kiểu phổ biến (x64, thường gặp)

|Kiểu|Byte|
|---|---|
|`char`|1|
|`bool`|1|
|`short`|2|
|`int`|4|
|`long`|4 (Windows) / 8 (Linux)|
|`long long`|8|
|`float`|4|
|`double`|8|
|con trỏ `T*`|8 (x64) / 4 (x86)|

> Kích thước phụ thuộc compiler/kiến trúc, chỉ `sizeof(char) == 1` là chắc chắn.

# 6 - 10 - 2026
## 6. CÁC LOẠI DUYỆT MẢNG
- ngoài kiểu duyệt gán cứng phần từ trong vòng lặp khi duyệt mảng, ta còn các kiểu khác:
### 1. For thường (dùng index)

```cpp
int arr[5] = {10, 20, 30, 40, 50};

for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";   // 10 20 30 40 50
}
```

Không muốn gõ cứng số 5 thì dùng `sizeof`:

```cpp
int n = sizeof(arr) / sizeof(arr[0]);  // 5
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

### 2. Range-based for (C++11), gọn nhất

```cpp
for (int x : arr) {
    cout << x << " ";
}
```

Muốn **sửa** phần tử thì phải dùng tham chiếu `&`:

```cpp
for (int &x : arr) {
    x *= 2;   // arr thành 20 40 60 80 100
}
```

❌ Không có `&` thì `x` chỉ là bản copy, sửa không ảnh hưởng mảng:

```cpp
for (int x : arr) x *= 2;  // arr không đổi
```

✅ Chỉ đọc mà phần tử to (string, struct) thì dùng `const auto&` cho đỡ copy:

```cpp
for (const auto &x : arr) cout << x << " ";
```

## 7. fill()
- gán cùng 1 giá trị cho cả đoạn mảng

```cpp
#include <iostream>
#include <algorithm>   // fill nằm trong này
using namespace std;

int main() {
    int arr[5];

    fill(arr, arr + 5, 7);   // gán 7 cho tất cả

    for (int x : arr) cout << x << " ";   // 7 7 7 7 7
}
```

> cú pháp: fill(đầu, cuối,giá trị )

### Điền một phần mảng

```cpp
int arr[5] = {1, 2, 3, 4, 5};

fill(arr + 1, arr + 4, 0);   // điền vị trí 1, 2, 3

// arr: 1 0 0 0 5
```

### Cách dùng cho mảng 1 chiều

```cpp
int n = 5;
int a[100];
fill(a, a + n, -1);   // chỉ điền n phần tử đầu
```

### So sánh với cách khác

|Cách|Ví dụ|Ghi chú|
|---|---|---|
|Vòng for|`for(i...) a[i] = 7;`|Dài, nhưng dễ hiểu|
|`fill()`|`fill(a, a+n, 7);`|Gọn, gán giá trị bất kỳ|
|`= {0}`|`int a[5] = {0};`|Chỉ lúc khai báo, chỉ để về 0|
|`memset()`|`memset(a, 0, sizeof(a));`|Nhanh, nhưng chỉ an toàn với 0 và -1|

### Lỗi hay gặp

❌ **Quên `+ n`, hoặc điền quá biên:**

```cpp
int a[5];
fill(a, a + 6, 0);   // ghi lố 1 phần tử, undefined behavior
```

✅ `fill(a, a + 5, 0);`

❌ **`= {7}` không điền hết 7:**

```cpp
int a[5] = {7};   // 7 0 0 0 0, chứ không phải 7 7 7 7 7
```

✅ Dùng `fill(a, a + 5, 7);`

❌ **`memset` với giá trị khác 0/-1** cho mảng `int`:

```cpp
memset(a, 1, sizeof(a));   // mỗi phần tử = 16843009, không phải 1
```


