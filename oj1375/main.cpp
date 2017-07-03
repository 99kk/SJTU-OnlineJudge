#include <iostream>
#include<stdio.h>
#include<cstring>

//ac
using namespace std;
struct edge
{
    int x, y, next;
};
bool v[80002];
edge e[80002],g[80002];
int answers[80002],lse[80002],lsg[80002],f[80002];
int maxG,maxE;
int find(int x)
{
    if (f[x]==-1)
        return x;
    f[x]=find(f[x]);
    return f[x];
}
void dfs(int x)
{
    v[x]=true;
    for (int i=lsg[x];i;i=g[i].next)
        if (v[g[i].y])
            answers[i]=find(g[i].y);
    for (int i=lse[x];i;i=e[i].next)
        {
            dfs(e[i].y);
            f[find(e[i].y)]=x;
        }
}
int main()
{
    memset(f,-1,sizeof(f));
    int n,m,root;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (y==-1)
            root=x;
        else
        {
            e[++maxE]=(edge){y,x,lse[y]};
            lse[y]=maxE;
        }
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[++maxG]=(edge){x,y,lsg[x]};
        lsg[x]=maxG;
        g[++maxG]=(edge){y,x,lsg[y]};
        lsg[y]=maxG;
    }
    dfs(root);
    for (int i=1;i<=m;i++)
    {
        edge now=g[i*2-1];
        if (answers[i*2-1]==now.x||answers[i*2]==now.x)
            printf("1\n");
        else
            if (answers[i*2-1]==now.y||answers[i*2]==now.y)
                printf("2\n");
                else
                    printf("0\n");
    }
    return 0;
}



/*
int father[40001];

bool isFather(int x, int y)
{
	int i = y;
	while(i != -1)
	{
		i = father[i];
		if(i == x) return true;

	}
	return false;
}


int maintest()
{

	int n, m, a, b, x,y, i,j;


	int *tem1, *tem2, rootID;
	cin>>n;
	tem1 = new int[n]; tem2 = new int[n];
	for( i = 0; i <= 40000; i++) father[i] = 0;
	for(i = 0; i <n; i++)
	{
		scanf("%d%d", &a, &b);

		tem1[i] = a;
		tem2[i] = b;
		if(b == -1) rootID = i;

	}
	father[tem1[rootID]] = -1;
	for(i = 0; i < n; i++)
	{
		if(i == rootID) continue;

		if(father[tem1[i]] == 0)
			father[tem1[i]] = tem2[i];
		else
			father[tem2[i]] = tem1[i];

		if(isFather(-1,tem2[i]))
			continue;
		else
			father[tem2[i]] = tem1[i];




	}






	cin>>m;
	for(i = 0; i <m; i++)
	{
		scanf("%d%d",&x, &y);
		if(isFather(x,y)) cout<<1<<endl;
		else if(isFather(y,x)) cout<<2<<endl;
		else cout<<0<<endl;



	}

    return 0;
}

/*
#include <iostream>
#include <stdio.h>

using namespace std;




*/
