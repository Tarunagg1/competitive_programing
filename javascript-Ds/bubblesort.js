const bubbleSort = (array) => {
    for (let index = array.length; index >0 ; index--) {
        for(let j=0; j<index-1; j++){
            if(array[j] > array[j+1]){
                [array[j],array[j+1]] = [array[j+1],array[j]];
            }
        }
    }
    return array;
}

console.log(bubbleSort([9,8,7,6,5,4,3,2,1]));