// Find anagrams in linked list
// MediumAccuracy: 81.88%Submissions: 3K+Points: 4
// Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

// Given a linked list of characters and a string S.Return all the anagrams of the string present in the given linked list.In case of overlapping anagrams choose the first anagram from left.

// Example 1:

// Input: a -> b -> c -> a -> d -> b -> c -> a
// S = bac
// Output: [a -> b -> c, b -> c -> a]
// Explanation: In the given linked list,
// there are three anagrams:
// 1. a -> b -> c -> a -> d -> b -> c -> a
// 2. a -> b -> c -> a -> d -> b -> c -> a
// 3. a -> b -> c -> a -> d -> b -> c -> a
// But in 1 and 2, a -> b -> c and b -> c-> a
// are ovelapping.So we take a -> b -> c as it
// comes first from left.So the output is:
// [a->b->c,b->c->a]
// Example 2:

// Input: a -> b -> d -> c -> a
// S = bac
// Output: -1
// Explanation: There is no anagrams, so output is -1
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findAnagrams() which takes head node of the linked list and a string S as input parameters and returns an array of linked list. If there is no anagram in the linked list,return -1.

// Expected Time Complexity: O(N), where N is length of LinkedList
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= |S| <= 105

// View Bookmarked Problems

class Solution
{
public:
    vector<Node *> findAnagrams(struct Node *head, string s)
    {
        // code here
        vector<Node *> ans;
        Node *start = head, *end = head;
        int n = s.length();

        // pattern string
        unordered_map<char, int> mp1;
        for (auto it : s)
            mp1[it]++;
        int count1 = mp1.size();

        // traversing string
        unordered_map<char, int> mp2;
        int count2 = 0;
        while (end != NULL)
        {
            mp2[end->data]++;
            if (mp1[end->data] == mp2[end->data])
                count2++;

            while (mp2[end->data] > mp1[end->data])
            {
                if (mp2[start->data] == mp1[start->data])
                    count2--;
                mp2[start->data]--;
                start = start->next;
            }

            if (count2 == count1)
            {
                ans.push_back(start);
                Node *ahead = end->next;
                end->next = NULL;
                start = ahead, end = ahead;
                mp2.clear();
                count2 = 0;
            }
            else
                end = end->next;
        }
        return ans;
    }
};
