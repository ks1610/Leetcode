/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

var multiply = function(num1, num2) {
    //return (BigInt(num1) * BigInt(num2)).toString()
    if (num1 === '0' || num2 === '0') return '0'
    
    const res = new Array(num1.length + num2.length).fill(0)

    for(let i = num1.length -1 ; i >= 0; i--){
        for(let j = num2.length -1 ; j >= 0; j--){
            const digi1 = i + j, digi2 = i + j + 1;
            let sum = res[digi2] + Number(num1[i]) * Number(num2[j])
            res[digi2] = sum%10
            res[digi1] += Math.floor(sum/10)
        }
    }
    if (res[0] === 0) res.shift()
    return res.join('')
};

// Example usage:
console.log(multiply('123', '456')); // 56088
console.log(multiply('123', '0')); // 0
console.log(multiply('123', '123')); // 15129
