#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n; //시작 현금

    vector<int> v; //날별 주식 가격
    for(int i=0; i<14; i++){
        int inp;
        cin>>inp;
        v.push_back(inp);
    }

    int jun =0, sung =0;
    int _n = n;
    
    //준현이의 매수
    for(auto it : v){
        if(it <= _n){
            jun = _n / it;
            _n = _n % it;
            break;
        }
    }

    jun = _n + (jun * v[13]); //마지막날 매도

    int cnt =0;
    int buy_idx = 999999; // 왜한거지?
    for(int i=1; i<v.size(); i++){
        //하락하는지 보는 것
        if(v[i] < v[i-1])
            cnt++;
        else cnt = 0;
        //3일 연속 하락 = 매수시점
        if(cnt >=3){
            sung += n / v[i];
            n = n % v[i];
            buy_idx = i; //매수일 기억
        }
    }
    cnt = 0;
    bool flag = false;
    for(int i = buy_idx+1; i<v.size(); i++){
        //상승하는지 보는 것
        if(v[i] > v[i-1])
            cnt++;
        else cnt =0;
        //3일 연속 상승 == 매도 시점
        if(cnt >= 3){
            flag = true; //매도했음을 기록
            sung = sung * v[i];
            break;
        }
    }

    if(!flag)
        sung = n + (sung * v[13]); //매도 안했었으면 마지막날 매도
        if(sung > jun)
            cout<<"TIMING";
        else if(sung < jun)
            cout<<"BNP";
        else
            cout<<"SAMESAME";
	return 0;
}