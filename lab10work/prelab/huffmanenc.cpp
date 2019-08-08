#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include "heap.h"
#include "treenode.h"
using namespace std;

int main(int argc, char **argv){

  if(argc != 2){
    cout << "only supply input file" << endl;
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  char g;
  vector <int> frequencies;
  vector <char> chars;
  bool found = false;
  int total_count = 0;

  while((g = fgetc(fp)) != EOF){
    found = false;
    if(g > 32){
      for(int i = 0; i < chars.size(); i++){
	if(chars[i] == g){
	  frequencies[i] = frequencies[i] + 1;
	  found = true;
	  i = chars.size();
	}
      }
      if(found == false){
	chars.push_back(g);
	frequencies.push_back(1);
      }
      total_count = total_count + 1;
    }
  }





  heap binary_heap = heap(frequencies, chars);




  
  //creating the huffman tree
  while(binary_heap.findMin()->getFreq() != total_count){
    binary_heap.consolidate();

  }
  
  
  //binary_heap.findMin()->printTree(binary_heap.findMin(), "");
  
  
  binary_heap.generateCode(binary_heap.findMin(), "");
  map<char,string> result = binary_heap.getMap();

  for(map<char,string>::const_iterator it = result.begin(); it != result.end(); it++){
    cout << it->first << " " << it->second << endl;

  }


  for(int z = 0; z < 39; z++){
    cout << "-";
  }

  cout << "-" << endl;

  rewind(fp);
  int comp = 0;
  while((g = fgetc(fp)) != EOF){
    cout << result.at(g) << " ";
    comp = comp + result.at(g).length();
  }

  cout << " " << endl;

  for(int z = 0; z < 39; z++){
    cout << "-";
  }
  cout << "-" << endl;

  cout << "There are a total of " << total_count << " symbols that are encoded." << endl;
  cout << "There are " << chars.size() << " distinct symbols used." << endl;
  cout << "There were " << chars.size()*8 << " bits in the original file" << endl;
  cout << "There were " << comp << " bits in the compressed file" << endl;

  double compression = ((double) chars.size()) * 8 / ((double) comp);
  cout << "This gives a compression ratio of " << compression << endl;
  cout << "The cost of the Huffman tree is "<< binary_heap.getCost() << " bits per character." << endl;


  return 0;
  
  
}
