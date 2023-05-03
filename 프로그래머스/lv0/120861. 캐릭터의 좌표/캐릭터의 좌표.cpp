#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x=0;
    int y=0;
    for(int i=0; i<keyinput.size(); i++){
        if(keyinput[i][0] == 'l'){
            if(x<=board[0]/2*-1)
                continue;
            x--;
        }
        else if(keyinput[i][0] == 'r'){
            if(x>=board[0]/2)
                continue;
            x++;
        }
        else if(keyinput[i][0] == 'u'){
            if(y>=board[1]/2)
                continue;
            y++;
        }
        else if(keyinput[i][0] == 'd'){
            if(y<=board[1]/2*-1)
                continue;
            y--;
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}