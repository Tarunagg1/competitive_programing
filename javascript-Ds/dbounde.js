const debouce = (cb, d) => {
    let timer;
    return (...args) => {
        if (timer) clearinterval(timer);
        timer = setInterval(() => {
            return cb(...args);
        }, d);
    }
}