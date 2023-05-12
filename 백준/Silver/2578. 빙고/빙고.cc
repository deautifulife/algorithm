#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[5][5];
pair<int, int> num[26];

bool check() {
    int bingo = 0;
    int cross_r = 0;
    int cross_l = 0;
    for(int i=0; i<5; i++){
        int col = 0;
        int row = 0;
        for(int j=0; j<5; j++){
            if(arr[i][j] == 0)
                row++;
            if(arr[j][i] == 0)
                col++;
        }
        if(col == 5)
            bingo++;
        if(row == 5)
            bingo++;
        if(arr[i][i] == 0)
            cross_r++;
        if(arr[i][4-i]==0)
            cross_l++;
    }
    if(cross_r == 5)
        bingo++;
    if(cross_l == 5)
        bingo++;
    if(bingo>=3)
        return true;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //빙고판 입력
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
            num[arr[i][j]] = {i,j}; //숫자 배열에 좌표 저장
        }
    }

    int ans = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            ans++;
            int number;
            cin>>number;
            arr[num[number].first][num[number].second] = 0; //해당좌표 0으로 바꾸기
            if(i>1){ //10번이상 입력되면
                if(check()){
                    cout<<ans;
                    return 0;
                }
            }
        }
    }

	return 0;
}