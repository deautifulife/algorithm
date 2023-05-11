#include <iostream>
#include <cstring>

using namespace std;


int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string nstr;
    string keyword;
    cin>>str>>keyword;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A')
            nstr+=str[i];
    }

    if(nstr.find(keyword) < nstr[nstr.length()-1])
        cout<<1;
    else
        cout<<0;
    
	return 0;
}