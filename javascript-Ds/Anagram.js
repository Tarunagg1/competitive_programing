const isStringIsAnagram = (str1, str2) => {
    let n1 = str1.length;
    let n2 = str2.length;

    if (n1 !== n2) return false;
    let mapping = {};

    for (let letter of str1) {
        mapping[letter] = mapping[letter] ? mapping[letter] + 1 : 1;
    }
    
    for (let item of str2) {
        if (!mapping[item]) return false;
        mapping[item] -= 1;
    }

    return true;
}

console.log(isStringIsAnagram("helllo", "lllheo"));