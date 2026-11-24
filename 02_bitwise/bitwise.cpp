#include <iostream>
#include <string>
using namespace std;
string xortest(string s, char key) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = s[i] ^ key;
  }
  return s;
}

int main() {
  string goc;
  int key2;
  cout << "nhap chuoi de ma hoa:";
  getline(cin, goc);
  cout << "nhap so de ma hoa chuoi:";
  cin >> key2;
  string mahoa2 = xortest(goc, key2);
  string giaima2 = xortest(mahoa2, key2);
  cout << "ma hoa: " << mahoa2 << endl;
  cout << "giai ma:" << giaima2 << endl;
  cout << (6 & 3) << endl;

  int n;
  cout << "nhap so can so chan hay le:";
  cin >> n;
  cout << "bitwise [AND]\n";
  cout << (n & 1 ? "le (1)!\n" : "chan (0)!\n");
  cout << "bitwise [OR]\n";
  cout << (n | 3) << endl;

  char c = 'B';
  char key = 24;
  char mahoa = c ^ key;
  cout << "ma hoa:" << mahoa << endl;

  char giaima = mahoa ^ key;
  cout << "giai ma:" << giaima << endl;
  cout << "\n ===== ma hoa =====\n";
  string s = "bao";
  char key3 = 24;
  for (int i = 0; i < s.length(); i++) {
    s[i] = s[i] ^ key3;
  }
  cout << "ma hoa: " << s << endl;
  for (int i = 0; i < s.length(); i++) {
    s[i] = s[i] ^ key3;
  }
  cout << "giai ma: " << s << endl;
  return 0;
}
