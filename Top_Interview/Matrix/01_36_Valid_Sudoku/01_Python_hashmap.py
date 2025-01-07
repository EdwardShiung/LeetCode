'''
collections.defaultdict 可以被視為一種基於 hashmap 的資料結構。
它本質上是 Python 的 dict 的擴展，內部使用哈希表來存儲鍵值對。


defaultdict 與 dict 的關係
defaultdict 是 Python 標準字典 (dict) 的一個子類。
它的特點是當訪問一個不存在的鍵時，不會拋出 KeyError，而是根據初始化時提供的「工廠函數」來自動生成一個預設值。
defaultdict 屬於 hashmap
defaultdict 以及 Python 的字典 (dict) 內部都是基於哈希表實現的，特性如下：

時間複雜度：

查找、插入和刪除的平均時間複雜度是 O(1)。
哈希表透過哈希函數將鍵映射到內部的存儲槽位。
哈希函數：

鍵必須是可哈希的（immutable），例如數字、字串、元組等。
dict 和 defaultdict 都使用哈希值來定位存儲位置。
defaultdict 的特性：

與普通的字典相比，defaultdict 提供了當鍵不存在時的「自動初始化」功能，這讓它更適合處理需要動態新增鍵值的場景。


例子
普通 dict：

python
d = {}
d[1]  # KeyError: 因為鍵 1 不存在
defaultdict：

python
from collections import defaultdict

d = defaultdict(list)  # 預設值是一個空列表
print(d[1])  # 自動返回 [] 而不是拋出 KeyError
d[1].append(10)
print(d)  # defaultdict(<class 'list'>, {1: [10]})
為什麼它屬於 hashmap？
在你的例子中：
python
rows = collections.defaultdict(set)
每一個 rows[r] 實際上是利用哈希表快速存儲和檢索行號 r 對應的 set 集合。
因此，collections.defaultdict 是一個擴展了功能的 hashmap（或者說字典），特別適合像數獨驗證這種需要動態儲存鍵值的應用場景！

'''