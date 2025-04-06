#include <bits/stdc++.h>
using namespace std;

int N, M;
bool btnErr[10];

bool IsNumPossible(int n) {
	if (n < 10) return !btnErr[n];
	while (n) {
		if (btnErr[n % 10]) return false;
		n /= 10;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	bool errDone = false;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) { 
		int input;
		cin >> input;
		btnErr[input] = true;
	}
	
	if (M == 10 || (M == 9 && btnErr[0] == false)) {
		cout << abs(N - 100);
		return 0;
	}

	int up = N, down = N;
	
	while (!IsNumPossible(up)) up++;
	while (!IsNumPossible(down)) down--;

	int a1 = abs(up - N);
	int tmp = up;
	if (up == 0) a1++;
	while (tmp)	tmp /= 10, a1++; 

	if (down < 0) down = 100;
	int a2 = abs(N - down);
	tmp = down;
	if (down == 0) a2++;
	while (tmp)	tmp /= 10, a2++;

	cout << min(min(a1, a2), abs(N - 100));
}