const throattling = (cb, d) => {
    let last = 0;
    return (...args) => {
        const current = Date.now()
        if (current - last < d) return;
        last = current;
        return cb(...args);
    }
}