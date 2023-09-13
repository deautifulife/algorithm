#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

struct ROBOT {
	int y, x, dir;
};

int n, m;
int map[50][50];
ROBOT robot;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.dir;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x]; 
		}
	}

	queue<ROBOT> q;
	q.push(robot);

	int ret = 0;
	while (!q.empty()) {
		ROBOT cur = q.front();
		q.pop();
		if (map[cur.y][cur.x] == 0) {
			map[cur.y][cur.x] = 2; //청소함
			ret++;
		}

		for (int dir = 0; dir < 4; dir++) {
			ROBOT next;
			next.dir = (cur.dir + 3 + (dir * 3)) % 4; //시계방향 3번이면 반시계 1번, 2번째, 3번째 돌때는 +3,6,9 더해줌
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] != 0) {
				continue;
			}
			q.push(next);
			break; //로봇은 큐에 하나만 유지해야하기 때문에 break
		}

		//로봇이 갈 곳이 없을때 180도 회전
		if (q.empty()) {
			ROBOT next;
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir + 2) % 4];
			next.x = cur.x + dx[(next.dir + 2) % 4];
			
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1) {
				break;
			}
			
			q.push(next);
		}
	}

	cout << ret;

	return 0;
}