/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    let isPrime = new Uint8Array(n), count = 0
    for(let i = 2; i < n; i++){
        if(isPrime[i]) continue
            count++;
            for(let j = i*i; j < n; j+=i)
                isPrime[j] = 1
    }
    return count
};

function testCountPrimes() {
    // Test case 1: n = 0
    if (countPrimes(0) === 0) {
        console.log("Test case 1 passed.");
    } else {
        console.log("Test case 1 failed.");
    }

    // Test case 2: n = 1
    if (countPrimes(1) === 0) {
        console.log("Test case 2 passed.");
    } else {
        console.log("Test case 2 failed.");
    }

    // Test case 3: n = 2
    if (countPrimes(2) === 0) {
        console.log("Test case 3 passed.");
    } else {
        console.log("Test case 3 failed.");
    }

    // Test case 4: n = 10 (Primes: 2, 3, 5, 7)
    if (countPrimes(10) === 4) {
        console.log("Test case 4 passed.");
    } else {
        console.log("Test case 4 failed.");
    }

    // Test case 5: n = 100 (Primes: 25 primes below 100)
    if (countPrimes(100) === 25) {
        console.log("Test case 5 passed.");
    } else {
        console.log("Test case 5 failed.");
    }

    // Test case 6: n = 5000
    if (countPrimes(5000) === 669) {
        console.log("Test case 6 passed.");
    } else {
        console.log("Test case 6 failed.");
    }
}

// Running the test
testCountPrimes();
