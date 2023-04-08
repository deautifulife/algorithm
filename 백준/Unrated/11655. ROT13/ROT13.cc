#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    getline(cin, text);
    // cin>>text;
    // string answer;
    vector<char> answer;

    for(int i=0; i<text.length(); i++) {
        if((int)text[i]<=57)
            // answer[i] = text[i];
            answer.push_back(text[i]);
        if((int)text[i]>=65 && (int)text[i]<=90) {
            if((int)text[i]+13>90)
                // answer[i] = (char)((int)text[i]-13);
                answer.push_back((char)((int)text[i]-13));
            else
                // answer[i] = (char)((int)text[i]+13);
                answer.push_back((char)((int)text[i]+13));
        }
        if((int)text[i]>=97 && (int)text[i]<=122) {
            if((int)text[i]+13>122)
                // answer[i] = (char)((int)text[i]-13);
                answer.push_back((char)((int)text[i]-13));
            else
                // answer[i] = (char)((int)text[i]+13);
                answer.push_back((char)((int)text[i]+13));
        }
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i];
    }
    

    return 0;
}