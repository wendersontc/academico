#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define oo ((1LL<<31)-1)
#define MAXN 50005

using namespace std;

int nodes,
    edges;

vector<pair<int,int > > Graph[ MAXN ];
int distMin[ MAXN ];

queue<int> Queue;
bitset<MAXN> inQueue;

void readData() {

     int x,
         y,
         cost;

     ifstream fin(FIN);

     fin>>nodes>>edges;

     while(edges--){
           fin>>x>>y>>cost;
           Graph[ x ].push_back({y,cost});
     }

     fin.close();
};

void Dijkstra() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;

     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while( !Queue.empty() ) {

            int node = Queue.front();

            Queue.pop();

            inQueue[ node ] = false;

            for(auto it : Graph[ node ]) {

                if(distMin[ it.first ] > distMin[ node ] + it.second) {

                   distMin[ it.first ] = distMin[ node ] + it.second;

                   if(!inQueue[ it.first ]) {

                       Queue.push( it.first );

                       inQueue[ it.first ] = true;
                   }
                }
            }
     }
};


void writeData() {

     ofstream fout(FOUT);

     for(int i = 2; i <= nodes; i++)

         (distMin[ i ] < oo) ? fout<<distMin[ i ]<<" " : fout<<0<<" ";

     fout.close();
};


int main() {

 readData();
 Dijkstra();
 writeData();

 return(0);
};
