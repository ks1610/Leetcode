function wordBreak(s, wordDict) {
    let dp = new Array(s.length + 1).fill(false);
    dp[0] = true;
    
    for(let i = 1; i <= s.length; i++){
        for(let w of wordDict){
            let start = i - w.length;
            if(start >= 0 && dp[start] && s.substring(start, i) === w){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.length];
}

// Test cases
const testCases = [
    { s: "leetcode", wordDict: ["leet", "code"], expected: true },
    { s: "applepenapple", wordDict: ["apple", "pen"], expected: true },
    { s: "catsandog", wordDict: ["cats", "dog", "sand", "and", "cat"], expected: false },
    { s: "", wordDict: [], expected: true },  // Edge case: empty string and empty wordDict
    { s: "a", wordDict: ["a"], expected: true },  // Single character match
    { s: "b", wordDict: ["a"], expected: false },  // Single character no match
    { s: "bb", wordDict: ["b", "bbb"], expected: true },  // Multiple character match
];

// Run tests
testCases.forEach((testCase, index) => {
    const { s, wordDict, expected } = testCase;
    const result = wordBreak(s, wordDict);
    console.log(`Test case ${index + 1}: ${result === expected ? 'Passed' : 'Failed'}`);
    console.log(`Input: s = '${s}', wordDict = ${JSON.stringify(wordDict)}`);
    console.log(`Expected: ${expected}, Got: ${result}`);
    console.log();
});
