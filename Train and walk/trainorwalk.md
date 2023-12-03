=>Objectice: CITY A TO B
=>1 metre in P sec
=>train from C to D in Q sec starts at t = Y sec 
=>Path 1: Simply go from city A to B withput using the train
=>Path 2: A path from A to B using the train

Path 1: 
distance AB = abs(x[A] - x[B])
Speed P sec for 1meter 
time1 = P * abs(x[A] - x[B])

Patg 2:
City A to city C and go to city D and goto city B
d[AC] = abs(x[C] - x[A]) Walking
d[CD] = abs(x[C] - x[D]) Train
d[DB] = abs(x[D] - x[B]) Walking
time2 = P*AC + Q*CD + P*DB

time for AC = P*AC
if time for AC>Y:
   Can not catch train in time
else
Waiting time = Y - P*AC
time2 += Waiting time

res = min(time1, time2)
