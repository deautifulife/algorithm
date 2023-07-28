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

void bfs(int row, int col){
    queue<pair<int,int>> q;
    q.push(make_pair(row,col));
    visited[row][col] = true;
    int cnt = 1;
    while(!q.empty()){
        int front_x = q.front().first;
        int front_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        string num;
        cin>>num;
        for(int j=0; j<n; j++){
            map[i][j] = num[j]-'0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false && map[i][j] == 1)
                bfs(i,j);
        }
    }

    sort(answer.begin(), answer.end());
    cout<<answer.size()<<'\n';
    for(int i=0; i<answer.size(); i++)
        cout<<answer[i]<<'\n';
}