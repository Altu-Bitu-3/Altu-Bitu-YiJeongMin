#include <iostream>
#include <algorithm>

using namespace std;
int alphabet[26];
string input;

int main()
{
    cin >> input;
    
    for(int i = 0; i < input.length(); i++)
    {
        alphabet[input[i] - 'A']++;
    }
    
    int check = 0;
    int middle = 100;
    
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] % 2 == 1)
        {
            middle = i;
            check++;
        }
    }
    
    if(check > 1)
    {
        cout << "I\'m Sorry Hansoo";
    }
    else
    {
        string answer;
        for(int i = 0; i < 26; i++)
        {
            if(alphabet[i] > 0)
            {
                for(int j = 0; j < alphabet[i] / 2; j++)
                answer += i + 'A';
            }
        }
        
        string temp = answer;
        reverse(temp.begin(), temp.end());
        
        if(middle != 100)
        {
            answer += middle + 'A';
        }
        
        answer += temp;
        
        cout << answer;
    }

    return 0;
}
