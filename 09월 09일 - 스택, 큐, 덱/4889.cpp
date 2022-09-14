#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> s;
string input;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans;
    int line = 1;
    
    while(1)
    {
        cin >> input;
        ans = 0;
        
        for(int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            
            if(c == '{')
            {
                s.push(c);
            }
            
            else if(c == '}')
            {
                if(s.empty() || s.top() != '{')
                {
                    s.push(c);
                }
                else
                {
                    s.pop();
                }
            }
            else
            {
                return 0;
            }
        }
        
        while(!s.empty())
        {
            char top = s.top();
            s.pop();
            
            if(s.top() != top)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }
            s.pop();
        }
        
        cout << line++ << ". " << ans << "\n";
    }
}
