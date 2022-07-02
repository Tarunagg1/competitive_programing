let arr = [1, 2, 3, 4, 5, 6, 7, 8];

const findConsucative = (array, num) => {
    if (num > array.length) {
        throw new Error("number exceeds")
    } else {
        let max = 0;
        for (let index = 0; index < array.length - num + 1; index++) {
            let temp = 0;
            for (let i = 0; i < num; i++) {
                temp += array[index + i];
            }
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }
}

console.log(findConsucative(arr, 4));