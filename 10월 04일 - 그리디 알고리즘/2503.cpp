#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool ans[1000];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int N;
    cin >> N;
    
    //모두 true로 초기화
    for(int i = 0; i < 1000; i++)
    {
        ans[i] = true;
    }
    
    //100 이하의 값들은 false
    for(int i = 0; i < 100; i++)
    {
        ans[i] = false;
    }
    
    for(int i = 100; i < 1000; i++)
    {
        string temp = to_string(i);
        
        //중복된 숫자가 있다면
        if(temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
        {
            ans[i] = false;
            continue;
        }
        
        //0이 있다면
        if(i % 10 == 0 || (i / 10) % 10 == 0)
        {
            ans[i] = false;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        int num;
        int st, b;
        cin >> num >> st >> b;
        string temp2 = to_string(num);
        
        for(int j = 100; j < 1000; j++)
        {
            if(ans[j])
            {
                string temp3 = to_string(j);
                int st2 = 0; //비교할 스트라이크 수
                int b2 = 0; //비교할 볼 수수
                
                for(int k = 0; k < 3; k++)
                {
                    for(int l = 0; l < 3; l++)
                    {
                        //자리와 값이 모두 같을 때(스트라이크)
                        if(k == l && temp2[k] == temp3[l])
                        {
                            st2++;
                            continue;
                        }
                        //자리는 다르고 값이 같을 때(볼)
                        if(k != l && temp2[k] == temp3[l])
                        {
                            b2++;
                        }
                    }
                }
                if(st2 != st || b2 != b)
                {
                    ans[j] = false;
                }
            }
        }
    }
    int answer = 0;
    
    for(int i = 0; i < 1000; i++)
    {
        if(ans[i])
        {
            answer++;
        }
    }
    
    cout << answer;
    return 0;
}
