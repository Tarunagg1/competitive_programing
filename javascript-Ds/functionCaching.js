function cacheFunction(fn, context) {
    let res = {};
    return function (...args) {
        let argsCache = JSON.stringify(args);
        if (!res[argsCache]) {
            res[argsCache] = fn.call(context || this, ...args);
        } else {
            return res[argsCache];
        }
    }
}

const calSqure = (num1, num2) => {
    for (let index = 0; index < 100000000; index++) { }
    return num1 + num2;
}

const advanceSum = cacheFunction(calSqure);

console.time('first call');
advanceSum(10, 20);
console.timeEnd('first call');



console.time('second call');
advanceSum(10, 20);
console.timeEnd('second call');
