#include <iostream>
#include <vector>

/*

    常見的三種哈希結構
    1. Array
    2. Set (集合)
    3. Map (映射)

    --> 常見的三種哈希結構上，如果討論的資料量，是限定範圍，請優先選擇 Array
        --> 常見的題型， Leetcode 242 有效的字母異位詞

    在 C++ 中, set 和 map 分別提供三種數據結構，其底層實現及優劣如下：

    |     集合        |   底層實現    |   是否有序    | 數值是否可以重複 | 能否更改數值 | 查詢效率 | 增刪效率 | 
      std::set            紅黑樹         有序           不可重複         不可修改      O(logN)   O(logN)
    std:multiset          紅黑樹         有序            可重複          不可修改     O(logN)   O(logN)
    std::unordered_set    哈希表         無序           不可重複         不可修改       O(1)      O(1)
 
    1. 當需要使用集合來解決問題時，優先使用 unordered_set，因為它的查詢和增刪效率是最優的。
    2. 如果需要集合是有序的，請用 set
    3. 如果需要集合，不僅有序，且還要重複，請用 multiset


    |     映射        |   底層實現    |   是否有序    | 數值是否可以重複 | 能否更改數值 | 查詢效率 | 增刪效率 | 
      std::map            紅黑樹         key有序        key不可重複      key不可修改  O(logN)   O(logN)
    std:multimap          紅黑樹         key有序         key可重複      key不可修改  O(logN)   O(logN)
    std::unordered_map    哈希表         key無序        key不可重複     key不可修改    O(1)      O(1)

    1. map 對 key 有限制，對 value 沒限制 （因為 Key 的儲存方式，是用紅黑樹所組成）

    總結：
    1. 雖然 std::set 和 std::multiset 都是由紅黑樹所組成，但是使用方法，還是Hash Method的使用。
    --> 利用 key 找尋 value
    2. Hash Method 使用時機：
        - 當需要快速判斷一個元素，是否出現集合理的時候，請考慮 Hash Method
            --> 換言之，判斷一個元素，是否出現過的場景，第一時間請想到 Hash Method



    [使用方式]
    1. include 標準庫
        --> include <unordered_set>
            using std::unordered_set;

        --> include <unordered_map>
            using std::unordered_map

    2. Initialize that
        Ex:
        --> unordered_set<int>
        Ex: 
        --> unordered_map<int,int>

    ps. 為什麼需要 std:: 前綴？
        C++ 標準庫中的所有內容都在 std 命名空間中定義。這樣的設計是為了避免名字衝突。
        如果不使用命名空間，標準庫中的類型和函數，可能會與使用者自定義的類型和函數發生衝突！

        因此 #include<unordered_set> 僅僅只是引入頭文件，還需要使用特定命名空間來讓電腦區分。

        如果，使用者不介意命名空間污染(標準庫及自定義衝突)，可以使用 using namespace std; 此為通用寫法。

*/
