
# フィードバックを受けての書き直し
ListNode の定義
```
/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x) : val(x), next(NULL) {}
* };
*/
```
フィードバックを要約するとこのようなことが言われていました。
- マジックナンバーは行儀が悪い（制約をまもらない入力が来たときに想定外の結果が得られることに対して）
- 入力を破壊するのが行儀が悪い
- Google Style Guide に沿ってみると読みやすい

さらに、直近3人のgithub から以下のような示唆が得られました
- floydの循環検出
- set で解く方法、その計算量

まずは floyd の循環検出で解いてみる。
slow と fast を使うことだけ覚えて自分で書いた。3分程度かかった。
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        while(fast != nullptr) {
            if(fast->next == nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;  
            if(fast == slow) return true;      
        }
        return false;
    }
};
```
時間計算量は O(頂点の数)、空間計算量は O(1)だと思った。
調べると時間計算量は最大でO(サイクルに到達するまでの頂点数+サイクルの頂点数)。
サイクルがあると仮定すると、slow がサイクルに到達したとき、fast との距離はサイクルの頂点数以下であり、その距離は早さの差である1ずつ縮まっていくから。

set を使う開放で解いてみる。
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode *now = head;
        while(now != nullptr) {
            if(visited.find(now) != visited.end())return true;
            visited.insert(now);
            now = now->next;
        }
        return false;
    }
};
```
時間計算量は、N = サイクルまでの頂点数+サイクルの頂点数 とすると、O(NlogN)、空間計算量は O(N)だと思った。
set.find() や set.insert() の時間計算量は set.size() について対数時間なので。
https://cpprefjp.github.io/reference/set/set/find.html
https://cpprefjp.github.io/reference/set/set/insert.html

unordered_set （格納順が規定されていないコンテナ）使ったら微妙に早くなった気がする。
https://cpprefjp.github.io/reference/unordered_set/unordered_set/find.html によると、unordered_set.find() は
-   平均： 定数時間
-   最悪：  size() について線形時間

ハッシュテーブルを使っているのでこのようになる。最悪の時はキーのハッシュ値が衝突しまくるとき？
ただのsetは一般的に、二分木として実装されるので、対数時間になる。
https://cpprefjp.github.io/reference/set/set.html