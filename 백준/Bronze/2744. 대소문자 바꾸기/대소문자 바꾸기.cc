#include <iostream>
// #include <vector>
#include <string>

using namespace std;

string input;
// string output;


int main(void) {

    cin>>input;

    for(int i=0; i<input.length(); i++){
        // 대문자인 경우 아스키코드 +32
        if('A' <= input[i] && input[i] <= 'Z')
            input[i] += 32;
        else
            input[i] -= 32;

        cout<<input[i];
    }

    return 0;
}
