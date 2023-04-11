#include <iostream>

using namespace std;

char video[64][64];

//재귀
void quadtree(int size, int x, int y) {
    char current = video[x][y];

    for(int i=x; i< x+size; i++) {
        for(int j =y; j<y+size; j++) {
            if(video[i][j] != current)
            {
                cout<<'(';
                quadtree(size /2, x,y);
                quadtree(size /2, x, y+size/2);
                quadtree(size /2, x+size/2, y);
                quadtree(size /2, x+size/2, y+size/2);
                cout<<')';
                return;
            }
        }
    }
    //다 같은 수면
    cout<<current;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string line;
        cin>>line;
        for(int j=0; j<n; j++) {
            video[i][j]=line[j];
        }
    }

    quadtree(n, 0, 0);

    return 0;

}
