#include "GameEngine.h"
#include <string>
#include <vector>
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
GameEngine::GameEngine(uint boardSize, std::vector<Player *> *players):board(boardSize,players){
    currentRound = 1;
}

GameEngine::~GameEngine(){}

const Board& GameEngine::getBoard() const{
  return this->board;
}

Player* GameEngine::operator[](uint id) const{
    for (int i=0; i< board.getlen(); i++){
      if (board.getpls()[i]->getID() == id){
          return board.getpls()[i];
      }
    }
    return nullptr;
}

bool GameEngine::isFinished() const{
    return (board.getlen()==0 || (board.getlen()==1 && board.isCoordHill(board.getpls()[0]->getCoord())));
}

void GameEngine::takeTurn(){
/*
    std::cout << "-- START ROUND " << std::to_string(currentRound) << " --" << std::endl;
    board.updateStorm(currentRound);
      for (int i=0; i< board.getlen(); i++){
        // uint d = board.getpls()[i]->getID();
        if ((!(board.getpls()[i]->isDead()))){
          takeTurnForPlayer(board.getpls()[i]->getID());
        // if(d != board.getpls()[i]->getID()){
          // i--;
        // }
        }
    }
    std::cout << "-- END ROUND " << std::to_string(currentRound) << " --" << std::endl;
    currentRound+=1;*/
}

Move GameEngine::takeTurnForPlayer(uint playerID){/*
  for (int k=0; k< board.getlen(); k++){
    if (board.getpls()[k]->getID()==playerID){

  if (board.isStormInCoord(board.getpls()[k]->getCoord())){
    std::cout << board.getpls()[k]->getFullName() << "(" << board.getpls()[k]->getHP() << ") is STORMED! (" <<  -Entity::stormDamageForRound(currentRound) << ")" << std::endl;
    int dmg = -Entity::stormDamageForRound(currentRound);
    board.getpls()[k]->setHP(board.getpls()[k]->getHP()+dmg);
  }

  if ( board.getpls()[k]->isDead()){
    std::cout << board.getpls()[k]->getFullName() << "("<<  board.getpls()[k]->getHP() << ") DIED." << std::endl;
    delete board.getpls()[k];
    return NOOP;
  }

  for (int l=0; l<board.getpls()[k]->getPriorityList().size(); l++){
    if (board.getpls()[k]->getPriorityList()[l] == NOOP){
      return NOOP;
    }
  else if (board.getpls()[k]->getPriorityList()[l] == ATTACK){
      for (int a2=0; a2< board.getlen(); a2++){
        for (int a3=0; a3< board.visibleCoordsFromCoord(board.getpls()[k]->getCoord()).size(); a3++){
          if (board.getpls()[a2]->getCoord()==board.visibleCoordsFromCoord(board.getpls()[k]->getCoord())[a3]){
            if (!(board.getpls()[a2]->isDead())){
              board.getpls()[k]->attackTo(board.getpls()[a2]);

              if ( board.getpls()[a2]->isDead()){
                std::cout << board.getpls()[a2]->getFullName() << "(" << board.getpls()[a2]->getHP() << ") DIED." << std::endl;
                delete board.getpls()[a2];
              }
              return ATTACK;
            }
          }
      }
    }
  }
  else{
    if (board.calculateCoordWithMove(board.getpls()[k]->getPriorityList()[l], board.getpls()[k]->getCoord()) != board.getpls()[k]->getCoord()){
      if ((board.getpls()[k]->getCoord().y>(board.getSize()-1)/2 && board.getpls()[k]->getPriorityList()[l]==UP)
       || (board.getpls()[k]->getCoord().y<(board.getSize()-1)/2 && board.getpls()[k]->getPriorityList()[l]==DOWN)
       || (board.getpls()[k]->getCoord().x<(board.getSize()-1)/2 && board.getpls()[k]->getPriorityList()[l]==RIGHT)
       || (board.getpls()[k]->getCoord().x>(board.getSize()-1)/2 && board.getpls()[k]->getPriorityList()[l]==LEFT)){
      board.getpls()[k]->executeMove(board.getpls()[k]->getPriorityList()[l]);
      return board.getpls()[k]->getPriorityList()[l];
          }
        }
      }
    }
  }
}
return NOOP;*/
}

Player *GameEngine::getWinnerPlayer() const{
  if (isFinished() && board.getlen()==1){
    return board.getpls()[0];
  }
  return nullptr;
}

void GameEngine::sort(){
  for (int i=0; i< board.getlen(); i++){
    sorted.push_back(board.getpls()[i]->getID());
  }

  for (int i=1; i< board.getlen(); i++){
    int k = sorted[i];
    int j = i-1;
    while(j>=0 && sorted[j] > k){
      sorted[j+1] = sorted[j];
      j-=1;
    }
        sorted[j+1] = k;
  }
}
