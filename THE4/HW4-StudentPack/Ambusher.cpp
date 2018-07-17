#include "Ambusher.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Ambusher::Ambusher(uint id, int x, int y):Player(id,x,y){
  this->setHP(100);
}

Armor Ambusher::getArmor() const{
  return NOARMOR;
}

Weapon Ambusher::getWeapon() const{
  return SEMIAUTO;
}

std::vector<Move> Ambusher::getPriorityList() const{
  return { ATTACK };
}

const std::string Ambusher::getFullName() const{
  return "Ambusher" + this->getBoardID();
}
