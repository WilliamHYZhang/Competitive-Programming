Starting on this solution, I'll try to add an analysis to each problem.

At first, I thought that brute force was not possible since at the worst case, you will have to update 1000 numbers 100 times, 
which is about 100,000 operations and I didn't know if it would be enough. However, the test cases were quite nice and brute force
worked.

PLAN:
1. Have an array, "times", of 1000 integers each initialized as 0. The index i represents the time point i to time point i+1 
covered. the element will represent how many lifeguards cover it.

2. Take input as a vector of pairs, "shifts", indicating the start and end times of each shift (on the hindsight, making this an
array would be better) In the same for loop, each index in the "times" array that falls in the range start <= index < end should 
have their value increased to by 1.

3. Set a variable equal to the maximum amount of time, "maxTime"

4. For each pair in shifts, subtract one from any element with its index within start <= index < end.

5. Set variable "tempMax"  = 0 for each pair. This represents the amount of time covered if that shift is removed.

6. For each element in times, if the element is greater than 0, add one to tempMax.

7. If tempMax is greater than maxTime, maxTime = tempMax.

8. Print maxTime as the final answer.


