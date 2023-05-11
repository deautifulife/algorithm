#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s[3], e[3], ans[3];

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strS, strE;
    cin>>strS>>strE;
    s[0] = (strS[0]-'0') * 10 + (strS[1]-'0');
    s[1] = (strS[3]-'0') * 10 + (strS[4]-'0');
    s[2] = (strS[6]-'0') * 10 + (strS[7]-'0');
    e[0] = (strE[0]-'0') * 10 + (strE[1]-'0');
    e[1] = (strE[3]-'0') * 10 + (strE[4]-'0');
    e[2] = (strE[6]-'0') * 10 + (strE[7]-'0');

    if(e[2] >= s[2])
        ans[2] = e[2] - s[2];
    else{
        ans[2] = 60 + e[2] - s[2];
        e[1]--;
    }

    if(e[1] >= s[1])
        ans[1] = e[1] - s[1];
    else{
        ans[1] = 60 + e[1] - s[1];
        e[0]--;
    }

    if(e[0] >= s[0])
        ans[0] = e[0] - s[0];
    else{
        ans[0] = 24 + e[0] - s[0];
    }

    if(ans[0] == 0 && ans[1] == 0 && ans[2] == 0)
        ans[0] = 24;

    // cout<<ans[0]<<":"<<ans[1]<<":"<<ans[2];
    printf("%02d:%02d:%02d\n", ans[0], ans[1], ans[2]);  
        

	return 0;
}