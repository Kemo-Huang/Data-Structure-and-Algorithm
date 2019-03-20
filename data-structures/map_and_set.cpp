#include <unordered_set>
#include <utility>
#include <iostream>

using namespace std;

int main() 
{ 
    unordered_set<int> us; 
  
    us.insert(1); 
    us.insert(3); 
    us.insert(4); 
    us.insert(2); 
    us.insert(2); 
  
    cout << "Elements in unordered_set:\n"; 
    for (auto it : us) 
        cout << it << " "; // Sorted 
  
    return 0; 
} 