/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let n = matrix[0].length, m = matrix.length;
    let left = 0;
    let right = (m * n) - 1;
    
    while(left <= right){
        let mid = parseInt((left + right) / 2);
        let mid_val = matrix[Math.floor(mid / n)][mid % n]

        if(mid_val === target)
            return true
        else if(mid_val < target)
            left = mid + 1;
        else 
            right = mid - 1; 
    }

    return false
};
