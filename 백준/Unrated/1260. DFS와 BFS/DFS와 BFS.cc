#include <iostream>
#include <queue>

using namespace std;

//전역 변수 - 자동 0초기화
int arr[1001][1001];
bool visit_dfs[1001];
bool visit_bfs[1001];
int n,m,v;

// 재귀
void DFS(int v) {
    visit_dfs[v] = 1; //시작 점 방문 갱신
    cout<<v<<" "; //방문한 노드 출력

    for(int i=1; i<=n; i++) {
        if(arr[v][i] == 1 && visit_dfs[i] == 0) { //지금 위치에서 인접하고 방문하지 않은 노드면
            DFS(i);
        }
        if(i==n)
            return;
    }
}

// 큐
void BFS(int v) {
    queue<int> q; //큐 생성
    q.push(v); //시작노드를 큐에 넣음

    while(!q.empty()) { //큐가 다 pop될 때까지 반복
        int next = q.front(); //큐 맨 앞 값을 방문
        visit_bfs[next] = 1; //방문한 노드 갱신
        cout << next<<" ";
        q.pop(); // 큐에서 pop

        //방문한 노드와 인접한 노드 다 큐에 push
        for(int i=1; i<=n; i++) {
            if(arr[next][i]==1 && visit_bfs[i] == 0){ //방문한 노드와 인접하고 방문한 적 없는 노드면
                q.push(i); //push
                visit_bfs[i] = 1; //i 점은 중복 방문을 방지하기위해 미리 방문기록
            }
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s,e;
    cin>>n>>m>>v;
    for(int i=0; i<m; i++) {
        cin>>s>>e;
        arr[s][e] = 1;
        arr[e][s] = 1; //방향이 정해져있지 않으므로 양방향
    }

    DFS(v);

    cout<<'\n';
    BFS(v);
}
