#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string input;
    int here = 0;
    vector<char> answer(1000000);
    
    while(n--)
    {
        cin >> input;

        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '<')
            {
                if(here != 0)
                {
                    here--;
                }
            }
            else if(input[i] == '>')
            {
                if(here != input.size())
                {
                    here++;
                }
            }
            else if(input[i] == '-' && here != 0)
            {
                if(here != 0)
                {
                    answer.erase(answer.begin() + here - 1);
                    here--;
                }
            }
            else
            {
                answer.insert(answer.begin() + here, input[i]);
                here++;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}
