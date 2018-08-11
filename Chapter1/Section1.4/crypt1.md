Fun problem! I didn't know what to do at first, since I knew that brute force would be approxiately O(n^5) where n is the length of the input. However, I quickly realized that at most n would be 10 (10 digits) and worst case would be only 10^5 or 100,000 operations which is great!

I wrote some helper functions first. 

"Partial product" takes 4 numbers and returns product the first 3 numbers as a combined 3 digit number (a, b, c, becomes abc) and the fourth number. So if it takes in (a, b, c, d) it returns abc * d.

"Get digits" takes a number and returns a vector of the digits that make up the number. Just simple mod 10 in a while loop.

"In" takes two vectors and returns true if every element in the first vector is in the second. Returns false otherwise.

The main body of the code is just 5 nested for loops iterating through the vector of input values. In each iteration, it takes the five digits: a, b, c, d, e. It calls partial product on (a, b, c, e) and on (a, b, c, d). Then it calls get digits on the results of those. If the length of the return value for get digits is not 3 it continues. If any of the elements in the return vector for get digits is not in the vector of inputs if continues (this is done using the "in" function). Then, it takes the sum, (sum1 + sum2*10) and calls get digits and in. If the in function returns false it continues. By this point if a,b,c,d,e have not made the program continue then it is a valid case. Add 1 to a counter. At the end, print counter and you're done.
