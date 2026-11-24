#include<iostream>
using namespace std;

int main(){
    int age = 20;
    string name = "bao";
    char grades[] = {'A','B','C'};
    for(char kt:grades)
        cout<<"["<<kt<<"] ";
    cout<<endl;
    cout<<"size of  string: "<< sizeof(name)<<" bytes\n";
    cout<<"hello,world";
    return 0;
}

