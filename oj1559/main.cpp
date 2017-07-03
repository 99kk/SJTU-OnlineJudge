#include <iostream>
#include <vector>

//AC

using namespace std;

struct node
{
	int x,y;
	node(int x1, int y1){x = x1; y = y1;}
	node(const node &n){x = n.x; y = n.y; }
	node(){}
};

void getMinArea(int &curhNum, int &MinArea, vector<node> &hNodes, vector<node> &gNodes)
{
	int h = hNodes.size(), g = gNodes.size();

	if(h < curhNum or h == 0) return;

	if(g > 0)
	{
		node key = gNodes[0], temG, temH;
		vector<node> leftHnode, leftGnode, rightHnode, rightGnode, upH, upG, downH, downG;
		for(int i = 0; i < gNodes.size(); i++)
		{
			temG = gNodes[i];
			if(temG.x < key.x ) leftGnode.push_back(temG);
			if(temG.x > key.x ) rightGnode.push_back(temG);
			if(temG.y < key.y ) downG.push_back(temG);
			if(temG.y > key.y ) upG.push_back(temG);


		}
		for(int i = 0; i < hNodes.size(); i++)
		{
			temH = hNodes[i];
			if(temH.x < key.x) leftHnode.push_back(temH);
			if(temH.x > key.x) rightHnode.push_back(temH);
			if(temH.y < key.y) downH.push_back(temH);
			if(temH.y > key.y) upH.push_back(temH);
		}

		getMinArea(curhNum, MinArea, leftHnode, leftGnode);
		getMinArea(curhNum, MinArea, rightHnode, rightGnode);
		getMinArea(curhNum, MinArea, upH, upG);
		getMinArea(curhNum, MinArea, downH, downG);

	}
	else
	{
		int lx = hNodes[0].x, ly = hNodes[0].y, rx = hNodes[0].x, ry = hNodes[0].y;
		for(int i = 0; i < hNodes.size(); i++)
		{
			if(lx > hNodes[i].x) lx = hNodes[i].x;
			if(ly > hNodes[i].y) ly = hNodes[i].y;
			if(rx < hNodes[i].x) rx = hNodes[i].x;
			if(ry < hNodes[i].y) ry = hNodes[i].y;
		}

		int curArea = (rx - lx ) * (ry - ly);
		if(h > curhNum)
		{
			curhNum = h; MinArea = curArea;
		}
		if(h == curhNum and MinArea > curArea) MinArea = curArea;
	}

}

int main()
{
	int n,i, x,y, curhNum = 0, minArea = 1001 * 1001;
	char c;
	cin>>n;

	vector<node> hNodes, gNodes;

	node tem;

	for(i = 0; i < n; i++)
	{
		cin>>x>>y>>c;
		tem.x = x; tem.y = y;
		if(c == 'H')
		{

			hNodes.push_back(tem);
		}
		if(c == 'G')
		{
			gNodes.push_back(tem);
		}
	}

	getMinArea(curhNum, minArea, hNodes, gNodes);


	cout<<curhNum<<" "<<minArea;


    return 0;
}
