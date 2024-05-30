var isPalindrome = function(s) {
    // Convert the string to lowercase and remove non-alphanumeric characters
    s = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
    
    let rev = "";
    // Construct the reversed string
    for (let i = s.length - 1; i >= 0; i--) {
        rev += s[i];
    }
    
    // Check if the original string is equal to the reversed string
    return rev === s;
};

// Test cases
const input1 = "A man, a plan, a canal: Panama";
const input2 = "race a car";
const input3 = "";
const input4 = " ";

console.log(`Input: "${input1}" => ${isPalindrome(input1) ? "Palindrome" : "Not a palindrome"}`);
console.log(`Input: "${input2}" => ${isPalindrome(input2) ? "Not a palindrome" : "Palindrome"}`);
console.log(`Input: "${input3}" => ${isPalindrome(input3) ? "Palindrome" : "Not a palindrome"}`);
console.log(`Input: "${input4}" => ${isPalindrome(input4) ? "Palindrome" : "Not a palindrome"}`);
