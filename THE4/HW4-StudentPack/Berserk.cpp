#include "Berserk.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Berserk::Berserk(uint id, int x, int y):Player(id,x,y){
  this->setHP(100);
}

Armor Berserk::getArmor() const{
  return WOODEN;
}

Weapon Berserk::getWeapon() const{
  return PISTOL;
}

std::vector<Move> Berserk::getPriorityList() const{
  return { ATTACK, UP, LEFT, DOWN, RIGHT };
}

const std::string Berserk::getFullName() const{
  return "Berserk" + this->getBoardID();
}
