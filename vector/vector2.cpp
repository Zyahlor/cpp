#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
  int n = 5;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      v[i] = rand() % 20;
  }
  for (int x : v) {
    cout << x << " ";
  }
  int sum = 0;
  for(int x :v )sum += x;
  cout<<"tong cac so trong mang:"<<sum<<endl;
  double tbc = (double)sum/v.size();
  cout<<"tbc:"<<tbc<<endl;
  int max_v = v[0],min_v = v[0];
  for(int i :v){
      if(max_v < i) max_v = i;
      else if(i < max_v && i < min_v) min_v = i;
  }
  for(int i = 0;i<v.size();i++)
      if(min_v > v[i]) min_v = v[i];
  cout<<"max:"<<max_v<<endl;
  cout<<"min:"<<min_v<<endl;
  return 0;
}
