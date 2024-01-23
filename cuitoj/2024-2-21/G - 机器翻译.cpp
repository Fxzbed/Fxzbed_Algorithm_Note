#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int m, n, t, ans = 0;

int main() {
	cin >> m >> n;
	vector<int> v; 
	for (int i = 0; i < n; i ++) {
        cin >> t;
		if (find(v.begin(), v.end(), t) == v.end()) { 
			v.push_back(t); 
			++ans;
		}
		if (v.size() > m) 
			v.erase(v.begin()); 
	}
	cout << ans << endl;
}