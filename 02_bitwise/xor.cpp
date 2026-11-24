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
  if(key2 < 1 || key2 > 127){
      cout<<"key khong hop le!\n";
      return 0;
  }
  string mahoa2 = xortest(goc, key2);
  string giaima2 = xortest(mahoa2, key2);
  cout << "ma hoa: " << mahoa2 << endl;
  cout << "giai ma:" << giaima2 << endl;
  return 0;
}
