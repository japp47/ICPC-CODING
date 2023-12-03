group is a set of events belonging to same table
load job is a group of groups (at max K)
load job 1 group1 group2 ... group k - same table index
load job 2 group1 group2 ... group k - same table index
.
.
load job J group1 group2 ... group k - same table index

Minimize the maxinum or maximize the minimum, try Binary search

I am going to allow files of the size S only.

group size = file size

if all events are done with S as limit of file size then 
all events can also be done with limit as S+1
S is monotonic.

Objective: To check if we can finish all events within J
           load lobs each load having at max K groups and 
           file size limit is S.

count[i][1] = number of events on table with i with payload size as 1
count[i][2] = number of events on table with i with payload size as 2

With limit S as file size we got F number of files(or)group ~F/K load jobs.

check(S):
for table in table_index:
    file1 -> 2 + 2....... 0 or 1 space remaining
    Within S units how many 2 size evenets can be inserted = S/2 can be pushed in 1 file
    count[1][2] such events
    events_per_file = S/2
    number of files reqd = ceil(count[i][2] / evebts_per_file )
    empty_space = 0
    empty_space = 2*(events_per_file - count[i][2]% events_per_file)
    if S%2:
        empty_space += number of files reqd
    if(count[i][1] <=empty_space)
        final_file_count = number of files reqd
    else:
        remaining_ones = count[i][1] - empty_spaces
        final_file_count = number of files reqd + ceil(remaining_ones/S)
    load_jobs_reqd = ceil(final_file_count/K)
    total_load_jobs += load_jobs_reqd

if(total_jobs_reqd<= J):
    return true;
else return false    

S=7
ceil S/2 = 3
count[i][2] = 7 
F1 F2 F3
2  2  2
2  2  ..
2  2  ..
.  .  .