#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int n;
int weight[31];
int weightField[31][31];
int index[31][31];
void print(int l,int r){
     if (l>r) return;
     int k=index[l][r];
     printf("%d ",k);
     print(l,k-1);
     print(k+1,r);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",&weight[i]);
        weightField[i][i]=weight[i];
        index[i][i]=i;
    }

    for (int i=n;i>0;i--)
		for (int j=i+1;j<=n;j++)
			for (int k=i;k<=j;k++)
			{
				int x=weightField[i][k-1],y=weightField[k+1][j];
				if (x==0) x=1;
				if (y==0) y=1;
				if (weightField[i][j]<(x*y+weight[k]))
				{
					weightField[i][j]=x*y+weight[k];
					index[i][j]=k;
				}
			}
    printf("%d\n",weightField[1][n]);
    print(1,n);

    return 0;
}
