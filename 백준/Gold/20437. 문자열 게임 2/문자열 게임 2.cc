#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string str;
        int k;
        cin>>str>>k;

        //str의 알파벳 문자별로 등장 빈도수 저장
        vector<int> count(26);
        for(int i=0; i<str.length(); i++)
            count[str[i] - 'a']++; //ex) count[0] = 3은 'a'가 str에 3번 등장했다는 뜻

        int answer3 = 99999;
        int answer4 = -1;
        for(int i=0; i<str.length(); i++){
            //빈도수가 K개 미만인 문자들은 문자열을 못만드므로 스킵한다.
            if(count[str[i]-'a'] < k)
                continue;

            int cnt =0;
            //연속 문자열의 시작 문자 str[i]
            for(int j=i; j<str.length(); j++){
                if(str[i] ==str[j]) //str[j]와 같다면 카운트 (자동으로 시작문자 = 끝문자 인 연속 문자열이 되는 것이기 때문)
                    cnt++;

                if(cnt == k){ // 카운트 수가 K와 같을 때 길이 업데이트
                    answer3 = min(answer3, j-i+1);
                    answer4 = max(answer4, j-i+1);
                    break;
                }
            }
        }

        if(answer3 == 99999 || answer4 == -1)
            cout<<-1<<'\n';
        else
            cout<<answer3<<" "<<answer4<<'\n';
    }
	return 0;
}