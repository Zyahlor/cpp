#include <iostream>
using namespace std;
using diem = int;

int main(){
    diem bao;
    cout<<"nhap diem cua bao:";
    cin>>bao;
    cout<<(bao >=8 ? "gioi!\n":(bao >= 5 ? "dau!\n" : "rot!\n"));
return 0;
}
