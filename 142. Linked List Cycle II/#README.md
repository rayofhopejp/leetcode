
# 142.Linked List Cycle II

```cpp

/**

* Definition for singly-linked list.

* struct ListNode {

* int val;

* ListNode *next;

* ListNode(int x) : val(x), next(NULL) {}

* };

*/

```

# step 1

何も見ないで問題を解いた。3.7分。
```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        auto now = head;
        while(now != nullptr) {
            if(visited.find(now) != visited.end()) {
                return now;
            }
            visited.insert(now);
            now = now->next;
        }
        return nullptr;
    }
};
```
Can you solve it using `O(1)` (i.e. constant) memory?
とあるので定数解法を考える。floyd の循環検知を使えばできそう
Wikipedia を見てから実装。8.5分。
https://ja.wikipedia.org/wiki/%E3%83%95%E3%83%AD%E3%82%A4%E3%83%89%E3%81%AE%E5%BE%AA%E7%92%B0%E6%A4%9C%E5%87%BA%E6%B3%95
```cpp

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while(fast != nullptr) {
            if(fast->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
```
# step2
他の人のコードを見る
- https://github.com/konnysh/arai60/pull/2/files
- https://github.com/tarinaihitori/leetcode/pull/2
- https://github.com/rinost081/LeetCode/pull/4
- https://github.com/codgas/leetcode/pull/2
- https://github.com/h1rosaka/arai60/pull/4
- https://github.com/hroc135/leetcode/pull/2
- https://github.com/Mike0121/LeetCode/pull/38
- https://github.com/hrkh/leetcode/pull/3
- https://github.com/ask-1407/leetcode/pull/4
- https://github.com/kazukiii/leetcode/pull/3
- https://github.com/seal-azarashi/leetcode/pull/2
- https://github.com/goto-untrapped/Arai60/pull/22
- https://github.com/colorbox/leetcode/pull/18
floyd の探索法で書くときは、一般的なアルゴリズムでないのでコメントがあるといいかもしれないと思った。
また、前半と後半のコードを関数に分けるとわかりやすいと思った。
set のほうが一般的ということで、今回は set の方のコードを改良した。
if, while の後に空白をつけるなどのいくつかのスタイルを変更した。
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        auto now = head;
        while (now) {
            if (visited.find(now) != visited.end()) {
                return now;
            }
            visited.insert(now);
            now = now->next;
        }
        return nullptr;
    }
};
```

## Step3
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        auto now = head;
        while (now) {
            if (visited.find(now) != visited.end()) {
                return now;
            }
            visited.insert(now);
            now = now->next;
        }
        return NULL;
    }
};
```