#include <iostream>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
    int num = 666;
    int series = 0;
    string target;
    while(!(series==n)) {
        target = to_string(num);
        for(int i=0; i<target.length()-2; i++) {
            if(target[i] == '6' && target[i+1] == '6' && target[i+2] == '6'){
                series++;
                break;
            }    
        }
        num++;
    }
    cout<<num-1;

    
    return 0;

}
