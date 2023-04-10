#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[101][101];
int dist[101][101];
bool visited[101][101];
//오 아 왼 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void bfs(int row, int col);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    //맵 생성
    for(int i=0; i<n; i++) {
        string row;
        cin>>row;
        for(int j=0; j<m; j++) {
            map[i][j] = row[j]-'0';
        }
    }

    //bfs 계산
    bfs(0,0);

    cout<<dist[n-1][m-1]; // 도착 좌표까지의 거리 출력
}

void bfs(int row, int col) {
    queue<pair<int,int>> q; //큐 생성
    q.push(make_pair(row,col));
    visited[row][col] = true; //현위치 방문 체크
    dist[row][col]++; //좌표 방문 카운트
    while(!q.empty()) {
        int front_x = q.front().first;
        int front_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            // next_x, next_y는 다음으로 push할 index 후보
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if(0<= next_x && next_x < n && 0<= next_y && next_y < m && visited[next_x][next_y] == false && map[next_x][next_y] == 1) { // 다음 좌표가 방문한 적 없으면서 1이면
                q.push(make_pair(next_x,next_y)); //다음 좌표 푸쉬
                visited[next_x][next_y] = true; //다음 좌표 방문 체크
                dist[next_x][next_y] = dist[front_x][front_y] + 1; //카운트
            }
        }
    }
}