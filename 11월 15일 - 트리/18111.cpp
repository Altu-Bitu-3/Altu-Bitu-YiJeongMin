#include <iostream>

using namespace std;
int n, m, b;
int minNum = 256;
int maxNum = 0;
int ground[500][500];

int main()
{
    int mint = 987654321;
    int minh = -1;
    
    cin >> n >> m >> b;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ground[i][j];
            if(minNum > ground[i][j])
            {
                minNum = ground[i][j];
            }
            if(maxNum < ground[i][j])
            {
                maxNum = ground[i][j];
            }
        }
    }
    
    for(int i = minNum; i < maxNum; i++)
    {
        int t = 0;
        int x = 0; //넣을 블록
        int y = 0; //꺼낼 블록
        
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                int block = i - ground[j][k];
                //음수면
                if(block < 0)
                {
                    y += -block;
                }
                else
                {
                    x += block;
                }
            }
        }
        
        if(x <= y + b)
        {
            t = x + y * 2;
            if(t <= mint)
            {
                mint = t;
                minh = i;
            }
        }
    }
    
    cout << mint << " " << minh;
}
