#include <iostream>
#include <string>
using namespace std;

const int doc = 4;  // 100
const int ghi = 2;  // 010
const int chay = 1; // 001
string hienthi(int q) {
  string s = "";
  s += (q & doc) ? "r" : "-";
  s += (q & ghi) ? "w" : "-";
  s += (q & chay) ? "x" : "-";
  return s;
}
int main() {
  int quyen = 0;
  cout << hienthi(quyen) << endl;
  cout << "OR:\n";
  quyen = quyen | doc;
  std::cout << hienthi(quyen) << endl;
  quyen = quyen | ghi | chay;
  std::cout << hienthi(quyen) << endl;
  std::cout << "AND (&) NOT(~):\n";
  quyen = quyen & ~ghi;
  std::cout << hienthi(quyen) << endl;
  std::cout << "XOR (^):\n ";
  quyen = quyen ^ chay;
  std::cout << hienthi(quyen) << endl;

  return 0;
}
