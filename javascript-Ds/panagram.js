const checkIsPanagram = (str) => {
    const arr = new Array(26).fill(false);
    let idx;

    for (let index = 0; index < str.length; index++) {
        if (str[index] >= "A" && str[index] <= "Z") {
            idx = str.charCodeAt(index) - "A".charCodeAt(0);
        } else if (str[index] >= "a" && str[index] <= "z") {
            idx = str.charCodeAt(index) - "a".charCodeAt(0);
        } else {
            continue;
        }
        arr[idx] = true;
    }

    for (let index = 0; index < arr.length; index++) {
        if (arr[index] === false) return false;
    }
    return true;
}

console.log(checkIsPanagram("The quick brown fox jumps over the lazy dog"));