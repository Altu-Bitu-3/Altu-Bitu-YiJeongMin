#include <iostream>
#include <vector> //벡터 사용

using namespace std;

const int MAX = 1e6; //최대 정수 범위

//에리토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime()
{
    vector<bool> is_prime(MAX + 1, true); //MAX까지의 모든 정수에 대해 true 값을 초기값으로 설정한다
    
    is_prime[0] = is_prime[1] = false; //0과 1은 소수가 아니므로 값을 false로 설정한다.
    
    for(int i = 2; i * i < MAX; i++) //2에서 999까지
    {
        if(!is_prime[i]) //is_prime의 값이 false이면(소수가 아니면)
        {
            continue; //다음 단계로 이어간다.
        }
        
        for(int j = i * i; j <= MAX; j += i) //MAX까지의 i의 배수에 대해
        {
            is_prime[j] = false; //is_prime 값을 false로 설정한다.
        }
    }
    
    return is_prime; //is_prime을 반환한다.
}

int goldbach(int n, vector<bool> &is_prime)
{
    for(int i = 3; i <= n / 2; i += 2) //홀수만 검사, n / 2 이상의 값은 어차피 n - i를 통해 검사되므로 n / 2까지 검사
    {
        if(is_prime[i] && is_prime[n - i]) //하나의 소수가 정해지면(i) 나머지 하나의 소수는 n - i로 자동 결정 -> 둘 다 소수라면
        {
            return i; //두 홀수 소수 중 더 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우 false 리턴
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    int n;
    
    vector<bool> is_prime = isPrime();
    
    while(true)
    {
        //입력
        cin >> n;
        if(n == 0) //입력이 0이면
        {
            break; //탈출
        }
        
        int prime = goldbach(n, is_prime); //골드바흐 추측의 결과값 prime
        if(prime) //prime 값이 0이 아니면 출력
        {
            cout << n << " = " << prime << " + " << n - prime << '\n';
        }
        else //prime 값이 0이면 출력
        {
            cout << "Goldback's conjecture is wrong.\n";
        }
    }
}
