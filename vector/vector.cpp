#include <iostream>
#include <vector>
using namespace std;

int main(){
    // tao vector
    vector<int> v ={10,20,30}; 
    v.push_back(40);
    v.push_back(50);
    cout<<"kich thuoc:"<<v.size()<<endl;
    cout<<"phan tu dau:"<<v.front()<<endl;
    cout<<"phan tu cuoi:"<<v.back()<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
