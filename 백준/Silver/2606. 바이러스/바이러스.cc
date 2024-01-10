#include <iostream>
#include <queue>

using namespace std;

int com[101][101];
int visited[101];
int n, c;

void bfs(int v) {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int next = q.front();
		visited[next] = 1;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (com[next][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1; //중복 방문 방지하기 위해
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}

	bfs(1);

	int ret = 0;
	for (int i = 2; i <= n; i++) {
		if (visited[i] == 1)
			ret++;
	}
	cout << ret;


	return 0;
}