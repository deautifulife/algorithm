#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int m,n,k;
int map[50][50];
bool visited[50][50];
vector<int> answer;

//오 아 왼 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void bfs(int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        cin>>m>>n>>k;
        //맵 생성 및 입력
        for(int i=0; i<k; i++){
            int r,c;
            cin>>r>>c;
            map[r][c]++;
        }

        //탐색
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++)
            if(visited[i][j]==false && map[i][j]==1)
                bfs(i,j);
        }
        cout<<answer.size()<<'\n';
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        answer.clear();

    }

}

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    visited[row][col]= true; // 현 위치 방문 체크
    int cnt=0;
    cnt++; //배추 개수
    while(!q.empty()) {
        int front_x = q.front().first;
        int front_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];

            if(!(0<=next_x && next_x < m && 0<=next_y && next_y < n))
                continue;
            if(visited[next_x][next_y] == false && map[next_x][next_y] == 1){
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = true;
                cnt++;
            }
        }
    }
    answer.push_back(cnt);
}