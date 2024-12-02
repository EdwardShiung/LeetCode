'''
/*
Given an array of strings words and a width maxWidth, 
format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; 
that is, pack as many words as you can in each line. Pad extra spaces ' ' 
when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line does not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", 
because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth


*/


'''

class Solution:
    def fullJustify(self, words: List[str],  maxWidth: int) -> List[str]:
        # Get the results
        res = []
        line = []
        length = 0
        index  = 0
        
        while(index < len(words)):
            
            # line complete
            '''
            1. 判斷完成：
                當前line 字母字數 + 下一個英文字 > maxWidth 
                    --> 將 "當前 line 字母字數"
            2. 加上 space
                - 平均加上
                - greedy 加上
            '''
            if length + len(line) + len(words[index]) > maxWidth:
                # 加上 space
                extrace_space = maxWidth - length
                # 平均加上
                space = extrace_space // max(1, len(line) - 1)
                # 多出格子
                reminder = extrace_space % max(1, len(line) - 1)
                
                for j in range(max(1, len(line) - 1)):
                    line[j] += " " * space
                    if reminder:
                        line[j] += " "
                        reminder -= 1
                
                res.append("".join(line))
                # Reset
                # 可以開始進行下一行
                # 進行前，要清空
                line = []
                length = 0
                

            # Line non-complete
            '''
            一行一行處理：
            這部分是指，當這一行字數，小於 maxWidth，就繼續編輯這一行
            '''
            line.append(words[index])
            # 單字進去後，計算一下這個單字的長度
            length += len(words[index])
            # index 移動
            index += 1
            
        # 最後一行處理
        last_line = " ".join(line)
        trail_space = maxWidth - len(last_line)
        res.append(last_line + " " * trail_space)
        
        # 返回結果
        return res
    



        
            