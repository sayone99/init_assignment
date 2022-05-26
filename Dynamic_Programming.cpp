// 백준 2579번 풀이
// https://www.acmicpc.net/problem/2579

#include <iostream>
using namespace std;


int stair[301];
int dp[301];
int Max(int a, int b);

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> stair[i];
	}

	dp[0] = stair[0];
	dp[1] = Max(stair[0] + stair[1], stair[1]);
	dp[2] = Max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < num; i++) {
		dp[i] = Max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 2]);
	}

	cout << dp[num - 1];

	return 0;
}


int Max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}
