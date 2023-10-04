#include <iostream>

using namespace std;

struct CELL {
	int s, d, z; //상어의 속도 방향 크기
};

int r, c, m; //맵크기, 상어정보 수
CELL map[2][100][100]; //스왑을 위해 2개

int fishing(int cur, int pos) {
	int size = 0;
	for (int y = 0; y < r; y++) {
		//상어 잡고 상어 초기화
		if (map[cur][y][pos].z != 0) {
			size = map[cur][y][pos].z;
			map[cur][y][pos].s = 0;
			map[cur][y][pos].d = 0;
			map[cur][y][pos].z = 0;
			break;
		}
	}
	return size;
}

//1-> up
//2-> down
//3-> right
//4-> left
void move(int cur) {
	int next = (cur + 1) % 2;
	//next map 초기화
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			map[next][y][x].s = 0;
			map[next][y][x].d = 0;
			map[next][y][x].z = 0;
		}
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[cur][y][x].z != 0) {
				//y감소
				if (map[cur][y][x].d == 1) {
					//map의 끝자리는 왕복시 1번만 이동하고 나머지값들은 2번씩 이동
					int ny = (((r - 1) * 2) - y) + map[cur][y][x].s;
					ny = (ny % ((r - 1) * 2)); //map의 크기보다 ny가 커질 수 있기 때문에 모듈러 연산을 통해 자리 자리를 찾음
					int nd = 2; //일단 y증가로 초기화
					if (ny >= (r - 1)) { //ny가 감소하는 방향이면
						ny = ((r - 1) * 2) - ny;
						nd = 1;
					}
					//상어 갱신
					if (map[next][ny][x].z < map[cur][y][x].z) {
						map[next][ny][x].s = map[cur][y][x].s;
						map[next][ny][x].d = nd;
						map[next][ny][x].z = map[cur][y][x].z;
					}
				}
				//y증가
				else if (map[cur][y][x].d == 2) {
					int ny = y + map[cur][y][x].s;
					ny = (ny % ((r - 1) * 2)); //map의 크기보다 ny가 커질 수 있기 때문에 모듈러 연산을 통해 자리 자리를 찾음
					int nd = 2; //일단 y증가로 초기화
					if (ny >= (r - 1)) { //ny가 감소하는 방향이면
						ny = ((r - 1) * 2) - ny;
						nd = 1;
					}
					//상어 갱신
					if (map[next][ny][x].z < map[cur][y][x].z) {
						map[next][ny][x].s = map[cur][y][x].s;
						map[next][ny][x].d = nd;
						map[next][ny][x].z = map[cur][y][x].z;
					}
				}
				//x증가
				else if (map[cur][y][x].d == 3) {
					int nx = x + map[cur][y][x].s;
					nx = (nx % ((c - 1) * 2)); //map의 크기보다 nx가 커질 수 있기 때문에 모듈러 연산을 통해 자리 자리를 찾음
					int nd = 3; //일단 x증가로 초기화
					if (nx >= (c - 1)) { //nx가 감소하는 방향이면
						nx = ((c - 1) * 2) - nx;
						nd = 4;
					}
					//상어 갱신
					if (map[next][y][nx].z < map[cur][y][x].z) {
						map[next][y][nx].s = map[cur][y][x].s;
						map[next][y][nx].d = nd;
						map[next][y][nx].z = map[cur][y][x].z;
					}
				}
				//x감소
				else if (map[cur][y][x].d == 4) {
					int nx = (((c - 1) * 2) - x) + map[cur][y][x].s;
					nx = (nx % ((c - 1) * 2)); //map의 크기보다 nx가 커질 수 있기 때문에 모듈러 연산을 통해 자리 자리를 찾음
					int nd = 3; //일단 x증가로 초기화
					if (nx >= (c - 1)) { //nx가 감소하는 방향이면
						nx = ((c - 1) * 2) - nx;
						nd = 4;
					}
					//상어 갱신
					if (map[next][y][nx].z < map[cur][y][x].z) {
						map[next][y][nx].s = map[cur][y][x].s;
						map[next][y][nx].d = nd;
						map[next][y][nx].z = map[cur][y][x].z;
					}
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c >> m;
	int y, x, cur = 0;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		y--, x--; //인덱스가 0부터이므로
		cin >> map[cur][y][x].s>>map[cur][y][x].d>>map[cur][y][x].z;
	}

	int ret = 0;
	for (int pos = 0; pos < c; pos++) {
		ret += fishing(cur, pos);
		move(cur);
		cur = (cur + 1) % 2;
	}
	cout << ret;

	return 0;
}