#include <iostream>
#include <cstring>

using namespace std;

int alpha[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int ans = 0;
    cin>>n;
    while(n--){
        memset(alpha, 0, sizeof(alpha));
        string str;
        bool check = 1;
        cin>>str;

        for(int i=0; i<str.length(); i++){
            if(i>0 && alpha[str[i]-'a'] > 0){
                if(str[i]==str[i-1]){
                    alpha[str[i]-'a']++;
                }
                else{
                    check = 0;
                    break;
                }
            }
            else
                alpha[str[i]-'a']++;
        }
        if(check == 1)
            ans++;
    }

    cout<<ans;
    
	return 0;
}