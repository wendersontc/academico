#include <iostream>
#include <vector>
#define lli long long int
#define veci vector <int>
#define vecb vector <bool>

using namespace std;

int main()
{
	lli n;
	cout<<endl<<"Coloque o n�mero de n�s no grafo"<<endl;
	cin>>n;
	vector <veci > matrix;
	matrix.clear();
	cout<<endl<<"Calcular dist�ncias de qual n�? (Por exemplo, fonte de = 0, 1 = primeiro n� e assim por diante"<<endl;
	lli src; cin>>src;
	veci dist;
	vecb visit;
	lli nxtNode;
	lli min=999999999;

	dist.clear(); visit.clear();
	for (int i=0; i<n; i++)
	{
		dist.push_back(0);
		visit.push_back(false);
	}


	cout<<endl<<"Agregar a matriz de entrada em um formul�rio tabulado"<<endl;

	for (int y=0; y<n; y++)
	{
		veci row;
		row.clear();
		for (int r=0; r<n; r++)
		{
			lli d;
			cin>>d;
			row.push_back(d);
		}
		matrix.push_back(row);
	}

	dist = matrix.at(src);

	dist.at(src)=0;
	visit.at(src)=true;

	for (int i=0; i<n; i++)
	{
		min=999999999;

		for (int h=0; h<n; h++)
		{
			if (min>=dist.at(h) && !visit.at(h))
			{
				min = dist.at(h);
				nxtNode = h;
			}


		}
			visit.at(nxtNode)=true;

			for (int s=0; s<n; s++)
			{
				if (!visit.at(s))
				{
					if (min+matrix.at(nxtNode).at(s) < dist.at(s))
					{
						dist.at(s)=min+matrix.at(nxtNode).at(s);
					}
				}
			}
	}

	for (int c=0; c<n; c++)
	{
		cout<<endl<<"dist�ncia do n� "<<c<<" a partir de "<<src<<" � "<<dist.at(c)<<endl;
	}

	return 0;
}


