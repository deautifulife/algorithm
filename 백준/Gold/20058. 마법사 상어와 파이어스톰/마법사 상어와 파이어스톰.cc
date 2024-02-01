#include <iostream>

using namespace std;

int N,Q;
int arr[64][64];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void rotate(int cy, int cx, int len, int unit){
    if(len == unit){
        int back[64][64]; //백업 변수
        for(int y=0; y<len; y++){
            for(int x=0; x<len; x++){
                back[cy+x][cx+len - y -1] = arr[cy + y][cx + x];
            }
        }
        for(int y=0; y<len; y++){
            for(int x=0; x<len; x++){
                arr[cy + y][cx + x] = back[cy+y][cx+x];
            }
        }
        return;
    }
    len /= 2;
    rotate(cy, cx, len, unit);
    rotate(cy+len, cx, len, unit);
    rotate(cy, cx+len, len, unit);
    rotate(cy+len, cx+len, len, unit);

}

void melt(){
    int len = (1<<N);
    int back[64][64];
    for(int y=0; y<len; y++){
        for(int x=0; x<len; x++){
            int cnt =0;
            for(int d=0; d<4; d++){
                int ny = y+dy[d];
                int nx = x+dx[d];
                if(ny < 0 || ny >= len || nx<0 || nx>=len){
                    continue;
                }
                if(arr[ny][nx] == 0){
                    continue;
                }
                cnt++;
            }
            if(cnt >= 3 || arr[y][x] == 0){
                back[y][x] = arr[y][x];
            }
            else{
                back[y][x] = arr[y][x]-1;
            }
        }
    }
    for(int y=0; y<len; y++){
            for(int x=0; x<len; x++){
                arr[y][x] = back[y][x];
            }
        }
}

void dfs(int y, int x, bool visited[64][64], int& size){
    size++;
    int len = (1<<N);
    for(int d=0; d<4; d++){
        int ny= y+dy[d];
        int nx= x+dx[d];
        if(nx<0 || nx>= len || ny < 0 || ny>len){
            continue;
        }
        if(visited[ny][nx] == true || arr[ny][nx] == 0){
            continue;
        }
        visited[ny][nx] = true;
        dfs(ny,nx,visited, size);
    }
}

int main(){

    cin>>N>>Q;
    int len = (1<<N); //2의n승을 구현하기 위한 비트연산 1을 1번 쉬프트하면 *2가 된다. 그래서 2번 쉬프트하고 N번 쉬프트하면 2의 N승

    //입력
    for(int y=0; y<len; y++){
        for(int x=0; x<len; x++){
            cin>>arr[y][x];
        }
    }

    //Q번 파이어스톰
    while(Q--){
        int L;
        cin>>L;
        //시뮬레이션 조건
        if(L>0){
            rotate(0,0,len,(1<<L));
        }
        melt();
    }
    
    int total = 0, maxsize = 0;
    bool visited[64][64] = {false, };
    for(int y=0; y<len; y++){
        for(int x=0; x<len; x++){
            total += arr[y][x];
            if(visited[y][x] == false && arr[y][x] != 0){
                visited[y][x] = true;
                int cursize =0;
                dfs(y,x,visited,cursize);
                if(maxsize < cursize){
                    maxsize = cursize;
                }
            }
        }
    }
    cout<<total<<"\n"<<maxsize;

    return 0;
}