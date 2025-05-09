//
// simulation of the 3 doors riddle from movie 21
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rounds = 0;
int first_pick_wins = 0;
int second_pick_wins = 0;

int randint(int min, int max) {
  int res = rand() % (max - min + 1) + min;
  return res;
}

void show_result(int first_pick_wins, int second_pick_wins, int rounds) {
  printf("\nROUND: %d \n", rounds);
  double first_percent = (double)first_pick_wins / (double)rounds * 100;
  double second_percent = (double)second_pick_wins / (double)rounds * 100;

  printf("First pick wins   = %d  percent won = %f\n", first_pick_wins,
         first_percent);
  printf("Second pick wins  = %d  percent won = %f\n\n", second_pick_wins,
         second_percent);
}

void play_round() {
  int win_door = randint(1, 3);
  int first_pick = randint(1, 3);

  // open a door that is not winning
  int open_door = randint(1, 3);
  while (open_door == win_door || open_door == first_pick) {
    open_door += 1;
    if (open_door > 3)
      open_door = 1;
  }

  // second pick is the other door(must be not equal to first pick
  // and not equal to open door)
  int second_pick = randint(1, 3);
  while (second_pick == first_pick || second_pick == open_door) {
    second_pick += 1;
    if (second_pick > 3)
      second_pick = 1;
  }

  // keep scores of first and second pick wins
  if (first_pick == win_door)
    first_pick_wins += 1;

  if (second_pick == win_door)
    second_pick_wins += 1;

  // inc rounds
  rounds += 1;
}

int main() {
  // simulate playing this game 1 million times
  for (int c = 0; c < 1000000; c++) {
    play_round();
  }

  show_result(first_pick_wins, second_pick_wins, rounds);
}
