let arr = [
    [10, 20],
    [30, 40, [50, 60], 70],
    [80, 90, 100],
    [110, 120, [130, 140, 150]]
];

const customFlat = (arr, depth = 1) => {
    let result = [];
    arr.forEach(function (ar) {
        if (Array.isArray(ar) && depth > 0) {
            result.push(...customFlat(ar, depth - 1));
        } else {
            return result.push(ar);
        }
    });
    return result;
}


console.log(customFlat(arr, 2));



