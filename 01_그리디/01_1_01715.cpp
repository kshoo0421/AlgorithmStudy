#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, tmp, sum = 0;
	multiset<int> card;
	cin >> n;
	while(n--){
		cin >> tmp;
		card.insert(tmp);
	}

	while (card.size() > 1) {
		tmp = *(card.begin());
		card.erase(card.begin());
		tmp += *(card.begin());
		card.erase(card.begin());
		sum += tmp;
		card.insert(tmp);
	}
	cout << sum;
}