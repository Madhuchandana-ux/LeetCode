class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // Min-heap to store pairs of {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& p : mp) {
            // p.second is frequency, p.first is the element
            minHeap.push({p.second, p.first});
            
            // Keep only the top k elements in the heap
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Extract the elements from the heap into the result vector
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};