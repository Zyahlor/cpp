# **1. Tổng quan về File I/O trong C++**

C++ cung cấp thư viện:

```C++
#include <fstream>
```

Trong đó có 3 class quan trọng:

|Class|Chức năng|
|---|---|
|`ofstream`|Ghi dữ liệu vào file|
|`ifstream`|Đọc dữ liệu từ file|
|`fstream`|Vừa đọc vừa ghi file|
# **2. Ghi dữ liệu vào file với** `ofstream`

Cú pháp:

```c++
ofstream file("data.txt");
```

Ví dụ:

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("data.txt");

    file << "Hello World" << endl;
    file << "Learning C++ File I/O";

    file.close();

    return 0;
}
```

Sau khi chạy chương trình, file `data.txt` sẽ chứa:

```
Hello World
Learning C++ File I/O
```

### **Giải thích**

- `ofstream file`: Tạo đối tượng dùng để ghi file.
    
- `"data.txt"`: Tên file cần ghi.
    
- `file <<`: Ghi dữ liệu vào file, tương tự `cout <<`.
    
- `file.close()`: Đóng file.
    

**Lưu ý:** Nếu file chưa tồn tại, chương trình thường tự tạo file. Nếu file đã tồn tại, chế độ mặc định sẽ ghi đè nội dung cũ.