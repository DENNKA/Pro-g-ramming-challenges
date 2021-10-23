#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

int main(){
  bool run = true;
  std::string rock = "rock", paper = "paper", scissors = "scissors";
  srand(time(NULL));
  while (run) {
    std::cout << "Choose element: ";
    std::string turnString;
    std::cin >> turnString;

    std::for_each(turnString.begin(), turnString.end(), [](char & c) {
        c = ::tolower(c);
    });

    int turn = turnString == rock ? 0 : turnString == paper ? 1 : turnString == scissors ? 2 : -1;

    if (turn == -1) continue;

    int botTurn = rand() % 3;

    std::cout << "Bot turn: " << (botTurn == 0 ? rock : botTurn == 1 ? paper : scissors) << std::endl;

    int shift = turn - botTurn;

    if (shift == 1 || shift == -2) {
      std::cout << "You win" << std::endl;
    } else if (shift == 0) {
      std::cout << "Stalemate" << std::endl;
    } else {
      std::cout << "You lose" << std::endl;
    }

  }
}
