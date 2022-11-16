const insertionSort = (array) => {
    for (let index = 1; index < array.length; index++) {
        let cur = array[index];
        let j = index - 1;
        while (j >= 0 && array[j] > cur) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = cur;
    }
    return array;
}


console.log(insertionSort([9, 8, 7, 6, 5, 4, 3, 2, 1]));

