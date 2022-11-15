#include <iostream>
#include <vector>

using namespace std;
vector<bool> visited(10, false);
vector<int> order(10); //주자 순서
/**
 * [힌트] 입력이 그렇게 크지 않네요! 모든 경우의 수를 다 해보면 될 것 같아요.
 *        3아웃이 되면 아웃 카운트와 출루한 주자들이 모두 리셋되고 새로운 이닝이 시작된다는 규칙을 잘 기억해주세요!
 */

 /* 출루한 주자들의 상태 업데이트 */
int hit(vector<bool> &state, int n) 
{
	int score = 0;
	for (int i = 3; i > 0; i--) 
	{
		if (!state[i]) //i번째 루에 주자 없는 경우
		{
			continue;
		}
		state[i] = false; //주자 위치 이동
		if (i + n >= 4) //홈으로 들어오는 경우
		{
			score++; //점수 획득
		}
		else 
		{
			state[i + n] = true; //i + n루로 주자 위치 이동
		}
	}
	//현재 타자의 위치 설정하기
	if (n == 4) //타자가 홈런을 날렸을 경우
	{	
		return score + 1; //점수 + 1
	}
	//안타를 쳤을 경우
	state[n] = true; //n루로 주자 위치 이동
	return score; //점수 리턴
}
/* 타순이 결정됐을 때 경기에서 얻는 점수 구하기 */
int getScore(vector<vector<int>> &inning, int n) 
{
	int out = 0, score = 0, cur = 0;
	vector<bool> state(4, false); //출루한 주자 저장
	int i = 1;
	while (true)
	{
		if (out == 3) //3아웃
		{	
			cur++; //다음 이닝
			out = 0;
			state = vector<bool>(4, false); //출루한 주자 리셋
			continue;
		}
		if (cur == n) //이닝 종료
		{	
			break;
		}

		int player = order[i++]; //타석으로 나갈 주자
		i = i % 9 + 1; //9번 타자까지 공을 쳤는데 3아웃이 발생하지 않은 상태인 경우
		if (inning[cur][player] == 0) //아웃
		{
			out++;
			continue;
		}
		score += hit(state, inning[cur][player]); //점수 계산
	}
	return score;
}
/* 타순 정하기 */
void game(int cnt, int n, vector<vector<int>> &inning, int &maxScore) 
{
	if (cnt == 4) //4번째 타자는 1로 고정
	{
		game(cnt + 1, n, inning, maxScore);
	}
	else if (cnt == 10) //9명의 타자 순서 정해진 경우
	{
		int score = getScore(inning, n); //점수 계산
		if (score > maxScore) //score가 maxScore보다 큰 경우
		{
			maxScore = score; //maxScore에 score값 저장
		}
	}
	else //타자 순서가 정해지지 않은 경우
	{
		for (int i = 2; i <= 9; i++) 
		{
			if (visited[i]) //이미 순서가 지나간 경우
			{
				continue;
			}
			visited[i] = true; //순서 체크
			order[cnt] = i; //순서 배열에 추가
			game(cnt + 1, n, inning, maxScore); //다음 순서 정하기
			visited[i] = false; //다시 원래대로
		}
	}
}
int main() 
{
	int n;
	cin >> n; //이닝 횟수
	int score, maxScore = 0; //점수, 가장 큰 점수 저장
	vector<vector<int>> inning(n, vector<int>(10)); //타자들이 각 이닝에서 얻는 결과
	for (int i = 0; i < n; i++) 
	{
		for (int j = 1; j <= 9; j++) 
		{
			cin >> inning[i][j];
		}
	}
	order[4] = 1; //1번 선수는 4번 타자로 고정
	visited[1] = true;

	game(1, n, inning, maxScore);
	cout << maxScore;
	return 0;
}
