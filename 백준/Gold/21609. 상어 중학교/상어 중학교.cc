#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

int N,M;
int board[20][20];

//가장 큰 블록그룹을 찾고 점수내기
int calcPoint(){
    int point =0;
    vector<int> maxArea; //좌표저장용 벡터
    int maxrainbow = 0;
    for(int color = 1; color<=M; color++){
        bool visited[20][20] = {false, }; //무지개 블록은 컬러가 바뀌어도 밟을 수 있으므로 for문 안에 visited 배열을 넣음
        //기준블록이 위에서 그리고 왼쪽부터 순서이므로 아래와 같은 반복문
        for(int y=0; y<N; y++){
            for(int x=0; x<N; x++){
                if(visited[y][x] == false && board[y][x] == color){
                    queue<int> q;
                    vector<int> vec;
                    int rainbow = 0;

                    q.push(y*100 + x);
                    vec.push_back(y*100 + x); //기준블록의 좌표
                    visited[y][x] = true;

                    while(!q.empty()){
                        int cy = q.front() / 100;
                        int cx = q.front() % 100;
                        q.pop();

                        for(int d=0; d<4; d++){
                            int ny = cy+dy[d];
                            int nx = cx+dx[d];
                            if(ny<0 || ny>=N || nx<0 || nx>=N){
                                continue;
                            }
                            if(visited[ny][nx] == false && (board[ny][nx] == color || board[ny][nx] == 0)){
                                q.push(ny * 100 + nx);
                                vec.push_back(ny*100 + nx);
                                visited[ny][nx] = true;
                                if(board[ny][nx] == 0){
                                    rainbow++;
                                }
                            }
                        }
                    }
                    if(maxArea.size() < vec.size() || (maxArea.size() == vec.size() && maxrainbow < rainbow) || 
                    (maxArea.size() == vec.size() && maxrainbow == rainbow && maxArea[0] < vec[0])){
                        maxArea.resize(vec.size());
                        copy(vec.begin(), vec.end(), maxArea.begin());
                        maxrainbow = rainbow;
                    }
                }
            }
        }
    }

    if(maxArea.size() >= 2){ //블록이 1개인거는 그룹으로 인정 X
        point = maxArea.size() * maxArea.size();
        //블록 제거
        for(int i=0; i<maxArea.size(); i++){
            int y= maxArea[i] / 100;
            int x = maxArea[i] % 100;
            board[y][x] = -2;
        }
    }
    return point;
}

void down(){
    for(int x=0; x<N; x++){
        int blank = 0;
        for(int y=N-1; y>=0; y--){
            if(board[y][x] == -2){
                blank++;
            }
            else if(board[y][x] == -1){
                blank = 0;
            }
            else{
                if(blank != 0){ //blank가 0이면 같은자리에 복사하고 지우는 바보같은 짓을 하게된다. 그러므로 예외처리
                    board[y+blank][x] = board[y][x];
                    board[y][x] = -2;
                }
            }
        }
    }
}
void rotate(){
    int back[20][20];

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            back[N-1-x][y] = board[y][x];
        }
    }

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            board[y][x] = back[y][x];
        }
    }
}

int solve(){
    int point =0;
    int curPoint = 0;
    do{
        curPoint = calcPoint();
        point+=curPoint;
        down();
        rotate();
        down();
    } while(curPoint !=0);

    return point;
}

int main(){

    cin>>N>>M;
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin>>board[y][x];
        }
    }

    int ret = solve();

    cout<<ret;

    return 0;
}