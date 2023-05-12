#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
char map[11][11];
char inp[11][11];
char out[11][11];

//상,하,좌,우,왼쪽위,왼쪽아래,오른쪽위,오른쪽아래
int dx[8] = {0,0,-1,1,-1,-1,1,1};
int dy[8] = {-1,1,0,0,-1,1,-1,1};

//cnt를 왜 변수에 넣나했더니 함수 호출할때마다 0으로 초기화하려고 했나봄
int dfs(int x, int y, int cnt){
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny >= 0 && ny < N){
            if(map[nx][ny]=='*')
                cnt++;
        }
    }
    return cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool flag = false; //지뢰를 밟았는지 안밟았는지 확인
    cin>>N;

    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>inp[i][k];
        }
    }
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(inp[i][k]=='x'){
                int cnt = dfs(i,k,0);
                out[i][k] = cnt+'0';
                if(map[i][k]=='*') 
                    flag = true; //지뢰를 밟음
            }
            else if(inp[i][k]=='.')
                out[i][k] = '.';
        }
    }

    //지뢰를 밟으면 모든 지뢰자표를 알려주고 게임 종료
    if(flag){
        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                if(map[i][k]=='*')
                    out[i][k]='*';
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cout<<out[i][k];
        }
        cout<<'\n';
    }

	return 0;
}