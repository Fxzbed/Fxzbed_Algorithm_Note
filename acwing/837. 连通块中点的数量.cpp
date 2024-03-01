#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int num[N], cnt[N];

int find(int x) {
    if (num[x] != x) num[x] = find(num[x]);
    return num[x];
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) {
        num[i] = i;
        cnt[i] = 1;
    }
    
    while (m --) {
        char ss[5];
        int o1, o2;
        scanf("%s", ss);
        
        if (ss[0] == 'C') {
            scanf("%d%d", &o1, &o2);
            if (find(o1) == find(o2)) continue; //出现自己合并自己！（为了防止cnt数据出错 直接continue!）
            cnt[find(o2)] += cnt[find(o1)];
            num[find(o1)] = find(o2);
        } else {
            if (ss[1] == '1') {
                scanf("%d%d", &o1, &o2);
                if (find(o1) == find(o2)) puts("Yes"); 
                else puts("No");
            }
            else {
                scanf("%d", &o1);
                printf("%d\n", cnt[find(o1)]); 
            }
        }
        
    }
    
    return 0;
}