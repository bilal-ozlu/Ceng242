#include "Player.h"
#include <string>
#include <iostream>
#include <ostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Player::Player(uint id, int x, int y):id(id), coordinate(x,y){}

Player::~Player(){}

uint Player::getID() const{
  return this->id;
}

const Coordinate& Player::getCoord() const{
  return this->coordinate;
}

int Player::getHP() const{
  return this->HP;
}

std::string Player::getBoardID() const{
  std::string x =std::to_string(this->id);
  if (x.length() == 1){
    return "0"+x;
  }
  else{
    return x;
  }
}

bool Player::isDead() const{
  return (this->HP<=0);
}

void Player::executeMove(Move move){
    int xx = coordinate.x;
    int yy = coordinate.y;

    if (move!=ATTACK && move!= NOOP){
        std::cout <<  this->getFullName() << "(" << this->getHP();

        if (move== UP){
            yy--;
            std::cout << ") moved UP." <<std::endl;
          }
        else if (move== DOWN){
            yy++;
            std::cout << ") moved DOWN." <<std::endl;
          }
        else if (move== LEFT){
            xx--;
            std::cout << ") moved LEFT." <<std::endl;
          }
        else if (move== RIGHT){
            xx++;
            std::cout << ") moved RIGHT." <<std::endl;
          }
        }
      setCoor(xx,yy);
}

bool Player::attackTo(Player *player){
    if(this->getID()!=player->getID()){
    int dmg = -Entity::damageForWeapon(this->getWeapon()) + Entity::damageReductionForArmor(player->getArmor());
    if (dmg>0){dmg=0;}
    std::cout << this->getFullName() << "(" << this->getHP() << ") ATTACKED " << player->getFullName() << "(" << player->getHP() << ")! (" << std::to_string(dmg) << ")" << std::endl;
    player->setHP(player->getHP() + dmg);

}
    return (player->getHP()<=0);
}

void Player::setHP(int hp){
  this->HP = hp;
}

void Player::setCoor(int a, int b){
  this->coordinate = Coordinate(a,b);
}
