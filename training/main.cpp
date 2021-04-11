#include <iostream>
#include <map>
using namespace std;
int main() {
    std::map<int,int> a;
    a[3] = 2;
    a[0] = 1;
    auto b = a.find(0);
    cout << a.find(0)->second;
    //cout << (a.find(0)->second()) << endl;
    return 0;
}