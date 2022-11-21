#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string input;
    int answer = n;
    
    while(n--)
    {
        cin >> input;
        vector<int> check(26, 0);
        
        check[input[0] - 97] = 1;
        
        for(int i = 1; i < input.length(); i++)
        {
            if(input[i] != input[i - 1])
            {
                int num = input[i] - 97;
                
                if(check[num] == 0)
                {
                    check[num]++;
                }
                else
                {
                    answer--;
                    break;
                }
            }
        }
    }
    
    cout << answer;
}
