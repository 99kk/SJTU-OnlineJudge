#include <iostream>

using namespace std;

//AC

void solveTree(char *seqTree, char pre[], char mid[], int startPre, int startMid, int len, int pos, int &maxPos)
{
	if(len <= 0) return;
	char cur = pre[startPre];
	seqTree[pos] = cur;
	if(maxPos < pos) maxPos = pos;

	int leftlen = 0, rightLen;
	while(mid[startMid + leftlen] != cur) leftlen++;
	rightLen = len- leftlen -1;
	solveTree(seqTree, pre, mid,startPre+1, startMid,leftlen, pos * 2, maxPos);
	solveTree(seqTree, pre, mid, startPre+leftlen+1,startMid+leftlen+1, rightLen, pos * 2+1, maxPos);
}

int main()
{
    char pre[30], mid[30], seqTree[1001];
    cin.getline(pre, 30);
    cin.getline(mid, 30);
    int len, maxPos = 1;
    for(len = 0; pre[len] != '\0'; len++);

	for(int i = 1; i <= 1000; i++) seqTree[i] = '0';
    solveTree(seqTree, pre, mid,0,0,len,1, maxPos);

    for(int i = 1; i <= maxPos; i++)
	{
		if(seqTree[i] != '0') cout<<seqTree[i]<<" ";
		else cout<<"NULL ";
	}






    return 0;
}
