Again, pure brute force. To get rid of duplicates, I used std::set to store the different combinations. Although I originally wanted to use unordered set, turns out you have to create your own hash function for tuples. Either way it works, although unordered set is faster.

First, I created helper functions. "make range" takes in a specific number and the number of numbers in the dial. It returns a vector of all of the possible values +- 2 that still will make the lock work. "add combos" calls "make range" 3 times (once for each number) and then iterates through every possible combination of numbers that work. It adds the 3 numbers combined as a tuple to a set.

All the main fuction does is call "add combos" twice (Once for farmer, and once for master). Because "add combos" takes the set that it adds to as a direct reference (using &), they add to the same set and prevents any repeats.

Finally the size of set is the answer.
