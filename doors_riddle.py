import random

# simulate 3 doors riddle from movie 21
# not by any means clean implementation, we use globals etc. but hey, it works and gets the job done :D
rounds = 0
first_pick_wins = 0
second_pick_wins = 0

def show_result(first_pick_wins, second_pick_wins, rounds):
    print(f"\nROUND {rounds}: ")
    print("first_pick_wins   = ", first_pick_wins, "   percent won=", first_pick_wins/rounds * 100)
    print("second_pick_wins  = ", second_pick_wins, "   percent won=", second_pick_wins/rounds * 100, "\n")

def play_round():
    global first_pick_wins
    global second_pick_wins
    global rounds

    win_door = random.randint(1,3)
    first_pick = random.randint(1,3)

    # open a door that is not winning
    open_door = random.randint(1,3)
    while(open_door == win_door or open_door == first_pick ):
        open_door +=1 
        if open_door>3:
            open_door = 1

    # second pick is the other door (must be not equal to first pick and not equal to open door)
    second_pick = random.randint(1,3)
    while(second_pick == first_pick or second_pick == open_door):
        second_pick+=1
        if second_pick>3:
            second_pick=1

    # keep scores of first and second pick wins
    if first_pick == win_door:
        first_pick_wins +=1

    if second_pick == win_door:
        second_pick_wins +=1

    # inc rounds
    rounds += 1


# simulate playing this game 1 million times
for c in range(0, 1000000):
    play_round()
    # show result while playing every 1k rounds
    # if c  % 1000 == 0:
    #    show_result(first_pick_wins, second_pick_wins, rounds)


# show final result
show_result(first_pick_wins, second_pick_wins, rounds)


