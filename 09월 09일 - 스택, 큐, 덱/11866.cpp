#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
queue<int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int t = m;
    
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    
    while(!q.empty())
    {
        for(int i = 1; i < m; i++)
        {
            q.push(q.front());
            q.pop();
        }
        arr.push(q.front());
        q.pop();
    }
    
    cout << "<";
    for(int i = 0; i < n - 1; i ++)
    {
        cout << arr.front() << ", ";
        arr.pop();
    }
    cout << arr.front() << ">";
}
