#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

class Node {
public:
  Node(string name);
  void addEdge(string name);
  bool isConnected(string name);
  bool isPast(string name);
  void addInc(string name);
  bool hasInc();
  int numInc();
  string getName();

  vector<string> edges;
  vector<string> incoming;
  
  
private:
  string uva_name;
  int number;
};

string Node::getName(){
  return this->uva_name;
}


Node::Node(string name){
  this->uva_name = name;
  this->number = 0;
}

void Node::addEdge(string name){
  this->edges.push_back(name);
}

void Node::addInc(string name){
  this->number = this->number + 1;
  this->incoming.push_back(name);
}

int Node::numInc(){
  return this->number;
}

bool Node::hasInc(){
  if(this->number > 0){
    return true;
  }
  return false;
}

bool Node::isConnected(string name){
  int size = this->edges.size();
  for(int i = 0; i < size; i++){
    if(this->edges[i] == name){
      return true;
    }
  }
  return false;
}

bool Node::isPast(string name){
  int size = this->incoming.size();
  for(int i = 0; i < size; i++){
    if(this->edges[i] == name){
      return true;
    }
  }
  return false;
}


string topological_sort(map<string,Node> graph, vector<string> nodes);




int main(int argc, char **argv){
  if(argc != 2){
    cout <<"Only give an input file as the parameter" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);

  if(!file.is_open()){
    cout << "File was not opened" << endl;
    exit(2);
  }

  string s1, s2;
  bool end = false;

  vector<Node> graph;
  vector<string> class_names;

  while(end == false){
    file >> s1;
    file >> s2;

    if(s1 == "0" && s2 == "0"){
      end = true;
      break;
    }

    if(std::find(class_names.begin(), class_names.end(), s1) == class_names.end()){
      class_names.push_back(s1);
      Node newnode = Node(s1);
      graph.push_back(newnode);
    }

    
    if(std::find(class_names.begin(), class_names.end(), s2) == class_names.end()){
      class_names.push_back(s2);
      Node newnode = Node(s2);
      graph.push_back(newnode);
    }
  }
  file.close();

  end = false;
  bool found1 = false;
  bool found2 = false;
  ifstream file_again(argv[1], ifstream::binary);

  while(end == false){
    file_again >> s1;
    file_again >> s2;

    if(s1 == "0" && s2 == "0"){
      end = true;
      break;
    }

    //getting index
    for(int i = 0; i < class_names.size(); i++){
      if(s1 == class_names[i]){
	graph[i].addEdge(s1);
	found1 = true;
      }
      if(s2 == class_names[i]){
	graph[i].addInc(s2);
	found2 = true;
      }

      if(found1 == true && found2 == true){
	i = class_names.size();
	found1 = false;
	found2 = false;
      }
    }
  }

  file_again.close();

  map<string, Node> the_graph;
  for(int i = 0; i < class_names.size(); i++){
      the_graph.insert(std::pair<string,Node>(class_names[i],graph[i]));
  }

  //we have a map with nodes, and directed edges
  string output = topological_sort(the_graph,class_names);
  cout << output << endl;
  return 0;
}


string topological_sort(map<string,Node> graph, vector<string> nodes){
  string output = "";
  //we will need a queue
  queue<string> q;
  string v, w;

  int nsize = nodes.size();
  bool visited[nsize];

  //this stores how many of the prerequisites have been visited
  int visitedb[nsize];

  int holder = 0;

  //initialize all values to false
  for(int i = 0; i < nsize; i++){
    visited[i] = false;
    visitedb[i] = 0;
  }

  for(int i = 0; i < nsize; i++){
    if(graph.at(nodes[i]).numInc() == 0){
      q.push(nodes[i]);
      visited[i] = true;
    }
  }

  while(!q.empty()){
    Node temp = graph.at(q.front());
    q.pop();
    output = output + " " + temp.getName();

    for(int i = 0; i < temp.edges.size(); i++){
      string t = temp.edges[i];
      cout << t << endl;

      //finding temp
      for(int z = 0; z < nodes.size(); z++){
	if(t == nodes[z]){
	  holder = z;
	  z = nodes.size();
	}
      }
      if(visited[holder] == false){
	if(visitedb[holder] == graph.at(nodes[holder]).numInc()){
	  q.push(nodes[holder]);
	  visited[holder] = true;
	}
	else{
	  visitedb[holder] = visitedb[holder] + 1;
	}
      }
    }
  }

  return output;
}
