#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000;

int n, m;
vector<vector<int>> board;
int ans;

/**
 * 1. 보라색 블럭을 제외하고는 모두 한붓 그리기로 그릴 수 있음
 *    -> 일반적인 백트래킹으로 모양을 만들 수 있음
 * 2. 보라색 블럭은 3개의 블럭이 결정된 이후에, 가운데에서 탐색을 해야 만들 수 있음
 *    -> 3번째 블럭을 결정하면서 현재 좌표를 갱신하지 않고, 직전 좌표에서 다시 한번 백트래킹을 진행하여 얻을 수 있음
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 방문처리 -> board를 활용해서 0을 저장하는 것으로
 * 가지치기 -> 현재 탐색이 남은 칸을 모두 MAX라 해도 ans이 더 큰 경우
 */

void backtracking(int x, int y, int cnt, int sum) 
{
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	if (cnt == 4) //기저조건: 4개의 블럭을 탐색함
	{
		ans = max(ans, sum); //ans와 sum중 더 큰 값을 ans에 저장
		return;
	}

	if (ans >= MAX * (4 - cnt) + sum) //가지치기
	{
		return;
	}
	
	for (int i = 0; i < 4; i++) //ㅜ 모양의 경우
	{
		int nx = x + dx[i]; //4가지 방향으로의 위치 확인
		int ny = y + dy[i]; ////4가지 방향으로의 위치 확인

		// 범위를 벗어나거나, 이미 방문했다면
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || !board[nx][ny]) 
		{
			continue;
		}
		if (cnt == 2)
		{
			int temp = board[nx][ny]; //temp에 board[nx][ny]값 저장
			board[nx][ny] = 0; //board[nx][ny]값 초기화
			backtracking(x, y, cnt + 1, sum + temp); //계산
			board[nx][ny] = temp; //원상태 복구
		}
		int temp = board[nx][ny]; //temp에 board[nx][ny]값 저장
		board[nx][ny] = 0; //board[nx][ny]값 초기화
		backtracking(nx, ny, cnt + 1, sum + temp); //계산
		board[nx][ny] = temp; //원상태 복구
	}
}

int main() {

	//입력
	cin >> n >> m;

	board.assign(n, vector<int>(m, 0)); //NxM 크기의 종이
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> board[i][j]; //종이 칸의 정수 저장
		}
	}

	//연산
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			int temp = board[i][j]; //temp에 board[i][j]값 저장
			board[i][j] = 0; //board[i][j]값 초기화
			backtracking(i, j, 1, temp); //모양처리
			board[i][j] = temp; //원상태 복구
		}
	}

	//출력
	cout << ans;

	return 0;
}
