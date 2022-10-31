#include <iostream>
#include <algorithm>

using namespace std;
typedef struct
{
    int gender;
    int num;
} student;

int n; //스위치 개수
int onoff[101];
int m; //학생 수
student st[101];

void onoffSwitch()
{
    for(int i = 1; i <= m; i++)
    {
        if(st[i].gender == 1)
        {
            for(int j = st[i].num; j <= n; j += st[i].num)
            {
                onoff[j] = 1 - onoff[j];
            }
        }
        else
        {
            int a = min(st[i].num - 1, n - st[i].num);
            int cnt = 0;
            for(int j = 1; j <= a; j++)
            {
                if(onoff[st[i].num - j] == onoff[st[i].num + j])
                {
                    cnt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            for(int j = - cnt; j <= cnt; j++)
            {
                onoff[st[i].num + j] = 1 - onoff[st[i].num + j];
            }
        }
        
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << onoff[i] << " ";
        if(i % 20 == 0)
        {
            cout << "\n";
        }
    }
}

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> onoff[i];
    }
    
    cin >> m;
    
    for(int i = 1; i <= m; i++)
    {
        cin >> st[i].gender >> st[i].num;
    }
    
    onoffSwitch();

    return 0;
}
