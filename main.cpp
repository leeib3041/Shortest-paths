#include "Graph.h"
#include "Timer.h"
#include <queue>

using namespace std;


int MAX = numeric_limits<int>::max();

//####implement the Dijkstra’s Algorithm here
vector<int> computeShortestPath(Graph g, int node){
  int n = g.size();
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
  vector<int>distance(n);

  /* initiate distance list and queue */
  distance[node] = 0;
  for( int i = 0; i < n; i++ ) {
    if( i != node ) distance[i] = MAX; 
    q.push(make_pair(distance[i], i));
  }

  while( !q.empty() ) {
    pair<int,int> vertex = q.top();
    list<int> adjacent = g.getConnectedNodes(vertex.second);
    int connectionSize = adjacent.size();
    q.pop();

    for( int i = 0; i < connectionSize; i++ ) {
      int u = vertex.second;
      int z = adjacent.front();
      int w = g.getEdgeWeight(u, z);

      if( (distance[u] + w) < distance[z] ) {
        distance[z] = distance[u] + w;
        q.push(make_pair(distance[u]+w, z));
      }
      adjacent.pop_front();
    }
  }
  
  /* handles MAX and overflow INT (neg values) to equal -1 for controlled list */
  for( int i = 0; i < n; i++ ) if( distance[i] == MAX || distance[i] < 0 ) distance[i] = -1;
  /* print distance */
  cout << "distnace[" << node << "]: "; for( int i = 0; i < n; i++ ) cout << "\t" << distance[i]; cout << endl;

  return distance;
};

//####compute all possible shortest paths by calling the Dijkstra's Algorithm on each pair of nodes
vector<vector<int> > computeAllPairsShortestPath(Graph g){
  vector<vector<int> > allPairsShortestPath;
  for( int i = 0; i < g.size(); i++ ) allPairsShortestPath.push_back(computeShortestPath(g, i));
  return allPairsShortestPath;
};

////BONUS
////####compute all possible shortest paths by implementing the dynamic programming approach
// Matrix computeAllPairsShortestPathDynamicProgramming(Graph g){

// };

bool compareResults(Graph g, Matrix a, Matrix b){

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g.size(); j++){
      if(a[i][j] != b[i][j]){
        return false;
      }
    }
  }

  return true;
}


int main(){

  //create graph as a random matrix
  Graph g(10,10);
  cout << "Graph generated " << endl;
  
  /* print graph and list of connected nodes for each node */
  g.print(); cout << endl;
  // for( int i = 0; i < 10; i++ ) {
  //   list<int> ls = g.getConnectedNodes(i);
  //   cout << "node " << i << ": ";
  //   for( auto it = ls.begin(); it != ls.end(); ++it ) cout << " " << *it; // requires -std=c++1
  //   cout << endl;
  // }
  cout << endl;

  //compute shortest path
  Timer time;
  time.start();
  Matrix a = computeAllPairsShortestPath(g);
  time.stop();
  cout << endl << "Time with Dijkstra's algorithm: " << time.getElapsedTimeInSec() << endl;

  // //compute all possible shortest paths
  // time.start();
  // Matrix b = computeAllPairsShortestPathDynamicProgramming(g);
  // time.stop();
  // cout << endl << "Time with Dynamic programming: " << time.getElapsedTimeInSec() << endl;

  // //compute by dynamic programming approach
  // if(compareResults(g,a,b)){
  //   cout << "They are the same" << endl;
  // }
  // else{
  //   cout << "Different" << endl;
  // }

};
