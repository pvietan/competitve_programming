# Problem 250
Most modern text editors are able to give some statistics about the text they are editing. One nice statistic is the average word length in the text.
A word is a maximal continuous sequence of letters ('a'-'z', 'A'-'Z'). Words can be separated by spaces, digits, and punctuation marks.
The average word length is the sum of all the words' lengths divided by the total number of words. For example, in the text "This is div2 easy problem.", there are 5 words: "This", "is", "div", "easy", and "problem". The sum of the word lengths is 4+2+3+4+7=20, so the average word length is 20/5=4.
Given a string text, return the average word length in it. If there are no words in the text, return 0.0.

**Solution:**
A word consists of letters, so we only need to find a single letter on the leftmost and then scan to the right until reach to the end of the text or reach to a character which is not a letter (‘a’-‘z’,’A’-‘Z’) then do it again. 

**Complexity:** O(n).

**Tags:** Implementation, Strings.

# Problem 500

# Problem 1000


*These problems are the properties of TopCoder, Inc. Any use or reproduction of these problems must be referenced to Topcoder, Inc.*