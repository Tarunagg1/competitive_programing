const calc = {
    total: 0,
    add(a) {
        this.total += a;
        return this;
    },
    multiply(a) {
        this.total *= a;
        return this;
    }
}

const result = calc.add(10).multiply(10);
console.log(result.total);