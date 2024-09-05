class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n < 2:
            return 0
        
        isPrime = [False] * n
        count = 0

        for num in range(2,n):
            if isPrime[num]:
                continue
            count+=1
            for mult in range(num*num, n, num):
                isPrime[mult] = True
        
        return count  

def test_countPrimes():
    sol = Solution()

    # Test case 1: n = 0
    if sol.countPrimes(0) == 0:
        print("Test case 1 passed.")
    else:
        print("Test case 1 failed.")

    # Test case 2: n = 1
    if sol.countPrimes(1) == 0:
        print("Test case 2 passed.")
    else:
        print("Test case 2 failed.")

    # Test case 3: n = 2
    if sol.countPrimes(2) == 0:
        print("Test case 3 passed.")
    else:
        print("Test case 3 failed.")

    # Test case 4: n = 10 (Primes: 2, 3, 5, 7)
    if sol.countPrimes(10) == 4:
        print("Test case 4 passed.")
    else:
        print("Test case 4 failed.")

    # Test case 5: n = 100 (Primes: 25 primes below 100)
    if sol.countPrimes(100) == 25:
        print("Test case 5 passed.")
    else:
        print("Test case 5 failed.")

    # Test case 6: n = 5000
    if sol.countPrimes(5000) == 669:
        print("Test case 6 passed.")
    else:
        print("Test case 6 failed.")

# Running the test
test_countPrimes()
