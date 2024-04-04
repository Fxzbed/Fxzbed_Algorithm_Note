#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 4
int b[10]={0,1,2,3,4,5,6,7,8,9};
int a[N][N];
int cnt;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool check(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<0||ty<0||tx==0&&ty==0||tx==2&&ty==3||tx>2||ty>3)continue;
		if(abs(a[tx][ty]-a[x][y])==1)return false;
	}
	return true;
}
int main()
{
  do{
  	
  	for(int i=1;i<=3;i++)a[0][i]=b[i-1];
  	for(int i=0;i<=3;i++)a[1][i]=b[i+3];
  	for(int i=0;i<=2;i++)a[2][i]=b[i+7];
 	bool flag=false;
 	for(int i=0;i<=2;i++)
 	{
 	for(int j=0;j<=3;j++)
 	   {
 	   	 if(i==0&&j==0)	continue;
 	   	 if(i==2&&j==3)	continue;
 	   	 if(!check(i,j))
 	   	 {
 	   	 	flag=true;
 	   	 	break;
		 }
	   }
	   if(flag)break;	
	 }
 	  if(!flag)cnt++;
  	 
  }while(next_permutation(b,b+10));
  cout<<cnt<<endl;
  return 0;
}
