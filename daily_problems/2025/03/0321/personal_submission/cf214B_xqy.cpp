#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {
	
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0 ; i < n ; ++i) {
		cin >> a[i];
	}
	sort(a.begin() , a.end() , greater<int>());

	if (a[n - 1] != 0) {
		cout << "-1\n";
		return;
	}

	vector<int> S;
	vector<vector<int>> f(3);
	for (int i = 0 ; i < n ; ++i) {
		if (a[i] % 3 == 0) S.push_back(a[i]);
		else f[a[i] % 3].push_back(a[i]);
	}

	auto get = [&] (int i,int del) {
		int m = f[i].size();
		for (int j = 0 ; j < m - del ; ++j) S.push_back(f[i][j]);
	};
	
	int len1 = f[1].size() , len2 = f[2].size();
	if (len1 % 3 == 0) {
		if (len2 % 3 != 2) {
			get(1 , 0) , get(2 , len2 % 3);
		} else {
			if (len1 != 0) get(1 , 1) , get(2 , 0);
			else get(2 , 2);
		}
	} else if (len1 % 3 == 1) {
		if (len2 % 3 == 0) {
			get(2 , 0) , get(1 , 1);
		} else if (len2 % 3 == 1) {
			get(1 , 0) , get(2 , 0);
		} else { //
			get(1 , 0) , get(2 , 1);
		}
	} else if (len1 % 3 == 2) {
		if (len2 % 3 == 2) get(1 , 0) , get(2 , 0);
		else if (len2 % 3 == 1) get(1 , 1) , get(2 , 0);
		else {
			if (len2 != 0) get(1 , 0) , get(2 , 1);
			else get(1 , 2);
		} 
	}

	sort(S.begin() ,S.end() , greater<int>());
	if (S[0] == 0) {
		cout << "0\n";
		return;
	}
	string ans = "";
	for (auto x : S) {
		ans += char('0' + x);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
