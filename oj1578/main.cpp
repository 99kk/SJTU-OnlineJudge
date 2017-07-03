#include <iostream>

using namespace std;

//ac

void north(char **a, int x, int y, int n, int m, int *cat, int *dog, int *mou)
{
	int x1 = x-1, x2 = x-1, y1 = y-1, y2 = y+1;
	switch(a[x][y])
	{
		case 'C':cat[0]++;break;
		case 'D':dog[0]++;break;
		case 'M':mou[0]++;break;
	}
	while(x1>=0 and y1 >=0)
	{
		switch(a[x1][y1])
		{
			case 'C':cat[0]++;break;
			case 'D':dog[0]++;break;
			case 'M':mou[0]++;break;
		}
		x1 -= 1; y1-= 1;
	}

	while(x2 >= 0 and y2 <m)
	{
		switch(a[x2][y2])
		{
			case 'C':cat[0]++;break;
			case 'D':dog[0]++;break;
			case 'M':mou[0]++;break;
		}
		x2 -= 1; y2 += 1;
	}

	if(x-1 >= 0)
		north(a,x-1,y,n,m,cat,dog,mou);

}

void south(char **a, int x, int y, int n, int m, int *cat, int*dog, int *mou)
{
	int x1 = x+1, x2 = x+1, y1 = y-1, y2 = y+1;
	switch(a[x][y])
	{
		case 'C':cat[1]++;break;
		case 'D':dog[1]++;break;
		case 'M':mou[1]++;break;
	}

	while(x1 <n and y1 >=0)
	{
		switch(a[x1][y1])
		{
			case 'C':cat[1]++;break;
			case 'D':dog[1]++;break;
			case 'M':mou[1]++;break;
		}
		x1 += 1; y1-= 1;
	}

	while(x2 < n and y2 <m)
	{
		switch(a[x2][y2])
		{
			case 'C':cat[1]++;break;
			case 'D':dog[1]++;break;
			case 'M':mou[1]++;break;
		}
		x2 += 1; y2 += 1;
	}

	if(x+1 < n)
		south(a,x+1,y,n,m,cat,dog,mou);

}

void west(char **a, int x, int y, int n, int m, int *cat, int*dog, int *mou)
{
	int x1 = x+1, x2 = x-1, y1 = y-1, y2 = y-1;
	switch(a[x][y])
	{
		case 'C':cat[2]++;break;
		case 'D':dog[2]++;break;
		case 'M':mou[2]++;break;
	}
	while(x1 >= 0 and x1 <n and y1 >=0 and y1 < m)
	{
		switch(a[x1][y1])
		{
			case 'C':cat[2]++;break;
			case 'D':dog[2]++;break;
			case 'M':mou[2]++;break;
		}
		x1 += 1; y1-= 1;
	}

	while(x2 >= 0 and x2 < n and y2 <m and y2 >= 0)
	{
		switch(a[x2][y2])
		{
			case 'C':cat[2]++;break;
			case 'D':dog[2]++;break;
			case 'M':mou[2]++;break;
		}
		x2 -= 1; y2 -= 1;
	}

	if(y-1 >= 0)
		west(a,x,y-1,n,m,cat,dog,mou);

}


void east(char **a, int x, int y, int n, int m, int *cat, int*dog, int *mou)
{
	int x1 = x+1, x2 = x-1, y1 = y+1, y2 = y+1;
	switch(a[x][y])
	{
		case 'C':cat[3]++;break;
		case 'D':dog[3]++;break;
		case 'M':mou[3]++;break;
	}
	while(x1 >= 0 and x1 <n and y1 >=0 and y1 < m)
	{
		switch(a[x1][y1])
		{
			case 'C':cat[3]++;break;
			case 'D':dog[3]++;break;
			case 'M':mou[3]++;break;
		}
		x1 += 1; y1+= 1;
	}

	while(x2 >= 0 and x2 < n and y2 <m and y2 >= 0)
	{
		switch(a[x2][y2])
		{
			case 'C':cat[3]++;break;
			case 'D':dog[3]++;break;
			case 'M':mou[3]++;break;
		}
		x2 -= 1; y2 += 1;
	}

	if(y+1 < m)
		east(a,x,y+1,n,m,cat,dog,mou);

}




int main()
{
	int n, m, i, j,k, step, x, y, cat[4], dog[4], mou[4];
	char **a, input[1001], op;
	cin>>n>>m;
	a = new char*[n];
	cin.get();

	for(i = 0; i < n; i++)
	{
		a[i] = new char[m+1];
	}

	/*
	for(i = 0; i <= m+1; i++)
	{
		dogs[0][i] = 0; cats[0][i] = 0; mice[0][i] = 0;
	}
	for(i= 0; i <=n+1; i++)
	{
		dogs[i][0]= 0; cats[i][0] = 0; mice[i][0] = 0;
	}
	*/


	for(i = 0; i < n; i++)
	{
		cin.getline(input, 1001);
		for(j = 0; input[j] != '\0'; j++)
		{
			a[i][j] = input[j];
			if(input[j] == 'H')
			{
				x = i; y = j;
			}

		}
	}

	for(i = 0; i <4; i++)
	{
		cat[i] = dog[i] = mou[i] = 0;
	}

	north(a,x,y,n,m,cat,dog,mou);
	south(a,x,y,n,m,cat,dog,mou);
	west (a,x,y,n,m,cat,dog,mou);
	east (a,x,y,n,m,cat,dog,mou);



	cin>>step;

	int x1, x2 , y1, y2;
	int nw[3], ne[3], sw[3], se[3], ceter[3], newcenter[3] , nwNew[3],neNew[3], swNew[3], seNew[3];

	for(i = 0; i < step; i++)
	{


		cin>>op;
		if( (op == 'N' and x-1 < 0) or (op == 'S' and x+1 >= n) or (op == 'W' and y-1 < 0 ) or (op == 'E' and y+1 >= m) ) continue;

		for(j = 0; j < 3; j++) {nw[j] =0; ne[j] = 0;sw[j] = 0;se[j] = 0;ceter[j] = 0; newcenter[j] = 0; nwNew[j] = 0;neNew[j]=0; swNew[j]=0; seNew[j]=0;  }

		switch(a[x][y])
			{
				case 'C':ceter[0]++;break;
				case 'D':ceter[1]++;break;
				case 'M':ceter[2]++;break;
			}

		x1 = x-1;  y1 = y-1;
		while(x1>=0 and y1 >=0)
		{
			switch(a[x1][y1])
			{
				case 'C':nw[0]++;break;
				case 'D':nw[1]++;break;
				case 'M':nw[2]++;break;
			}
			x1 -= 1; y1 -= 1;
		}

		x2 = x-1; y2 = y+1;
		while(x2 >= 0 and y2 <m)
		{
			switch(a[x2][y2])
			{
				case 'C':ne[0]++;break;
				case 'D':ne[1]++;break;
				case 'M':ne[2]++;break;
			}
			x2 -= 1; y2 += 1;
		}

		x1 = x+1; y1 = y-1;
		while(x1 <n and y1 >=0)
		{
			switch(a[x1][y1])
			{
				case 'C':sw[0]++;break;
				case 'D':sw[1]++;break;
				case 'M':sw[2]++;break;
			}
			x1 += 1; y1-= 1;
		}

		 x2 = x+1; y2 = y+1;
		while(x2 < n and y2 <m)
		{
			switch(a[x2][y2])
			{
				case 'C':se[0]++;break;
				case 'D':se[1]++;break;
				case 'M':se[2]++;break;
			}
			x2 += 1; y2 += 1;
		}

			switch(op)
			{
				case 'N': x -= 1;break;
				case 'S': x += 1; break;
				case 'W': y -= 1; break;
				case 'E': y += 1; break;
			}



					switch(a[x][y])
				{
					case 'C':newcenter[0]++;break;
					case 'D':newcenter[1]++;break;
					case 'M':newcenter[2]++;break;
				}

				x1 = x-1;  y1 = y-1;
				while(x1>=0 and y1 >=0)
				{
					switch(a[x1][y1])
					{
						case 'C':nwNew[0]++;break;
						case 'D':nwNew[1]++;break;
						case 'M':nwNew[2]++;break;
					}
					x1 -= 1; y1 -= 1;
				}

				x2 = x-1; y2 = y+1;
				while(x2 >= 0 and y2 <m)
				{
					switch(a[x2][y2])
					{
						case 'C':neNew[0]++;break;
						case 'D':neNew[1]++;break;
						case 'M':neNew[2]++;break;
					}
					x2 -= 1; y2 += 1;
				}

				x1 = x+1; y1 = y-1;
				while(x1 <n and y1 >=0)
				{
					switch(a[x1][y1])
					{
						case 'C':swNew[0]++;break;
						case 'D':swNew[1]++;break;
						case 'M':swNew[2]++;break;
					}
					x1 += 1; y1-= 1;
				}

				 x2 = x+1; y2 = y+1;
				while(x2 < n and y2 <m)
				{
					switch(a[x2][y2])
					{
						case 'C':seNew[0]++;break;
						case 'D':seNew[1]++;break;
						case 'M':seNew[2]++;break;
					}
					x2 += 1; y2 += 1;
				}



		switch(op)
		{
		case 'N':
			{
				cat[0] = cat[0] - ne[0] - nw[0] - ceter[0] ;
				dog[0] = dog[0] - ne[1] - nw[1] - ceter[1] ;
				mou[0] = mou[0] - ne[2] - nw[2] - ceter[2] ;

				cat[1] = cat[1] + seNew[0] + swNew[0] + newcenter[0];
				dog[1] = dog[1] + seNew[1] + swNew[1] + newcenter[1];
				mou[1] = mou[1] + seNew[2] + swNew[2] + newcenter[2];

				cat[2] = cat[2] - sw[0] + nwNew[0] - ceter[0] + newcenter[0];
				dog[2] = dog[2] - sw[1] + nwNew[1] - ceter[1] + newcenter[1];
				mou[2] = mou[2] - sw[2] + nwNew[2] - ceter[2] + newcenter[2];

				cat[3] = cat[3] + neNew[0] - se[0] - ceter[0] + newcenter[0];
				dog[3] = dog[3] + neNew[1] - se[1] - ceter[1] + newcenter[1];
				mou[3] = mou[3] + neNew[2] - se[2] - ceter[2] + newcenter[2];

				cout<<cat[0]<<" "<<dog[0]<< " "<<mou[0]<<endl;
				break;

			}
		case 'S':
			{
				cat[0] = cat[0] + neNew[0] + nwNew[0] + newcenter[0];
				dog[0] = dog[0] + neNew[1] + nwNew[1] + newcenter[1];
				mou[0] = mou[0] + neNew[2] + nwNew[2] + newcenter[2];

				cat[1] = cat[1] - se[0] - sw[0] - ceter[0];
				dog[1] = dog[1] - se[1] - sw[1] - ceter[1];
				mou[1] = mou[1] - se[2] - sw[2] - ceter[2];

				cat[2] = cat[2] + swNew[0] - nw[0] - ceter[0]+ newcenter[0];
				dog[2] = dog[2] + swNew[1] - nw[1] - ceter[1]+ newcenter[1];
				mou[2] = mou[2] + swNew[2] - nw[2] - ceter[2]+ newcenter[2];

				cat[3] = cat[3] - ne[0] + seNew[0] - ceter[0]+ newcenter[0];
				dog[3] = dog[3] - ne[1] + seNew[1] - ceter[1]+ newcenter[1];
				mou[3] = mou[3] - ne[2] + seNew[2] - ceter[2]+ newcenter[2];

				cout<<cat[1]<<" "<<dog[1]<< " "<<mou[1]<<endl;
				break;
			}
		case 'W':
			{

				cat[0] = cat[0] - ne[0] + nwNew[0] - ceter[0]+ newcenter[0];
				dog[0] = dog[0] - ne[1] + nwNew[1] - ceter[1]+ newcenter[1];
				mou[0] = mou[0] - ne[2] + nwNew[2] - ceter[2]+ newcenter[2];

				cat[1] = cat[1] - se[0] + swNew[0] - ceter[0]+ newcenter[0];
				dog[1] = dog[1] - se[1] + swNew[1] - ceter[1]+ newcenter[1];
				mou[1] = mou[1] - se[2] + swNew[2] - ceter[2]+ newcenter[2];

				cat[2] = cat[2] - sw[0] - nw[0] - ceter[0];
				dog[2] = dog[2] - sw[1] - nw[1] - ceter[1];
				mou[2] = mou[2] - sw[2] - nw[2] - ceter[2];

				cat[3] = cat[3] + neNew[0] + seNew[0] + newcenter[0];
				dog[3] = dog[3] + neNew[1] + seNew[1] + newcenter[1];
				mou[3] = mou[3] + neNew[2] + seNew[2] + newcenter[2];

				cout<<cat[2]<<" "<<dog[2]<< " "<<mou[2]<<endl;
				break;
			}
		case 'E':
			{
				cat[0] = cat[0] + neNew[0] - nw[0] - ceter[0]+ newcenter[0];
				dog[0] = dog[0] + neNew[1] - nw[1] - ceter[1]+ newcenter[1];
				mou[0] = mou[0] + neNew[2] - nw[2] - ceter[2]+ newcenter[2];

				cat[1] = cat[1] + seNew[0] - sw[0] - ceter[0]+ newcenter[0];
				dog[1] = dog[1] + seNew[1] - sw[1] - ceter[1]+ newcenter[1];
				mou[1] = mou[1] + seNew[2] - sw[2] - ceter[2]+ newcenter[2];

				cat[2] = cat[2] + swNew[0] + nwNew[0] + newcenter[0];
				dog[2] = dog[2] + swNew[1] + nwNew[1] + newcenter[1];
				mou[2] = mou[2] + swNew[2] + nwNew[2] + newcenter[2];

				cat[3] = cat[3] - ne[0] - se[0] - ceter[0];
				dog[3] = dog[3] - ne[1] - se[1] - ceter[1];
				mou[3] = mou[3] - ne[2] - se[2] - ceter[2];
				cout<<cat[3]<<" "<<dog[3]<< " "<<mou[3]<<endl;
				break;
			}
		}




	}



    return 0;
}
