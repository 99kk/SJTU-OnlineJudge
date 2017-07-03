#include <iostream>
#include <stdio.h>

using namespace std;

//ac

int n, *pre, *mid, *post;

void changeToPost(int preStart, int midStart, int len)
{
	if(len <= 0) return;
	if(len == 1)
	{
		printf("%d ", pre[preStart]);
		return;
	}

	int leftLen = 0;
	int curRoot = pre[preStart];

	while(curRoot != mid[midStart + leftLen]) leftLen++;

	changeToPost(preStart+1, midStart, leftLen);
	changeToPost(preStart +leftLen + 1, midStart + leftLen +1, len- leftLen-1);
	printf("%d ",curRoot);

}


int main()
{
    int i;
	cin>>n;
	pre = new int[n]; mid = new int[n]; post = new int[n];

	for(i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &mid[i]);


	changeToPost(0,0, n);




    return 0;
}
