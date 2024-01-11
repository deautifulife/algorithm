#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> graph[100001];
int visit[100001];
int ret[100001];

// 큐
void BFS(int v) {
    queue<int> q; //큐 생성
    q.push(v); //시작노드를 큐에 넣음

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if (visit[child]==0) {
                visit[child] = 1;
                ret[child] = parent;
                q.push(child);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    BFS(1);

    for (int i = 2; i <= n; i++) {
        cout << ret[i] << '\n';
    }



   
}