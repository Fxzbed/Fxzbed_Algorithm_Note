#include<iostream>

using namespace std;

int x[5000005], k;

void qsort(int l,int r) {
	int i = l, j = r, mid = x[l + r >> 1];
	while (i <= j) {
		while(x[j] > mid)
			j --;
		while(x[i] < mid)
			i ++;
		if(i <= j) {
			swap(x[i], x[j]);
			i ++;
			j --;
		}
	}
	//l<=j<=i<=r
	if(k <= j) qsort(l, j);
	else if(i <= k) qsort(i, r);
	else {
		printf("%d",x[j + 1]);
		return;
	}
}

int main() {
	int n;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	qsort(0,n-1);
}