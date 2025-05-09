# Doors riddle

Say you are at game show and get to choose between 3 doors.
One door has a big prise behind it, the other two doors have nothing.
You pick a door. But then the gamehost says: I will show you a door
that is not winning. And then asks you if you want to keep your first pick
or change your choice.

What should you do? Is it the same or should you switch?

The answer is that if you switch your odds improve. The first pick is 33%
winning however if you switch then your odds improve.
When we simulate this we do see switching gets you 66%.

Run the simulation and see the second pick does get more wins:

```
$ python doors_riddle.py

ROUND 1000000:
First pick wins   =  333903    percent won = 33.3903
Second pick wins  =  666097    percent won = 66.6097

```

This riddle is also featured in the movie 21 with Kevin Spacey etc.
https://www.imdb.com/title/tt0478087

Update: added a c version of this simple simulation that is way faster for kicks ;)

```
$ gcc doors_riddle.c -o doors_riddle
$ ./doors_riddle

ROUND: 1000000
First pick wins   = 333081  percent won = 33.308100
Second pick wins  = 666919  percent won = 66.691900

```

Same results 66% wins when switching vs 33% when staying with first pick.
Let's see the difference in speed:

```
$ time python doors_riddle.py

ROUND 1000000:
First pick wins   =  333198    percent won = 33.3198
Second pick wins  =  666802    percent won = 66.6802

python doors_riddle.py  1.95s user 0.01s system 99% cpu 1.958 total


$ time ./doors_riddle

ROUND: 1000000
First pick wins   = 333081  percent won = 33.308100
Second pick wins  = 666919  percent won = 66.691900

./doors_riddle  0.12s user 0.00s system 99% cpu 0.122 total
```

C version is still more then 10 times faster (didn't even use -O2).
Pretty sure we can optimise the python version further using something
like pandas or even try cpython. Also the code is not clean and uses globals but it just gets the job done and proves our little riddle.
