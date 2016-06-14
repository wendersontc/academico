#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define MAXN 50005
#define oo ((1LL<<31)-1)
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"

using namespace std;

struct Node {

       int y,
           cost;
       bool operator < (const Node& n) const {

            return cost > n.cost;
       } 
};

vector<Node> Graph[ MAXN ];
int distMin[ MAXN ];
queue<Node> Queue;
bitset<MAXN> inQueue(0);

int nodes,
    edges;

//prototpes functions
void readData();
void Dijkstra();
void writeData();

//main function
int main() {

    readData();
    Dijkstra();
    writeData();

    return(0);
};

void readData() {

     int x;

     Node node;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(int ed = 1; ed <= edges; ed++) {

         scanf("%d %d %d", &x, &node.y, &node.cost);

         Graph[ x ].push_back( node ); 
     }

     fclose( stdin );
};

void Dijkstra() {

     Node node, 
          aux, 
          auxNode; 
     int  k;  

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;
  
     node.y = 1;

     node.cost = 0;

     Queue.push( node );

     inQueue[ 1 ] = true;

     while(!Queue.empty()) {
 
            aux = Queue.front();

            k = aux.y;

            Queue.pop();

            inQueue[ aux.y ] = false;

            for(int i = 0; i < Graph[ k ].size(); i++) {

                              int nodeY = Graph[ k ][ i ].y,

                                  nodeCost = Graph[ k ][ i ].cost;

                              if(distMin[ nodeY ] > distMin[ k ] + nodeCost) {

                                 distMin[ nodeY ] = distMin[ k ] + nodeCost;

                                 if(!inQueue[ nodeY ]) {
                                     
                                     auxNode.y = nodeY;

                                     auxNode.cost = distMin[ nodeY ];    

                                     Queue.push( auxNode );

                                     inQueue[ nodeY ] = true;
                                     
                                 }                            
                              }   
            }
     }
};

void writeData() {

     freopen(FOUT, "w", stdout);

     for(int i = 2; i <= nodes; i++) printf("%d ", (distMin[ i ] < oo) ? distMin[ i ] : 0);

     fclose( stdout );
};

