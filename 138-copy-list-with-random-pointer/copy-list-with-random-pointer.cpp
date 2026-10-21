class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> oldToNew;
        
        // 1. First pass: Create a copy of each node (just the val) 
        // and map original node -> cloned node
        Node* curr = head;
        while (curr != nullptr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // 2. Second pass: Connect the next and random pointers using the map
        curr = head;
        while (curr != nullptr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        
        // Return the head of the new copied list
        return oldToNew[head];
    }
};