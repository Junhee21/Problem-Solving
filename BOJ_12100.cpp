// 21/11/24

#include <iostream>
#include <vector>
using namespace std;

int n;
int answer = 0;

vector<vector<int>> pushBlock(vector<vector<int>> matrix)
{
    vector<vector<int>> output(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        vector<int> arr;
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                if (check)
                {
                    arr.push_back(matrix[i][j]);
                    check = false;
                }
                else
                {
                    if (arr.back() == matrix[i][j])
                    {
                        arr.back() *= 2;
                        check = true;
                    }
                    else
                        arr.push_back(matrix[i][j]);
                }
            }
        }
        for (int j = 0; j < (int)arr.size(); j++)
            output[i][j] = arr[j];
    }

    return output;
}

vector<vector<int>> curl(vector<vector<int>> &matrix)
{
    vector<vector<int>> output(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[n - j - 1][i] = matrix[i][j];
        }
    }
    return output;
}

void DFS(vector<vector<int>> matrix, int level)
{
    if (level == 5)
    {
        int nowAnswer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] > nowAnswer)
                    nowAnswer = matrix[i][j];
            }
        }
        if (nowAnswer > answer)
            answer = nowAnswer;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        DFS(pushBlock(matrix), level + 1);
        matrix = curl(matrix);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    DFS(matrix, 0);
    cout << answer;
    return 0;
}
