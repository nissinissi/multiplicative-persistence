# multiplicative persistence

The multiplicative persistence of an integer is the how many times you can replace the number by the product of its digits, before it becomes a single digit.

It is conjectured that the largest possible persistence for an integer in base 10 is 11 (minimally achieved by 277777788888899).

This repository includes an attempt to find other integers whose multiplicative persistence is 11, using a brute force search and some of the observations in https://oeis.org/A003001.

The digit product of a number of persistence 12, is a number of persistence 11. This means that if one of the known numbers of persistence 11 has prime factors that all belong to the set {2,3,5,7}, the problem is solved.
