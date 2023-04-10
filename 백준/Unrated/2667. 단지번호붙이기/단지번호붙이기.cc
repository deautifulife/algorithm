#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[30][30];
bool visited[30][30];
vector<int> answer;
//오 아 왼 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    cin>>n;
    for(int i=0; i<n; i++) {
        string num;
        cin>>num;
        for(int j=0; j<n; j++) {
            map[i][j]=num[j]-'0';
        }
    }

    //탐색
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] == false && map[i][j] == 1) //방문한 적없고 집이 있으면
                bfs(i,j);
        }
    }

    //정렬 및 도출
    sort(answer.begin(), answer.end());
    cout<<answer.size() << '\n';
    for(int i=0; i< answer.size(); i++)
        cout<<answer[i]<<'\n';
}

void bfs(int row, int col) {
    queue<pair<int,int>> q; //큐 생성
    q.push(make_pair(row,col)); 
    visited[row][col] = true; //현위치 방문 체크
    int cnt = 0;
    cnt++; //집 하나 추가요
    while(!q.empty()) {
        int front_x = q.front().first;
        int front_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            // next_x, next_y는 다음으로 push할 index 후보
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
             //맵 범위 한정에서 다음 좌표가 방문한적 없으며 집이 있는 경우
            if(0<= next_x && next_x < n && 0<= next_y && next_y < n && visited[next_x][next_y] == false && map[next_x][next_y] ==1 ) {
                q.push(make_pair(next_x, next_y)); //다음 좌표 푸쉬
                visited[next_x][next_y] = true; //다음 좌표 방문 체크
                cnt++; // 집 하나 또 추가요
            }
        }
    }
    answer.push_back(cnt); //집 개수 추가
}