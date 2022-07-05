let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];


const findEvenNum = (arr) => {
    let result = [];

    const helperFunction = (inputArr) => {
        if (inputArr.length === 0) return;

        if (inputArr[0] % 2 == 0) {
            result.push(inputArr[0]);
        }

        helperFunction(inputArr.slice(1))

    }
    
    helperFunction(arr)
    return result;
}


console.log(findEvenNum(arr));
