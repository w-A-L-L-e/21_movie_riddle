# Doors riddle

Say you are at game show and get to choose between 3 doors.
One door has a big prise behind it, the other two doors have nothing.
You pick a door. But then the gamehost says: I will show you a door
that is not winning. And then asks you if you want to keep your first pick
or change your choice.

What should you do? Is it the same or should you switch?

The answer is that if you switch your odds improve. The first pick is 33%
winning however if you switch then your odds improve. It's actually not 66% but it is way
better than 33% (close to 50%).

Run the simulation and see the second pick does get more wins:

```
$ python doors_riddle.py

ROUND 1000000:
first_pick_wins   =  333498    percent won= 33.3498
second_pick_wins  =  481495    percent won= 48.1495
```

This riddle is also featured in the movie 21 with Kevin Spacey etc.
https://www.imdb.com/title/tt0478087
