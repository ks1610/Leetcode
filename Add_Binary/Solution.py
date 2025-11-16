class Solution(object):
    def convert(self, a):
        if a == '1':
            return 1
        return 0  # FIXED

    def convert1(self, n):
        if n == 1:
            return '1'
        return '0'

    def addBinary(self, a, b):
        result = ""
        i = len(a) - 1
        j = len(b) - 1
        carry = 0

        while i >= 0 or j >= 0 or carry:
            x = self.convert(a[i]) if i >= 0 else 0
            y = self.convert(b[j]) if j >= 0 else 0

            sum1 = x + y + carry
            bit = sum1 % 2
            carry = sum1 // 2   # FIXED (integer division)

            result += self.convert1(bit)

            i -= 1
            j -= 1

        return result[::-1]

if __name__ == "__main__":
    sol = Solution()

    a1 = "11"
    b1 = "1"
    print("Input:", a1, b1)
    print("Output:", sol.addBinary(a1, b1))
    print()

    a2 = "1010"
    b2 = "1011"
    print("Input:", a2, b2)
    print("Output:", sol.addBinary(a2, b2))
