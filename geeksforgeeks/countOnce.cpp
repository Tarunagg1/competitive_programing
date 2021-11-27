int countOnce(int arr[], int n){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == 0){
            if(arr[mid-1] == 1 || mid == 0){
                return mid;
            }else{
                high = mid-1;
            }
        }else{
            if(arr[mid+1] == 0 || mid == n-1){
                return mid+1;
            }else{
                low = mid+1;
            }
        }
    }
    return 0;
}