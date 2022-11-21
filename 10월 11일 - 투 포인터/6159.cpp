#include <iostream>

using namespace std;
int n, s, cnt = 0;
int cow[20000];

void costume()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cow[i] + cow[j] <= s)
            {
                cnt++;
            }
        }
    }
}

int main()
{
    cin >> n >> s;
    
    for(int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    
    costume();
    
    cout << cnt;

    return 0;
}
