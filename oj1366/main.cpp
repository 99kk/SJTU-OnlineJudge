#include <iostream>
#include <cstring>

using namespace std;

//AC

struct wordNode
{
	char word[100];
	int id_ori;
	int len;
};

void exchange(wordNode &w1, wordNode&w2)
{
	char tem[100]; int temID = w1.id_ori, temLen = w1.len;
	strcpy(tem, w1.word);
	strcpy(w1.word, w2.word);
	w1.id_ori = w2.id_ori;
	w1.len = w2.len;
	strcpy(w2.word, tem);
	w2.id_ori = temID;
	w2.len = temLen;
}

int slice(wordNode *a, int low, int high)
{
	char key[100];
	strcpy(key, a[low].word);
	int i = low, j = low+1;
	for(j = low+1; j <= high; j++)
	{
		if(strcmp(key, a[j].word)>0)
		{
			i++;
			exchange(a[i], a[j]);
		}
	}
	exchange(a[i], a[low]);
	return i;
}

void quickSort(wordNode* a, int low, int high)
{
	//
	if(low< high)
	{
		int w = slice(a, low, high);
		quickSort(a, low, w-1);
		quickSort(a, w+1, high);
	}
}



int searchDic(wordNode *a,const char*p, int low, int high)
{
	if(low == high) return low;

	int mid = (low + high) / 2;

	if( strcmp(a[mid].word, p) >=0 )
		return searchDic(a, p, low, mid);
	else
		return searchDic(a,p,mid+1, high);
}

int main()
{
    int n, m, i, j,k;
    cin>>n>>m;

    char p[1001], pp[1001];
    wordNode *a = new wordNode[n+1];
    cin.get();
    for(i = 1; i <= n; i++)
	{
		cin.getline(a[i].word, 99);
		a[i].len = strlen(a[i].word);
		a[i].id_ori = i;
	}

	quickSort(a, 1, n);


	for(i = 1; i <= m; i++)
	{
		cin>>k>>p;

		int start = searchDic(a,p,1,n);
		int s;
		bool exsit = true;
		strcpy(pp, p);
		for(j = 0; pp[j]!='\0'; j++);
		pp[j-1]++;
		int ending = searchDic(a,pp,1,n)-1;

		if(start+k-1>ending){cout<<-1<<endl;}
		else  cout<<a[start+k-1].id_ori<<endl;
		/*
		for(s = start; s < start+k; s++)
		{

			if(strcmp(a[s].word,p)>=0){continue;}
			else {exsit = false; break;}
		}

*/



	}



    return 0;
}
