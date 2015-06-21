# Problem 250 TextStatistics
Most modern text editors are able to give some statistics about the text they are editing. One nice statistic is the average word length in the text.
A word is a maximal continuous sequence of letters ('a'-'z', 'A'-'Z'). Words can be separated by spaces, digits, and punctuation marks.
The average word length is the sum of all the words' lengths divided by the total number of words. For example, in the text "This is div2 easy problem.", there are 5 words: "This", "is", "div", "easy", and "problem". The sum of the word lengths is 4+2+3+4+7=20, so the average word length is 20/5=4.
Given a string text, return the average word length in it. If there are no words in the text, return 0.0.

**Solution:**
A word consists of letters, so we only need to find a single letter on the leftmost and then scan to the right until reach to the end of the text or reach to a character which is not a letter (‘a’-‘z’,’A’-‘Z’) then do it again. 

**Complexity:** O(n).

**Tags:** Implementation, Strings.

# Problem 500 CreatePairs
You are given a list of integers, and you are allowed to group elements into pairs. Each element must either belong to a single pair or remain unpaired. Sum the products of the pairs with the values of the unpaired elements. Your goal is to maximize this sum.
For example, consider the list {0, 1, 2, 4, 3, 5}. If you make the pairs (2, 3) and (4, 5), the sum is 0 + 1 + (2 * 3) + (4 * 5) = 27.
You are given a vector <int> data containing the list of integers. Return the maximum possible sum.

**Solution:**
This problem requires summing products of pairs of elements, so it is reasonable to group 2 largest elements which have value larger than 1 and to group 2 smallest elements which have value smaller than 0. After that if the smallest element is non-negative or there is no value 0 then sum all the rest of the array, else if there is an element which is 0 then group 0 with that negative element and then sum all the rest of the array. 

**Complexity:** O(n).

**Tags:** Greedy, Math.

# Problem 1000 Squares
You are given a rectangular field divided into square cells. Each cell contains a letter. A square with vertices in the centers of four cells is called valid if those four cells are distinct and all contain the same letter. For example, the following field contains two valid squares:
ABA
BAB
ABA
One has vertices in the centers of the following squares:
A.A
...
A.A
Another has vertices in the centers of the following cells:
.B.
B.B
.B.
You are given a vector <string> field. The j-th character of the i-th element of field is the letter contained in the cell at row i, column j. Return the number of distinct valid squares in the field. Two squares are distinct if one has a vertex in a cell where the other does not.

**Solution:**
Given a rectangular field which each cell is a character, the problem asks us to count how many squares are there which have its 4 corners all contain the same letter. First, let's find a pair of cells that contain the same letter, now we can 



*These problems are the properties of TopCoder, Inc. Any use or reproduction of these problems must be referenced to Topcoder, Inc.*