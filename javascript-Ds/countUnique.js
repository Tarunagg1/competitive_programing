const countUniqueNumbers = (arr) => {
    if (arr.length > 0) {
        let i = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[i] !== arr[j]) {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;
    } else {
        throw new Error("Array is empty");
    }
}

console.log(countUniqueNumbers([9, 8, 7, 6, 5, 4, 3, 2, 1,10]));

// /var/www/html/latest_drupal/drupal/sites/all/themes/new_101_india_theme/templates
