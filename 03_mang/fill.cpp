#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  // int arr[10];
  // fill(arr,arr+5,7);
  // fill(arr+5,arr + 10,10);
  // for(int x : arr) cout<<"["<<x<<"] ";
  cout << "bai 1:\n";
  int a[6] = {6, 9, 1, 2, 5, 10};
  for (int x : a)
    cout << "[" << x << "] ";
  cout << "\nbai 2:\n";
  int tong = 0 ;
  double avg = 0;
  for (int x : a)
    tong += x;
  avg = tong * 1.0 / (sizeof(a) / sizeof(a[0]));
  cout << "tong cac phan tu trong mang:[" << tong << "]\n";
  cout << "trung binh cac phan tu trong mang:[" << avg << "]\n";
  cout << "bai 3:\n";
  int maxVal = a[0], minVal = a[0], maxidx = 0, minidx = 0;
  int np = (sizeof(a) / sizeof(a[0]));

  for (int i = 0; i < np; i++) {

    if (maxVal < a[i]) {
      maxVal = a[i];
      maxidx = i;
    }
    if (minVal > a[i]) {
      minVal = a[i];
      minidx = i;
    }
  }
  cout << "so lon nhat la:[" << maxVal << "] o vi tri:[" << maxidx << "]\n";
  cout << "so nho nhat la:[" << minVal << "] o vi tri:[" << minidx << "]\n";

  cout << "bai 4:\n";
  int b[8] = {3, 7, 3, 9, 3, 1, 7, 3};
  int tim = 3;
  int dem = 0;
  for (int x : b) {
    if (x == tim)
      dem++;
  }
  cout << "trong mang co so phan tu [" << tim << "]:[" << dem << "]\n";
  cout << "bai 5:\n";
  int c[10];
  fill(c, c + 3, 0);
  fill(c + 3, c + 7, 5);
  fill(c + 7, c + 10, 9);
  for (int x : c)
    cout << "[" << x << "] ";
  cout << "\nbai 6:\n";
  int mang[] = {1, 2, 3, 4, 5};
  int p = sizeof(mang) / sizeof(mang[0]);
  for (int i = 0; i < p / 2; i++) {
    int temp = mang[i];
    mang[i] = mang[p - i - 1];
    mang[p - i - 1] = temp;
  }
  for (int x : mang)
    cout << "[" << x << "] ";

  return 0;
}
