#include <iostream>
using namespace std;

int main() {
  int arr[5] = {10, 20, 30, 40, 50};
  cout << "duyet gan cung gia tri:\n";
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  std::cout << endl;
  cout << "duyet dua tren kich thuoc mang:\n";
  int n =sizeof(arr) / sizeof(arr[0]); 
  for (int i = 0;i<n ;i++) {
    cout << arr[i] << " ";
  }
    cout<<endl;
    cout<<"duyet theo kieu range-base:\n";
    for(int x : arr){
        cout<<"["<<x<<"] ";
    }
    cout<<endl;
  return 0;
}
