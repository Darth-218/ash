/* fun.cpp --- why so serious?
 *
 * Author: alchemistsGestalt
 * Maintainer: alchemistsGestalt
 * Created: 17 May, 2024
 * Modified: 17 May, 2024
 *
 * Code:
 */

#include "ash.hpp"

#define NUM_GAMES 2
#define OR(a,b) a?a:b

void guess() {
  int secret = rand() % 100;
  int guess;
  TTY << "Guess a number between 0 (inclusive) and 100 (exclusive)!" << LF;
GAME:
  QUAD >> guess;
  switch (OR((guess>secret), -(secret>guess))) {
    default:
      ERR << "This shouldn't have happened" << LF;
    case 1:
      TTY << guess << " is too big :(" << LF;
      break;
    case -1:
      TTY << guess << " is too small :(" << LF;
      break;
    case 0:
      TTY << "The secret number was " << secret << "!!!! :D" << LF;
      return;
  }
  goto GAME;
}

auto stringify_card(int card) -> std::string {
  if (card <= 10)
    return std::to_string(card);
  else
    switch (card) {
      case 11:
        return "Jack";
      case 12:
        return "Queen";
      case 13:
        return "King";
    }
  return "INVALID CARD";
}

void acey_deucy() {
  int money = 100;
  int cards[3] = {0};
  int bet;
  TTY << "You will be shown two (2) cards." << LF;
  TTY << "How much do you bet that the next card's value will be between them?"
      << LF;
GAME:
  if (money <= 0)
    goto FAILED;
RANDOMISE:
  for (int i = 0; i < 3; i++) {
    cards[i] = rand() % 13 + 1;
  }
  if (cards[0] == cards[1])
    goto RANDOMISE;
  TTY << "You have " << money << " dollars." << LF;
  TTY << "Here are the next two cards:" << LF;
  TTY << stringify_card(cards[0]) << ", " << stringify_card(cards[1]) << LF;
  TTY << "Your bet? ";
  QUAD >> bet;
  if (bet == 0)
    TTY << "Cautious...";
  else if ((cards[2] > cards[0] && cards[2] < cards[1]) ||
      (cards[2] < cards[0] && cards[2] > cards[1])) {
    TTY << "You win!";
    money += bet;
  } else {
    TTY << "You lose!";
    money -= bet;
  }
  TTY << " (the last card was " << stringify_card(cards[2]) << ")" << LF;
  goto GAME;
FAILED:
  return;
}

auto main(int argc, char **argv) -> int {
  std::string games[] = {"Guess", "Acey-Deucy"};
  void (*game_funs[])() = {guess, acey_deucy};
  int i = 0;
  TTY << "Choose a game to play!" << LF;
  for (auto game : games) {
    TTY << "[" << i++ << "] " << game << LF;
  }
  QUAD >> i;
  if (i >= NUM_GAMES) {
    TTY << "Not a valid option, sorry :(" << LF;
    return -1;
  }
  srand(time(NULL));
  game_funs[i]();
  return 0;
}

/* fun.cpp ends here */
