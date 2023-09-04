#include <iostream>
//#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int map[101][101];

//오 아 왼 위
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int head_y, head_x, tail_index; 
int snake_y[10101] , snake_x[10101];
char cmd[10001];


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int y, x;

	//사과의 위치
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}


	int time;
	char c;
	cin >> m;
	//시간과 커맨드
	for (int i = 0; i < m; i++) {
		cin >> time >> c;
		cmd[time] = c;
	}

	//초기값 세팅
	int dir = 0;
	time = 0;
	head_y = 1, head_x = 1, tail_index = time;
	snake_y[time] = head_y, snake_x[time] = head_x;
	map[head_y][head_x] = -1;

	while (1) {
		++time;

		head_y += dy[dir];
		head_x += dx[dir];

		//벽이나 지 몸에 부딫힐 경우
		if (head_y < 1 || head_y > n || head_x <1 || head_x > n || map[head_y][head_x] == -1) {
			break;
		}

		snake_y[time] = head_y;
		snake_x[time] = head_x;

		//사과 체크
		if (map[head_y][head_x] == 0) {
			int tail_y = snake_y[tail_index];
			int tail_x = snake_x[tail_index];
			map[tail_y][tail_x] = 0; //뱀의 위치가 -1이니까 0으로 초기화
			++tail_index;
		}
		map[head_y][head_x] = -1;

		if (cmd[time] == 'D') {
			dir = (dir + 1) % 4;
		}
		else if (cmd[time] == 'L') {
			dir = (dir + 3) % 4;
		}
	}

	cout << time;



	return 0;
}