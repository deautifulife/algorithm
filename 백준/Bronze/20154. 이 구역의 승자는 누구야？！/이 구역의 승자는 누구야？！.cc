#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int sum;
    int line[26] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

    cin>>str;
    for(int i=0; i<str.length(); i++){
        sum += line[str[i]-'A'];
        if(sum>10)
            sum = sum%10;
    }
    if(sum%2==1)
        cout<<"I'm a winner!";
    else
        cout<<"You're the winner?";

	return 0;
}