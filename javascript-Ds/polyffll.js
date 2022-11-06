let arr = [1, 2, 3, 4];



//// ForEach polyfill

Array.prototype.myEach = function (cb) {
    for (let index = 0; index < this.length; index++) {
        cb(this[index], index)
    }
}


// map pollyfill

Array.prototype.myMap = function (cb) {
    let arr = [];
    for (let index = 0; index < this.length; index++) {
        arr.push(cb(this[index], index, this));
    }
    return arr;
}

// reduce pollyfill

Array.prototype.myReduce = function (cb, initial) {
    let accumulator = initial;

    for (let index = 0; index < this.length; index++) {
        if (accumulator) {
            accumulator = cb(accumulator, this[index], index, this);
        } else {
            accumulator = this[index];
        }
    }
    return accumulator;
}

// filter pollyfill

Array.prototype.myFilter = function (cb) {
    let temp = [];
    for (let index = 0; index < this.length; index++) {
        if (cb(this[index], i, this)) temp.push(this[index]);
    }
    return temp;
}

// let final = arr.filter((p,c) => p > 2);


// console.log(final);


// call apply  bind
let obj = {
    name: "tarun",
    printName: function (age, address) {
        console.log(`namne: ${this.name}  age ${age} address ${address}`);
    }
}

let obj2 = {
    name: "arun"
}

// obj.printName.call(obj2, 10, "call");
// obj.printName.apply(obj2, [10, "apply"]);
// let bindFun = obj.printName.bind(obj2, 10, "bind");
// bindFun();


/// dbouncing
const getData = () => {
    console.log('getting data for you');
}
const dBounce = (cb, time) => {
    let timer;
    return function (...args) {
        if (timer) {
            clearTimeout(timer);
        }
        timer = setTimeout(() => {
            cb();
        }, time)
    }
}

const dBounceFunction = dBounce(getData, 3000)


//// flattan array
let flattenArrData = [1, 2, [3, 4, 5], [6, 7, 8], 9, [10]];

const flattenArr = (oldArr) => {
    let flatArr = [];
    oldArr.forEach(ele => {
        if (Array.isArray(ele)) {
            flatArr = flatArr.concat(flattenArr(ele))
        } else {
            flatArr.push(ele);
        }
    })

    return flatArr;
}


const re = arr.myMap((ele, i) => {
    return ele * 3
})

console.log(re);