#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, sum = 0;
	cin >> N;

	multiset<int> card; 
	
	while(N--){
		int input;
		cin >> input;
		card.insert(input);
	}

	while (card.size() > 1) {
		int cur = *(card.begin());
		card.erase(card.begin());
		cur += *(card.begin());
		card.erase(card.begin());
		sum += cur;
		card.insert(cur);
	}
	cout << sum;
}