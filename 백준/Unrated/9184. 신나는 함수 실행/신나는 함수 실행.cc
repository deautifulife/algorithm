#include <iostream>

using namespace std;

int dp[21][21][21]; //어차피 음수면 1을 바로 리턴하고 20을 넘으면 20으로 낮춰버리니까 21이면 넉넉하다.

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return w(20,20,20);
    //dp배열에 계산된 값이 생기면 리턴
    if(dp[a][b][c] != 0)
        return dp[a][b][c];
    if(a < b && b < c){
        dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }
    else{
        dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1)
            break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<'\n';
    }
    
    return 0;

}
