There's 3 basic steps I did to solve this problem.

1.Find bessie. This is done by comparing 3 consectives cows at a time (a, b, c). Bessie can either be a small cow wedged between two bigger cows or a big cow wedged between two smaller cows. Check if that is the case AND if a <= c. The latter is very important because you might have a case such as 1,4,5,2,6. Without the check, you might get 5 as bessie when it is actually 2. Obviously, the first and last cows cannot be compared so I had seperate if statements for those two edge cases.

2.Find where bessie should go. This might be a bit trickay if there is more than one cow with the same height as bessie. What I did was I just went through the entire list smallest to largest. If the cow height at the position I am at is more than bessie, return that positions ONLY if the original bessie index is greater than the position I am at. Else, you have to check if the heights to the left of the cow are equal to bessie. Once you find one that isn't return that position.

3.Finally was to calculate the number of repeated heights between those two endpoints. What I mean by this is two equal consecutive heights counts as ONE repeat and three counts as two, so on and so forth. This is because if you have bessie, a, a, you can just swap bessie and the last 'a' instead of swapping twice. Pretty self-explainatory, just for loop through the values, if pos[i] == pos[i+1] then increase a variable.

The answer is the difference between where bessie should go and where bessie is, minus the number of repeats.
