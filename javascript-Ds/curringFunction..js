function sum(a) {
    return function (b) {
        if (b) return sum(a + b);
        return a;
    }
}


console.log(sum(10)(20)(30)());