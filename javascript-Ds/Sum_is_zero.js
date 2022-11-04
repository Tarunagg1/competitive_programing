let arr = [-5, -4, -3, -2, 0, 2, 4, 6, 8];

const getSumPairZero = (arr) => {
    for (let index = 0; index < arr.length; index++) {
        for (let j = 1; j <= arr.length; j++) {
            const currEle = arr[index];
            if (currEle + arr[j] === 0) {
                return [currEle, arr[j]];
            }
        }
    }
}


const betterSolution = (arr) => {
    let firstPointer = arr[0];
    let lastPointer = arr.length - 1;

    while (firstPointer < lastPointer) {
        sum = arr[firstPointer] + arr[lastPointer];
        if (sum === 0) {
            return [arr[firstPointer], arr[lastPointer]];
        }
        else if (sum > 0) {
            lastPointer--;
        } else {
            firstPointer++;
        }
    }
}

console.log(betterSolution(arr));