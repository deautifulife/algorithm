#include <iostream>

using namespace std;

struct POS {
	int y, x, d; 
};

//오왼위아래
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

int n, k;
int color[12][12];
int map[12][12][5]; //3차원 배열로 최대 4개의 말까지 쌓을 수 있으므로 
					//첫번째 배열에는 갯수가 들어가고 나머지는 말의 인덱스가 들어가도록함

int pos_size;
POS pos[10];

int turn(int index) {
	POS cur = pos[index];
	POS next;
	next.y = cur.y + dy[cur.d];
	next.x = cur.x + dx[cur.d];
	next.d = cur.d;

	if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n || color[next.y][next.x] == 2) {
		next.d = (cur.d == 0 || cur.d == 2) ? (cur.d + 1) : (cur.d - 1);
		next.y = cur.y + dy[next.d];
		next.x = cur.x + dx[next.d];
		pos[index].d = next.d; //방향이 갱신된 방향으로 들어가도록 
		if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n || color[next.y][next.x] == 2) {
			return map[cur.y][cur.x][0]; //현재 위치 말의 개수를 리턴
		}
	}

	//말보다 위에 있는 말을 체크
	int bottom = -1;
	int& cur_size = map[cur.y][cur.x][0];
	for (int i = 1; i <= cur_size; i++) {
		if (map[cur.y][cur.x][i] == index) {
			bottom = i;
			break;
		}
	}

	int move[5] = { 0, };
	int& move_size = move[0];
	for (int i = bottom; i <= cur_size; i++) {
		move[++move_size] = map[cur.y][cur.x][i];
	}
	cur_size = bottom - 1; //쌓은 말이 움직이면 cur_size가 줄어든다.

	//빨간판 뒤집기
	if (color[next.y][next.x] == 1) {
		for (int i = 1; i <= move_size / 2; i++) {
			int temp = move[i];
			move[i] = move[move_size - i + 1];
			move[move_size - i + 1] = temp;
		}
	}

	//move배열에 있는 애를 next위치에 쌓아준다.
	int& next_size = map[next.y][next.x][0];
	for (int i = 1; i <= move_size; i++) {
		map[next.y][next.x][++next_size] = move[i];
		pos[move[i]].y = next.y;
		pos[move[i]].x = next.x;
		if (next_size >= 4) {
			return next_size;
		}
	}
	return next_size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> color[y][x];
		}
	}
	for (int i = 0; i < k; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		y--, x--, d--; //인덱스가 0부터 시작이므로 -1
		pos[pos_size].y = y;
		pos[pos_size].x = x;
		pos[pos_size].d = d;
		int& size = map[y][x][0]; //&는 둘다 같은 메모리를 참조하여 map[y][x][0]이 변할때 size가 변하고
								  //size가 변할때 배열의 값들이 변한다.
		map[y][x][++size] = pos_size;
		pos_size++;
	}
	int loop = 0, ret = -1;
	while (loop <= 1000 && ret == -1) {
		loop++;
		for (int i = 0; i < k; i++) {
			int h = turn(i); //말의 인덱스를 넣고 턴을 시키면 한 칸 움직이도록 하고 움직인 칸의 높이를 리턴
			if (h >= 4) {
				ret = loop;
				break;
			}
		}
	}
	cout << ret;

	return 0;
}