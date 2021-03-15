int countOne(int arr[],int N){
    int low = 0;
    int high = n-1;
    while(low<high){
        int mid = (low +high) / 2;
        if(arr[mid] == 0){
            high = mid-1;
        }else{
            if(arr[mid+1] == 0 || mid == n-1){
                return mid+1;
            }else{
                low = mid+1;
            }
        }
    }
    return -1;
}