#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int n;
char words[100][11] = {""};
int answer = 0;

void counting(int ar[26], char *word)
{
    for(int i = 0; i < strlen(word); i++)
    {
        ar[word[i] - 'A']++;
    }
}

int solution(int n, char words[][11])
{
    int diff, length;
    int freq_firstword[26] = {0}, freq_other[26] = {0};
    
    length = strlen(words[0]);
    counting(freq_firstword, words[0]);
    
    for(int i = 1; i < n; i++)
    {
        diff = 0;
        memset(freq_other, 0x0, 26 * sizeof(int));
        counting(freq_other, words[i]);
        
        for(int j = 0; j < 26; j++)
        {
            diff += abs(freq_other[j] - freq_firstword[j]);
        }
        
        if(diff == 0 || diff == 1 || (diff == 2 && (strlen(words[i]) == length)))
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    
    answer = solution(n, words);
    
    cout << answer;

    return 0;
}
