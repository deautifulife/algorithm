#include <iostream>

using namespace std;

int n, team;
int s; //이전 시간
int Atime,Btime,Ascore,Bscore;
string t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int min,sec;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>team>>t;
        min = stoi(t.substr(0,2));
        sec = stoi(t.substr(3,2));

        if(Ascore > Bscore){
            Atime = Atime + (min * 60) + sec - s; //초로 기록
        }
        else if(Ascore < Bscore) {
            Btime = Btime + (min * 60) + sec - s;
        }
        if(team == 1)
            Ascore++;
        else
            Bscore++;

        s = (min * 60) + sec;
    }

    if(Ascore > Bscore)
        Atime = Atime + (48 * 60) - s;
    else if(Ascore < Bscore)
        Btime = Btime + (48 * 60) - s;
    
    // cout<<Atime/60<<":"<<Atime%60<<'\n';
    // cout<<Btime/60<<":"<<Btime%60<<'\n';
    printf("%02d:%02d\n", Atime / 60, Atime % 60);
	printf("%02d:%02d\n", Btime / 60, Btime % 60);

}