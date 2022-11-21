#include <iostream>

using namespace std;
int t; //t: 테스트 케이스의 개수
int m, n, k; //m: 배추밭의 가로 길이, n: 배추밭의 세로 길이, k: 배추가 심어져 있는 위치의 개수
int x, y; //x, y: 배추의 위치
int cab[50][50]; //배추밭
int visited[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
        {
            continue;
        }
        if(cab[nx][ny] == 1 && visited[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin >> t;
    
    while(t--)
    {
        cin >> m >> n >> k;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cab[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        
        while(k--)
        {
            cin >> x >> y;
            cab[x][y] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cab[i][j] == 1 && visited[i][j] == 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}
