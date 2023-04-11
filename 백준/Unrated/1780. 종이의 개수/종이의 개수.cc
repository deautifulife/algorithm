#include <iostream>

using namespace std;

int paper[3000][3000];
int a,b,c;

void Cut(int size, int x, int y) {
    int current = paper[x][y];

    for(int i=x; i< x+size; i++){
        for(int j= y; j<y+size; j++){
            if(paper[i][j] != current) {
                Cut(size/3, x, y);
                Cut(size/3, x, y+size/3);
                Cut(size/3, x, y+size/3*2);
                Cut(size/3, x+size/3, y);
                Cut(size/3, x+size/3, y+size/3);
                Cut(size/3, x+size/3, y+size/3*2);
                Cut(size/3, x+size/3*2, y);
                Cut(size/3, x+size/3*2, y+size/3);
                Cut(size/3, x+size/3*2, y+size/3*2);
                return;
            }
        }
    }
    if(current == -1)
        a++;
    if(current == 0)
        b++;
    if(current ==1)
        c++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>paper[i][j];
        }
    }
    Cut(n,0,0);

    cout<<a<<'\n';
    cout<<b<<'\n';
    cout<<c<<'\n';

    return 0;

}
