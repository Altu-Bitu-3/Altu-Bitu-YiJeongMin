#include <iostream>
#include <string>
#include <vector>

using namespace std;
int maxDiff = 0;
int n;
vector<int> info;

bool compare(vector<int> ryan, vector<int> &answer)
{
    for(int i = 10; i >= 0; i--)
    {
        if(ryan[i] > answer[i])
        {
            return true;
        }
        else if(ryan[i] < answer[i])
        {
            return false;
        }
    }
}

void calcScore(vector<int> ryan, vector<int> apeach, vector<int> &answer)
{
    int ryanScore = 0;
    int apeachScore = 0;
    
    for(int i = 0; i < 11; i++)
    {
        if(ryan[i] > apeach[i])
        {
            ryanScore += 10 - i;
        }
        else if(apeach[i] > 0)
        {
            apeachScore += 10 - i;
        }
    }
    
    int diff = ryanScore - apeachScore;
    if(diff > 0 && maxDiff <= diff)
    {
        if(maxDiff == diff && !compare(ryan, answer))
        {
            return;
        }
        maxDiff = diff;
        answer = ryan;
    }
}

void shoot(int idx, int arrows, vector<int> ryan, vector<int> apeach, vector<int> &answer)
{
    if(idx == 11 || arrows == 0)
    {
        ryan[10] += arrows;
        calcScore(ryan, apeach, answer);
        ryan[10] -= arrows;
        return;
    }
    
    if(apeach[idx] < arrows)
    {
        ryan[idx] += apeach[idx] + 1;
        shoot(idx + 1, arrows - apeach[idx] - 1, ryan, apeach, answer);
        ryan[idx] -= apeach[idx] + 1;
    }
    
    shoot(idx + 1, arrows, ryan, apeach, answer);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> ryan(11, 0);
    vector<int> answer(11, -1);
    
    shoot(0, n, ryan, info, answer);
    
    if(answer[0] == -1)
    {
        vector<int> looseAnswer(1, -1);
        return looseAnswer;
    }
    
    return answer;
}

int main()
{
    cin >> n;
    for(int i = 0; i < 11; i++)
    {
        cin >> info[i];
    }
    
    solution(n, info);
}
