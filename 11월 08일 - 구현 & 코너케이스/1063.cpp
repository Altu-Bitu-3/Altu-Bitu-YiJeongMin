#include <iostream>
#include <vector>
#include <string>

using namespace std;
string king, stone, rlbt;
int n;
vector<pair<int, int>> c(2);

int main()
{
    cin >> king >> stone >> n;
    
    for(int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            int num = 1;
            for(char j = 'A'; j <= 'H'; j++)
            {
                if(king[i] == j)
                {
                    c[0].first = num;
                }
                else
                {
                    num++;
                }
            }
        }
        else
        {
            c[0].second = king[1] - '0';
        }
    }
    
    for(int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            int num = 1;
            for(char j = 'A'; j <= 'H'; j++)
            {
                if(stone[i] == j)
                {
                    c[1].first = num;
                }
                else
                {
                    num++;
                }
            }
        }
        else
        {
            c[1].second = stone[1] - '0';
        }
    }
    
    while(n--)
    {
        cin >> rlbt;
        
        if(rlbt == "R") //한 칸 오른쪽으로
        {
            if(c[0].first + 1 < 9)
            {
                c[0].first++;
                
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first + 1 < 9)
                    {
                        c[1].first++;
                    }
                    else
                    {
                        c[0].first--;
                    }
                }
            }
        }
        else if(rlbt == "L") //한 칸 왼쪽으로
        {
            if(c[0].first - 1 > 0)
            {
                c[0].first--;
                
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first - 1 > 0)
                    {
                        c[1].first--;
                    }
                    else
                    {
                        c[0].first++;
                    }
                }
            }
        }
        else if(rlbt == "B") //한 칸 아래로
        {
            if(c[0].second - 1 > 0)
            {
                c[0].second--;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].second - 1 > 0)
                    {
                        c[1].second--;
                    }
                    else
                    {
                        c[0].second++;
                    }
                }
            }
        }
        else if(rlbt == "T") //한 칸 위로
        {
            if(c[0].second + 1 < 9)
            {
                c[0].second++;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].second + 1 < 9)
                    {
                        c[1].second++;
                    }
                    else
                    {
                        c[0].second--;
                    }
                }
            }
        }
        else if(rlbt == "RT") //오른쪽 위 대각선으로
        {
            if(c[0].first + 1 < 9 && c[0].second + 1 < 9)
            {
                c[0].first++;
                c[0].second++;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first + 1 < 9 && c[1].second + 1 < 9)
                    {
                        c[1].first++;
                        c[1].second++;
                    }
                    else
                    {
                        c[0].first--;
                        c[0].second--;
                    }
                }
            }
        }
        else if(rlbt == "LT") //왼쪽 위 대각선으로
        {
            if(c[0].first - 1 > 0 && c[0].second + 1 < 9)
            {
                c[0].first--;
                c[0].second++;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first - 1 > 0 && c[1].second + 1 < 9)
                    {
                        c[1].first--;
                        c[1].second++;
                    }
                    else
                    {
                        c[0].first++;
                        c[0].second--;
                    }
                }
            }
        }
        else if(rlbt == "RB") //오른쪽 아래 대각선으로
        {
            if(c[0].first + 1 < 9 && c[0].second - 1 > 0)
            {
                c[0].first++;
                c[0].second--;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first + 1 < 9 && c[1].second - 1 > 0)
                    {
                        c[1].first++;
                        c[1].second--;
                    }
                    else
                    {
                        c[0].first--;
                        c[0].second++;
                    }   
                }
            }
        }
        else //왼쪽 아래 대각선으로
        {
            if(c[0].first - 1 > 0 && c[0].second - 1 > 0)
            {
                c[0].first--;
                c[0].second--;
                if(c[0].first == c[1].first && c[0].second == c[1].second)
                {
                    if(c[1].first - 1 > 0 && c[1].second - 1 > 0)
                    {
                        c[1].first--;
                        c[1].second--;
                    }
                    else
                    {
                        c[0].first++;
                        c[0].second++;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            if(c[i].second == j)
            {
                char temp = 'A' - 1;
                temp += c[i].first;
                cout << temp << c[i].second << "\n";
            }
        }
    }
    
    return 0;
}
