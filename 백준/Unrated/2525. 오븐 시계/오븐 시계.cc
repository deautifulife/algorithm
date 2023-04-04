#include <iostream>

using namespace std;

int main() {
    int h,m;
    int time;
    cin>>h>>m;
    cin>>time;
    m = m+time;
    if(m>=60) {
        h=h+m/60;
        m= m%60;
    }

    if(h>=24) {
        h=h-24;
    }

    cout<<h<<' '<<m<<'\n';

    return 0;
}