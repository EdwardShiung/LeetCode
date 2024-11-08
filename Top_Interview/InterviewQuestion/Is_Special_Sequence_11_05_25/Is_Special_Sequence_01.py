

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



# class Solution:
#   # Determine the string s is a palindrome or not.
#   def is_palindrome_after_remove(self, s:str) -> bool:
    
#     # if the string is palindrome, return True directly
#     if s == s[::-1]:
#       return True

#     left = 0
#     right = len(s) - 1
    
#     while left < right:
#       if s[left] != s[right]:
#         skip_left = s[left + 1: right + 1]
#         skip_right = s[left: right]
#         return skip_left == skip_left[::-1] or skip_right == skip_right[::-1]
#       left += 1
#       right -= 1

#     return True
  
  
#   def isSpecialSequence(self, dna_sequence: str) -> str:

#     n = len(dna_sequence)

#     for i in range(1,n):
#       first = dna_sequence[:i]
#       second = dna_sequence[i:]
#       # print("first", first, "second", second)
#       # print("first", self.is_palindrome_after_remove(first), "second",self.is_palindrome_after_remove(second))
#       if self.is_palindrome_after_remove(first) == self.is_palindrome_after_remove(second):
#         return "YES"

#     return "NO"

class Solution:
    def is_palindrome_after_remove(self, s: str) -> bool:
        """檢查字串移除最多一個字符後是否能形成迴文"""
        if len(s) <= 1:
            return True
            
        def can_form_palindrome(left, right, removed=False):
            while left < right:
                if s[left] != s[right]:
                    if removed:  # 已經移除過一個字符了
                        return False
                    # 嘗試移除左邊或右邊的字符
                    return (can_form_palindrome(left + 1, right, True) or 
                           can_form_palindrome(left, right - 1, True))
                left += 1
                right -= 1
            return True
            
        return can_form_palindrome(0, len(s) - 1)

    def isSpecialSequence(self, dna_sequence: str) -> str:
        n = len(dna_sequence)
        if n < 2:  # 字串長度必須至少為2才能分割
            return "NO"
            
        # 檢查所有可能的分割點
        for i in range(1, n):
            # 分割成兩個子字串
            first = dna_sequence[:i]
            second = dna_sequence[i:]
            
            # 檢查兩個子字串是否都能在移除最多一個字符後形成迴文
            if self.is_palindrome_after_remove(first) and self.is_palindrome_after_remove(second):
                return "YES"
        
        return "NO"
      
      
testString = "abcd"
solution = Solution()
# print(solution.is_palindrome_after_remove(testString))
# print(solution.isSpecialSequence(testString))


# Review Python

# Using the slice 
# [begin : end]
# -> Include beginning index, not include ending index

# exampleString = "abcdef"
# length = len(exampleString)
# print("size of : ", length)
# lastCharacter = exampleString[length - 1]
# print("Last character is: ", lastCharacter, "Index is : ", length - 1)
# print("How's the [1:5]? Is the same with bcde? ", exampleString[1:5])

# for loop review
# for i in range(1, length):
#   print(exampleString[i])
  
  # Answer b c d e f



def can_form_palindrome_by_removing_one_char(s: str) -> bool:
    # Helper function to check if a string is palindrome
    def is_palindrome(substring: str) -> bool:
        return substring == substring[::-1]

    # Iterate through each character in the string
    for i in range(len(s)):
        # Form a new string by removing the i-th character
        new_string = s[:i] + s[i+1:]
        print("string", new_string)
        # Check if the new string is a palindrome
        if is_palindrome(new_string):
            return True

    # If no possible palindrome formation by removing one character
    return False

# Example usage:
s = "abcad"
print(can_form_palindrome_by_removing_one_char(s))  # Output should be True


