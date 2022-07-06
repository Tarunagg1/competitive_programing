const selectionSort = (array) =>  {
    for (let index = 0; index < array.length; index++) {
        let min = index;
        for(let j=index+1; j < array.length; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        if(index !== min){
            let temp = array[index];
            array[index] = array[min];
            array[min] = temp;
        }
    }
    return array;
}


console.log(selectionSort([9, 8, 7, 6, 5, 4, 3, 2, 1]));

