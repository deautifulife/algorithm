#include <iostream>

using namespace std;

char board[51][51];
char white_board[8][8] = {
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
};

char black_board[8][8] = {
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
};

int white_first(int x, int y){
    int result = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if(board[x+i][y+j] != white_board[i][j])
                result++;
        }
    }
    return result;
}

int black_first(int x, int y){
    int result = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if(board[x+i][y+j] != black_board[i][j])
                result++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int result=9999;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>board[i][j];

    int coloring_w, coloring_b;
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            coloring_w = white_first(i,j);
            coloring_b = black_first(i,j);
            if(coloring_w < coloring_b){
                if(coloring_w < result)
                    result = coloring_w;
            }
            else {
                if(coloring_b < result)
                    result = coloring_b;        
            }
        }
    }
    cout<<result;

    
    return 0;

}
