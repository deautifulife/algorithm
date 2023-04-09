#include <iostream>

using namespace std;

static int n;
static int tree[26][2]; //[알파벳 수][왼,오]


void preOrder(int now);
void inOrder(int now);
void posOrder(int now);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    
    for(int i=0; i<n; i++) {
        char node_char, left, right;
        cin>>node_char>>left>>right;
        int node = node_char - 'A'; //node를 인덱스로 변환시키기 위한 연산

        if(left == '.') {
            tree[node][0] = -1;
        }
        else {
            tree[node][0] = left - 'A';
        }

        if(right == '.') {
            tree[node][1] = -1;
        }
        else {
            tree[node][1] = right - 'A';
        }
    }

    preOrder(0);
    cout<<'\n';
    inOrder(0);
    cout<<'\n';
    posOrder(0);
    cout<<'\n';

    return 0;
}

void preOrder(int now) { // 현재 -> 왼쪽 -> 오른쪽 순서로
    if(now == -1) 
        return;
    cout<<(char)(now + 'A'); // 현재
    preOrder(tree[now][0]); // 왼
    preOrder(tree[now][1]); // 오
}
void inOrder(int now) { // 왼 -> 현재 -> 오
    if(now == -1)
        return;
    inOrder(tree[now][0]);
    cout<<(char)(now + 'A'); // 현재
    inOrder(tree[now][1]);
}
void posOrder(int now) {
    if(now == -1)
        return;
    posOrder(tree[now][0]);
    posOrder(tree[now][1]);
    cout<<(char)(now + 'A'); // 현재
}