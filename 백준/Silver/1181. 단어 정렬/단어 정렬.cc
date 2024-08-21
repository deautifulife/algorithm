#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> word;

bool compare(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        word.push_back(str);
    }
    
    sort(word.begin(), word.end(), compare);
    for (int i = 0; i < n; i++) {
        if (i > 0 && word[i] == word[i - 1])
            continue;
        cout << word[i] << '\n';
    }

}