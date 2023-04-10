#include <iostream>
#include <queue>
// #include <vector>
#include <cstring> //memset

using namespace std;

int m,n;
int ans;
char map[50][50];
int pVisited[50][50];
//오 아 왼 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int bfs(int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //맵 구성
    cin>>m>>n;    
    for(int i=0; i<m; i++){
        string wl;
        cin>>wl;
        for(int j=0; j<n; j++) {
            map[i][j]=wl[j];
        }
    }

    //탐색
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if(map[i][j]=='L')
                ans = max(bfs(i,j),ans);
                //방문 배열 초기화
                for(int k=0; k<m; k++) {
                    memset(pVisited[k], 0, sizeof(pVisited[k]));
                }
        }
    }
    cout<<ans-1;
}

int bfs(int row, int col) {
    if(map[row][col]=='W')
        return 0;
    int cnt=0;
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    pVisited[row][col]= 1; // 현 위치 방문 체크
    while(!q.empty()) {
        int front_x = q.front().first;
        int front_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];

            if(!(0<=next_x && next_x < m && 0<=next_y && next_y < n))
                continue;
            if(pVisited[next_x][next_y] == 0 && map[next_x][next_y] == 'L'){
                q.push(make_pair(next_x, next_y));
                pVisited[next_x][next_y] = pVisited[front_x][front_y] + 1;
                cnt = max(cnt, pVisited[next_x][next_y]);
            }
        }
    }
    return cnt;
}