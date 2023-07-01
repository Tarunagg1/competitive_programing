const debouce = (cb, d) => {
    let timer;
    return (...args) => {
        if (timer) clearTimeout(timer);
        timer = setTimoeut(() => {
            return cb(...args);
        }, d);
    }
}

