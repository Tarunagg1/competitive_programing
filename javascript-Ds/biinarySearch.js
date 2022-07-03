let arr = [1,2,3,4,5,6,7,8,9];


const binarySearch = (arr,num) =>{
    let min = 0;
    let max = arr.length;

    while (min <= max) {
        let mid = Math.floor((min+max) / 2);

        if(arr[mid] === num){
            return mid;
        }
        else if(arr[mid] < num){
            min = mid + 1;
        }else[
            max = mid - 1,
        ]
    }
    return -1;
}


console.log(binarySearch(arr,4));
