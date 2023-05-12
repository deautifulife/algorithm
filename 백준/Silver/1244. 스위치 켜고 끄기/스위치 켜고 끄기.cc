#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, student, g, y;
bool arr[101];

int main(){

ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin>>n;
for(int i=1; i<=n; i++){
    cin>>arr[i]; //스위치의 상태 입력 받기
}

cin>>student; //학생 수 입력 받기
for(int k=0; k<student; k++){
    cin>>g>>y; //학생의 성별, 스위치 번호

    if(g==1) { //남학생의 경우
        for(int i=1; i<=n; i++){
            if(i%y==0) //배수일때
                arr[i]= !arr[i]; //스위치 전환
        }
    }

    else{ //여학생
        arr[y] = !arr[y]; // 우선 자기 스위치 상태 ㅏㅂ꿈
        for(int i=1; arr[y+i] == arr[y-i]; i++){ // 대칭이면 반복
            if(y+i>n || y-i<1) //인덱스 벗어나면 멈춤
                break;
            
            arr[y+i] = !arr[y+i]; //스위치 전환
            arr[y-i] = !arr[y-i]; //스위치 전환
        }
    }
}

for(int i=1; i<=n; i++){
    cout<<arr[i]<<" ";
    if(i%20==0) //20개의 숫자를 출력했다면 줄바꾸기
        cout<<'\n';
}
return 0;
}