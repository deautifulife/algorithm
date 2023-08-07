#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int>> graph;
vector <int> sequence;
vector <int> visited;
int seq;

void dfs(int n) {
    sequence[n] = ++seq;
    visited[n] = 1;
    int nextd;
    for (int i = 0; i < graph[n].size(); i++) {
        nextd = graph[n][i];
        if (visited[nextd] == 0)
            dfs(nextd);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;
    graph.resize(n + 1);
    visited.resize(n + 1);
    sequence.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        //방향이 없으니까 양방향
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(r);
    for (int i = 1; i <= n; i++)
        cout << sequence[i]<<'\n';

    return 0;
}