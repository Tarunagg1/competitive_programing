// Maximum number of events that can be attended 
// Medium Accuracy: 45.94% Submissions: 3277 Points: 4
// There are N events in Geek's city. You are given two arrays start[] and end[] denoting starting and ending day of the events respectively. Event i starts at start[i] and ends at end[i].
// You can attend an event i at any day d between start[i] and end[i] (start[i] ≤ d ≤ end[i]). But you can attend only one event in a day.
// Find the maximum number of events you can attend.

 

// Example 1:

// Input:
// N = 3
// start[] = {1, 2, 1}
// end[] = {1, 2, 2}
// Output:
// 2
// Explanation:
// You can attend a maximum of two events.
// You can attend 2 events by attending 1st event
// at Day 1 and 2nd event at Day 2.
// Example 2:
// Input:
// N = 3
// start[i] = {1, 2, 3}
// end[i] = {2, 3, 4} 
// Output :
// 3
// Explanation:
// You can attend all events by attending event 1
// at Day 1, event 2 at Day 2, and event 3 at Day 3.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function maxEvents() which takes an integer N and two arrays start[], and end[] of size N as input parameters and returns the maximum number of events that can be attended by you.


// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ start[i] ≤ end[i] ≤ 105 




class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // code here
       vector<pair<int,int>> v;

       for(int i = 0; i < N; i++)
           v.push_back({start[i],end[i]});
       
       sort(v.begin(),v.end());
       // sort all the meeting according to first and then second day
       
       priority_queue<int,vector<int>,greater<int>> pq; // min Heap
       int cnt = 0; // Max meetings
       int i = 0, d = 0;
       while(!pq.empty() || i < N){
           if(pq.size() == 0)
               d = v[i].first; // cheking if it is the first meeting
       
           while(i < N && v[i].first <= d)
               pq.push(v[i++].second);
           pq.pop();
           
           cnt++; // incrementing the max count
           d++; // incrementing the current day
           
           while(!pq.empty() && pq.top() < d) pq.pop();
       }
       return (cnt);
    }
};

























