#include <iostream>

using namespace std;

int main() {
    int chess[6] = {1,1,2,2,2,8};
    int white[6];
    for(int i=0;i<6;i++) {
        cin>>white[i];
    }

    for(int i=0;i<6;i++) {
        cout<<chess[i]-white[i]<<' ';
    }

    return 0;
}