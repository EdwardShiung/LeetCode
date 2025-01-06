'''
[Question]: LeetCode 30
[Type]: Sliding Window
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

'''



class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # Edge Case:
        if len(s) == 0 or len(words[0]) == 0:
            return []
        
        # Set a result array: Store the results
        results = []
        
        # Count the word in words' list
        word_count = len(words)
        
        # Count the word's length from word list
        word_length = len(words[0])
        
        # Set a Hashmap_01: Record the Words' List
        wordList = {}
        
            # Using for-loop to record the words count
        for word in words:
            wordList[word] = wordList.get(word, 0) + 1
        
        
        # [Core]: Calculate the Results
            # Calculate the limitation in 1st loop
        outerLimitation = len(s) - word_count * word_length + 1
            # Using 2 loops to calculate the results
            # Outer loop 
        for i in range(outerLimitation):
            # Set a Hashmap_02: Verify and compared tools
            verifyMap = {}
            # Inner loop
            for j in range(0, word_count):
                # Record the next word position
                next_word_index = i + j * word_length
                # Store the word
                word = s[next_word_index:next_word_index + word_length]
                
                # Verify_01: the word whether is in the wordList or not
                if word not in wordList:
                    break
                
                # If word in wordList, add the word to the verifyMap
                verifyMap[word] = verifyMap.get(word, 0) + 1
                
                # Verify_02: Check the number of word in verifyMap is not higher than wordList
                if verifyMap[word] > wordList.get(word, 0):
                    break
                
                if j + 1 == word_count:
                    results.append(i)

        return results    
    
    
    '''
    參考解答：
    https://www.youtube.com/watch?v=ddSzsLUSPrQ
    
    TC = O(M*N*len)
    
    M 代表 String
    N 代表 Word Count --> 也就是題目 words' list 中，有多少個字
    len 代表：每一個字的長度
    
    SC = O(M + N)
    M 代表 第一個 Hashmap
    N 代表 第二個 Hashmap
    '''