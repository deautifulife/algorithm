#include <iostream>
#include<algorithm> //reverse 쓰기위함

using namespace std;

int main() {
    string str = "";
    cin>>str;
    string save = str;
    reverse(str.begin(), str.end());

    if(str==save)
        cout<<1;
    else
        cout<<0;

    return 0;
}