#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int alpha[26];

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        memset(alpha, 0, sizeof(alpha));
        int max = 0;
        char ans;
        string str;

        getline(cin, str);

        for(int i=0; i<str.length(); i++){
            if(str[i] == ' ')
                continue;
            else
                alpha[str[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(alpha[i] > max){
                max = alpha[i];
                ans = (char)i+'a';
            }
            else if(alpha[i] == max)
                ans = '?';
        }
        cout<<ans<<'\n';
    }

	return 0;
}