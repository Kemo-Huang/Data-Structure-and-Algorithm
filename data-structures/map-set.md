# Map vs Set

- unique key
- set and map both use **Red Black Tree**
- the complexties of search, insert and delete are **O(log n)**.

## set 

- ordered key 
- comp(a, b) for comparing keys 

## map

- key and value
- ordered key 
- comp(a, b) for comparing keys 

## unordered_set

## unordered_map

## multiset

## multimap

## set<pair<>> vs map<>

```cpp
#include <utility>
#include <set>
#include <map>
using namespace std;
int main(){
    set<pair<int,int>> s; // same as unordered_set
    map<int,int> m; // same as unordered_map ...
    s.insert(make_pair(1,1));
    s.insert(make_pair(1,2));
    // s.size() = 2
    m.insert(make_pair(1,1));
    m.insert(make_pair(1,2));
    // m.size() = 1
}
```
## other usage

Scenario 1:

  - keep insertion order
  - no duplicate key
  - need frequency
  - sorted result
  
Use **map** and **vector/deque** together. First check if map contains key. If so, frequency + 1. If not, insert it to vector and map respectively.  
The **push_back** function of **vector** is much faster than **list**, **queue** or **deque** when there is **huge** number of elements to be pushed because each time it push back, it expends the memory size by half of its current size.  
When the number of elements to be pushed is not very large, **deque** is faster.  
[https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html](https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html)
