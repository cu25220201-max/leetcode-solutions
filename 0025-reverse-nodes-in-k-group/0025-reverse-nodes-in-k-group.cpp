class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = getKth(groupPrev, k);

            // Not enough nodes left
            if (kth == nullptr)
                break;

            // Save the next group's starting node
            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous part with reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;

            // Move groupPrev to the end of reversed group
            groupPrev = temp;
        }

        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {

        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }

        return curr;
    }
};