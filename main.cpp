#include "Graph.h"
#include "Timer.h"
#include <queue>

using namespace std;


int MAX = numeric_limits<int>::max();

// vector<int> computeShortestPath(Graph g, int node){

//   //####implement the Dijkstra’s Algorithm here

// };

// vector<vector<int> > computeAllPairsShortestPath(Graph g){

//   //####compute all possible shortest paths by calling the Dijkstra's Algorithm on each pair of nodes

// };

// Matrix computeAllPairsShortestPathDynamicProgramming(Graph g){
//   //BONUS
//   //####compute all possible shortest paths by implementing the dynamic programming approach
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
  Graph g(5,5);
  cout << "Graph generated " << endl;
  g.print();

  // //compute shortest path
  // Timer time;
  // time.start();
  // Matrix a = computeAllPairsShortestPath(g);
  // time.stop();
  // cout << "Time with Dijkstra's algorithm" << time.getElapsedTimeInSec() << endl;

  // //compute all possible shortest paths
  // time.start();
  // Matrix b = computeAllPairsShortestPathDynamicProgramming(g);
  // time.stop();
  // cout << "Time with Dynamic programming" << time.getElapsedTimeInSec() << endl;

  // //compute by dynamic programming approach
  // if(compareResults(g,a,b)){
  //   cout << "They are the same" << endl;
  // }
  // else{
  //   cout << "Different" << endl;
  // }

};
