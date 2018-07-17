#include "Tracer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Tracer::Tracer(uint id, int x, int y):Player(id,x,y){
  this->setHP(100);
}

Armor Tracer::getArmor() const{
  return BRICK;
}

Weapon Tracer::getWeapon() const{
  return SHOVEL;
}

std::vector<Move> Tracer::getPriorityList() const{
  return { UP, LEFT, DOWN, RIGHT, ATTACK };
}

const std::string Tracer::getFullName() const{
  return "Tracer" + this->getBoardID();
}
