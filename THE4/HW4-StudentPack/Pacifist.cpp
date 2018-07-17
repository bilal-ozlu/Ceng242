#include "Pacifist.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Pacifist::Pacifist(uint id, int x, int y):Player(id,x,y){
  this->setHP(100);
}

Armor Pacifist::getArmor() const{
  return METAL;
}

Weapon Pacifist::getWeapon() const{
  return NOWEAPON;
}

std::vector<Move> Pacifist::getPriorityList() const{
  return { UP, LEFT, DOWN, RIGHT };
}

const std::string Pacifist::getFullName() const{
  return "Pacifist" + this->getBoardID();
}
