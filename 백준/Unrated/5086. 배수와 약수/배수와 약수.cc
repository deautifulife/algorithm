#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    
    int cnt = 0;
    int result[10001];
    while(1) {
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        
        if(b%a==0){
            result[cnt] = 0;
            cnt++;
            continue;
        }
        if(a%b==0){
            result[cnt] =1;
            cnt++;
            continue;
        }
        else if(b%a!=0 && a%b!=0)
            result[cnt] = 2;
            cnt++;
            continue;

    }

    for(int i=0; i<cnt; i++) {
        if(result[i]==0)
            cout<<"factor"<<'\n';
        else if(result[i]==1)
            cout<<"multiple"<<'\n';
        else if(result[i]==2)
            cout<<"neither"<<'\n';
    }

    return 0;
}