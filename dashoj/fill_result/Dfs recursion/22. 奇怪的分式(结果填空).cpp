#include <iostream>
using namespace std;
 
int main()
{
	int ans = 0;
	for(int a = 1; a <= 9; a ++)
	for(int b = 1; b <= 9; b ++)
	for(int c = 1; c <= 9; c ++)
	for(int d = 1; d <= 9; d ++)
	{
		if(a == b || c == d) continue;
		if(a * c * (b * 10 + d) == b * d * (a * 10 + c)) ans ++;
	}
			
	cout << ans << endl;
	return 0;
}
