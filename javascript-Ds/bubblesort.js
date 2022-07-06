const bubbleSort = (array) => {
    for (let index = array.length; index > 0; index--) {
        for (let j = 0; j < index - 1; j++) {
            if (array[j] > array[j + 1]) {
                [array[j], array[j + 1]] = [array[j + 1], array[j]];
            }
        }
    }
    return array;
}


const bubbleSortOptimization = (array) => {
    for (let index = array.length; index > 0; index--) {
        let isSwap = false;
        for (let j = 0; j < index - 1; j++) {
            if (array[j] > array[j + 1]) {
                isSwap = true;
                [array[j], array[j + 1]] = [array[j + 1], array[j]];
            }
        }
        if(!isSwap) {
            break;
        }
    }
    return array;
}


console.log(bubbleSortOptimization([9, 8, 7, 6, 5, 4, 3, 2, 1]));