// 21/11/11

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
string boomb;
string output;
vector<pair<int, int>> arr;

void check(void){
    int boomb_size = (int)boomb.size();
    int j=0;

    for (int i=0; i<(int)str.size(); i++){
        if (str[i] != boomb[j]){
            j = 0;
        }
        if (str[i] == boomb[j]){
            arr.push_back({i, j});
            j++;
            if (j==boomb_size){
                for (int k=0; k<boomb_size; k++)
                    arr.pop_back();
                if (arr.empty())
                    j=0;
                else
                    j=arr.back().second+1;
            }
        }
        else {
            for (int k=0; k<(int)arr.size(); k++)
            {
                output += str[arr[k].first];
            }
            arr.clear();
            output+=str[i];
        }
    }
    for (int k=0; k<(int)arr.size(); k++)
        output += str[arr[k].first];
}

int main(void){
    cin >> str >> boomb;

    check();

    if (output.length() == 0)
        cout << "FRULA";
    else
        cout << output;

    return 0;
}