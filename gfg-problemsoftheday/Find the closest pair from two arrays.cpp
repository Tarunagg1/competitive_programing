

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
         int i=0,j=m-1,MIN_DIFF = INT_MAX;
        vector<int> INDEXES(2);
        while(i<n and j>=0)
        {
            int sum = arr[i] + brr[j];
            int DIFF = abs(sum-x);
            if(MIN_DIFF > DIFF)
            {
                INDEXES[0] = arr[i];
                INDEXES[1] = brr[j];
                MIN_DIFF = DIFF;
            }
            if(sum < x) i++;
            else j--;
        }
        return INDEXES;
    }
};