let arr = [1, 2, 3, 4];
let arr2 = [1, 4, 9, 16];




const isSquareCheck = (arr1, arr2) => {
    for (let index = 0; index < arr1.length; index++) {

        let isSquare = false;

        for (let i = 0; i < arr2.length; i++) {
            if (arr1[index] * arr1[index] === arr2[i]) {
                isSquare = true;
            }
            if (i === arr2.length - 1) {
                if (!isSquare) {
                    return false;
                }
            }
        }

    }
    return true;
}

const isSquareCheckBetter = (arr1, arr2) => {
    let map1 = {};
    let map2 = {};

    for (let item of arr1) {
        map1[item] = map1[item] ? map1[item] + 1 : 1;
    }

    for (let item of arr2) {
        map2[item] = map2[item] ? map2[item] + 1 : 1;
    }

    for (key in map1) {
        if (!map2[key * key]) {
            return false;
        }

        if (map1[key] !== map2[key * key]) {
            return false;
        }
    }
    return true;
}





console.log(isSquareCheck(arr, arr2));
console.log(isSquareCheckBetter(arr, arr2));

