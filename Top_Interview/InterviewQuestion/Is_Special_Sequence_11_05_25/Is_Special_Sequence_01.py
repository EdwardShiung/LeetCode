

# Data scientists at Amazon are working on a utility for genome sequencing algorithms that look for palindromic patterns in DNA sequence strings.

# A DNA sequence string is considered special if it can be divided into two non-empty substrings 
# such that the resulting strings can be rearranged to form palindromes 
# after removing at most one character from each of them.

# Given a string, dna_sequence, return the string "YES" if it is a special sequence and "NO" otherwise.

# Note: A substring is defined as any contiguous segment of a string. 
# A palindrome is a string that reads the same forwards and backwards such as "abccba", "aba", "b", and "ccc".

# Function Description

# Complete the function isSpecialSequence in the editor below.

# isSpecialSequence takes the following arguments:

# str dna_sequence: the given string of dna sequence
# Returns

# string: "YES" if the given sequence is special and "NO" otherwise

# Example 1:

# Input:  dna_sequence = "abcad"
# Output: "YES" 
# Explanation:

# String 1 = abca
# String 2 = d
# Palindrome_01 = aba(remove'c')
# Palindrome_02 = d


# Not Good for Time Complexity
# class Solution:
  
#   # Creating a helper function to check if the string is palindrome, return True directly
#   def is_palindrome(self, s:str) -> bool:
#       if s == s[::-1]:
#         return True
      
#   # Determine the string s is a palindrome after removing one character.
#   def is_palindrome_after_remove(self, s:str) -> bool:
    
#     # If the string is palindrome, return True directly.
#     if self.is_palindrome(s):
#       print(True)
#       return True

#     # Using for-loop to detect the palindrome
#       # Each time, we remove one element to detect the substring
#     for i in range(len(s)):
#       # Remove a character and rearrange the string
#       newString = s[:i] + s[i + 1:]
#       print("newString", newString)
      
#       if self.is_palindrome(newString):
#         print(True)
#         return True
      
#     print(False)
#     return False
  
#   def isSpecialSequence(self, dna_sequence: str) -> str:

#     n = len(dna_sequence)

#     for i in range(n):
#       preCharacters = dna_sequence[:i]
#       postCharacters = dna_sequence[i:]
#       print("PreCharacters",preCharacters, "PostCharacters", postCharacters)
#       # Pre-Characters use removing function but Post-Characters use normal is_palindrome function
#         # The question reminds us that you can remove at most once, so we only remove Pre-Characters.
#       if(self.is_palindrome_after_remove(preCharacters) and self.is_palindrome(postCharacters)):
#         return "YES"
#     return "NO"


# Optimize the Time Complexity
class Solution:
  
    def is_palindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
  
    def is_palindrome_after_remove(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                return self.is_palindrome(s[left + 1:right + 1]) or self.is_palindrome(s[left:right])
            left += 1
            right -= 1
        return True
  
    def isSpecialSequence(self, dna_sequence: str) -> str:
        n = len(dna_sequence)
        for i in range(n):
            preCharacters = dna_sequence[:i]
            postCharacters = dna_sequence[i:]
            if self.is_palindrome_after_remove(preCharacters) and self.is_palindrome(postCharacters):
                return "YES"
        return "NO"      


testString = "a"
solution = Solution()
print(solution.isSpecialSequence(testString))









