let arr = [4, 3, 2, 1];
let myNewList = [];
let i = 0;
let j = 1;


const isSortedArr = (arr) => {
    for (let index = 0; index < arr.length; index++) {
        if (arr[index] > arr[index + 1]) {
            return false;
        }
    }
    return true;
}

const sortCheck = (arr) => {
    if (isSortedArr(arr)) {
        myNewList = arr;
        return;
    }
    else if (arr[i] < arr[j]) {
        i++;
        j++;
        sortCheck(arr);
    } else {
        [arr[i], arr[j]] = [arr[j], arr[i]];
        i = 0;
        j = 1;
        sortCheck(arr);
    }
}

sortCheck(arr);
console.log(myNewList);
