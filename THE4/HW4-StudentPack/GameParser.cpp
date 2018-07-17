#include "GameParser.h"
#include "Ambusher.h"
#include "Tracer.h"
#include "Berserk.h"
#include "Pacifist.h"
#include "Dummy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
std::pair<int, std::vector<Player *> *> GameParser::parseFileWithName(const std::string& filename){

  std::pair<int, std::vector<Player *> *> result;
  //std::vector<Player *> * players = new   std::vector<Player *> ;
  std::ifstream f;
  f.open(filename.c_str());
  while(f.good()){
    std::string w;
    std::string wwww;
    std::string n0;
    uint n1;
    int n2;
    int n3;
    f>>w;
    f>>w;
    f>>w;
    result.first = std::stoi(w);
    f>>w;
    f>>w;
    f>>w;
    int pc = std::stoi(w);
    for (int i=0; i<pc; i++){
      f>>w;
      int p = 0;
      if ((p = w.find("::")) != std::string::npos) {
          n1 = std::stoi(w.substr(0, p));
          w.erase(0, p + 2);
      }
      if ((p = w.find("::")) != std::string::npos) {
          n0 = w.substr(0, p);
          w.erase(0, p + 2);
      }
      if ((p = w.find("::")) != std::string::npos) {
          n2 = std::stoi(w.substr(0, p));
          w.erase(0, p + 2);
      }
    n3 = std::stoi(w);

    if (n0=="Ambusher"){
      /*players*/result.second->push_back(new Ambusher(n1,n2,n3));
    }
    else if (n0=="Tracer"){
    result.second->push_back( new Tracer(n1,n2,n3));
    }
    else if (n0=="Berserk"){
      result.second->push_back( new Berserk(n1,n2,n3));
    }
    else if (n0=="Pacifist"){
      result.second->push_back(new Pacifist(n1,n2,n3));
    }
    else if (n0=="Dummy"){
      result.second->push_back(new Dummy(n1,n2,n3));
    }
  }
}
//result.second = players;
  return result;
}
