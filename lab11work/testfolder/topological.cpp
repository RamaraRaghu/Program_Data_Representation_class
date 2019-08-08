//Rakshith Raghu, rr5de, 12/3/2018
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <stack>
#include <list>
#include <map>
using namespace std;


class Graph {
public:
  
  Graph(int vertices);
  void addLine(string start, string end, map<string, int> m);
  void topological_sort();
  void print_function(stack<int> the_stack);
  
private:
  int number;
  list<int> *adjacent;
  void topological_util(int number, stack<int> &stack, bool visited[]);
  map<int,string> theMap;
};
/**@brief Creates a graph
 *@param vertices It asks what the number of nodes is
 */
Graph::Graph(int vertices){
  this->number = vertices;
  adjacent = new list<int>[this->number];
}

/**@brief Adds a directed edge into the graph
 *@param start is the first node that the edge starts out of
 *@param end is the is the second node where the edge ends in
 *@param m is a map to translate string name of classes to ints(which makes sorting easier)
 */

void Graph::addLine(string start, string end, map<string, int> m){
  //turning the strings into numbers
  theMap[m[start]] = start;
  theMap[m[end]] = end;

  //storing that in list
  adjacent[m[start]].push_back(m[end]);
}

/**@brief private function to run through the graph to the next available class
 *@param number is the index/node that the function starts at
 *@param stack is the stack containing the current list of classes already selected
 *@param visited is the boolean for breadth first algorithm being used overall. It colors a node as checked after the function runs through it
 */

void Graph::topological_util(int number, stack<int> &stack, bool visited[]){
  visited[number] = true;

  list<int>::iterator i;

  //this is the actual sorting function
  for(i = adjacent[number].begin(); i != adjacent[number].end(); ++i){
    if( visited[*i] != true){
      topological_util(*i, stack, visited);
    }
  }
  stack.push(number);
}

/**@brief is the public function of the topological sort. It sets up the breadth first algorithm and uses the util function for help
 *
 *
 *
 */


void Graph::topological_sort(){
  stack<int> temp_stack;
  int size = this->number;

  //sets the visited for everything false so it can all be sorted
  bool *visited = new bool[size];
  for(int i = 0; i < size; i++){
    visited[i] = false;
  }

  //runs the sorting function on everything
  for(int i = 0; i < size; i++){
    if(visited[i] == false){
      topological_util(i, temp_stack, visited);
    }
  }

  print_function(temp_stack);
  //returns a stack that can then be printed using another function
  
}

/**This actually prints the results of the topological sort
 *@param the_stack is the stack produced from the sort which is printed in reverse to get the order
 *
 */

void Graph::print_function(stack<int> the_stack){

  //placeholder variables
  int placeholder = 0;
  string the_class = "";

  //actually prints the data and then deletes it
  while(the_stack.empty() == false){
    placeholder = the_stack.top();
    the_class = theMap[placeholder];
    cout << the_class << " ";
    the_stack.pop();
  }
  cout << endl;
}



int main(int argc, char **argv){
  if(argc != 2){
    cout << "supply input file as the only parameter" << endl;
    exit(1);
  }
  
  ifstream file(argv[1], ifstream::binary);

  if(!file.is_open()){
    cout << "file was unable to open" << endl;
    exit(2);
  }

  string s1,s2;
  bool endread = false;
  list<string> lines;
  
  while(endread == false){
    file >> s1;
    file >> s2;

    if(s1 == "0" && s2 == "0"){
      endread = true;
      break;
    }

    lines.push_back(s1);
    lines.push_back(s2);

    lines.unique();
  }

  file.close();
  
  lines.sort();
  int size = lines.size();

  int count = 0;
  map<string, int> main_map;
  list<string>::iterator z; 
  for(z = lines.begin(); z != lines.end(); z++){
    string placeholder = *z;
    main_map[placeholder] = count;
    count++;
    } 

  Graph main_graph(size);

  endread = false;
  ifstream file_edge(argv[1], ifstream::binary);
  
  while(endread == false){
    file_edge >> s1;
    file_edge >> s2;
    if(s1 == "0" && s2 == "0"){
      endread = true;
      break;
    }
    main_graph.addLine(s1,s2, main_map);
  }
   main_graph.topological_sort();

  file_edge.close();
  return 0;
  
}
