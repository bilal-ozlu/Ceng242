#include "Board.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Board::Board(uint boardSize, std::vector<Player *> *players):boardSize(boardSize),players(players){}

Board::~Board(){}

uint Board::getSize() const{
  return this->boardSize;
}

bool Board::isCoordInBoard(const Coordinate& coord) const{
    return ( coord.x < this->getSize() && coord.y < this->getSize() && coord.x>=0 && coord.y>=0);
}

bool Board::isStormInCoord(const Coordinate &coord) const{
    return (isCoordInBoard(coord) && (!isCoordHill(coord)) && (coord.x < sss || coord.x >= this->getSize()-sss || coord.y < sss || coord.y >= this->getSize()-sss));
}

bool Board::isCoordHill(const Coordinate& coord) const{
    return (coord.x == coord.y && coord.x == (this->getSize()-1)/2);
}

Player *Board::operator[](const Coordinate& coord) const{
  if (isCoordInBoard(coord)){
    for (int i=0; i< this->getlen(); i++){
      if ((*players)[i]->getCoord() == coord){
        return (*players)[i];
      }
    }}
    return nullptr;
}

Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const{
  if (move!=ATTACK && move!= NOOP){
      if (move== UP && isCoordInBoard(Coordinate(coord.x,coord.y-1))){
        for (int i=0; i< this->getlen(); i++){
          if ((*players)[i]->getCoord().x == coord.x && (*players)[i]->getCoord().y == coord.y-1){
            return coord;
            }
          }
          return Coordinate(coord.x,coord.y-1);
        }
      else if (move== DOWN && isCoordInBoard(Coordinate(coord.x,coord.y+1))){
          for (int i=0; i< this->getlen(); i++){
            if ((*players)[i]->getCoord().x == coord.x && (*players)[i]->getCoord().y == coord.y+1){
              return coord;
              }
            }
            return Coordinate(coord.x,coord.y+1);
          }
      else if (move== LEFT && isCoordInBoard(Coordinate(coord.x-1,coord.y))){
        for (int i=0; i< this->getlen(); i++){
          if ((*players)[i]->getCoord().x == coord.x-1 && (*players)[i]->getCoord().y == coord.y){
            return coord;
            }
          }
          return Coordinate(coord.x-1,coord.y);
        }
      else if (move== RIGHT && isCoordInBoard(Coordinate(coord.x+1,coord.y))){
        for (int i=0; i< this->getlen(); i++){
          if ((*players)[i]->getCoord().x == coord.x+1 && (*players)[i]->getCoord().y == coord.y){
            return coord;
            }
          }
          return Coordinate(coord.x+1,coord.y);
        }
      }
      return coord;
}

std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const{
    std::vector<Coordinate> res;
    if (isCoordInBoard(coord)){
    if (coord.y-1 >=0 && coord.y-1 < this->getSize() && coord.x >=0 && coord.x < this->getSize())
      {res.push_back(Coordinate(coord.x,coord.y-1));}
    if (coord.y+1 >=0 && coord.y+1 < this->getSize() && coord.x >=0 && coord.x < this->getSize())
      {res.push_back(Coordinate(coord.x,coord.y+1));}
    if (coord.y >=0 && coord.y < this->getSize() && coord.x-1 >=0 && coord.x-1 < this->getSize())
      {res.push_back(Coordinate(coord.x-1,coord.y));}
    if (coord.y >=0 && coord.y < this->getSize() && coord.x+1 >=0 && coord.x+1 < this->getSize())
      {res.push_back(Coordinate(coord.x+1,coord.y));}
    }

    return res;

}

void Board::updateStorm(uint currentRound){
    sss = Entity::stormWidthForRound(currentRound);
}

std::vector<Player *>Board::getpls() const{
  return *players;
}

int Board::getlen() const{
  return players->size();
}
