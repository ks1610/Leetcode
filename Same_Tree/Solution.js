function TreeNode(val, left, right) {
      this.val = (val === undefined ? 0 : val);
      this.left = (left === undefined ? null : left);
      this.right = (right === undefined ? null : right);
 }
 
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if (p === null && q === null) {
        return true;
    }
    if (p === null || q === null || p.val !== q.val) {
        return false;
    }
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
};

// Helper function to create a binary tree from an array
function createTreeFromArray(arr, i = 0) {
    if (i >= arr.length || arr[i] === null) {
        return null;
    }

    let root = new TreeNode(arr[i]);
    root.left = createTreeFromArray(arr, 2 * i + 1);
    root.right = createTreeFromArray(arr, 2 * i + 2);
    return root;
}

// Test cases
let tree1 = createTreeFromArray([1, 2, 3]);
let tree2 = createTreeFromArray([1, 2, 3]);
let tree3 = createTreeFromArray([1, 2]);
let tree4 = createTreeFromArray([1, null, 2]);
let tree5 = createTreeFromArray([1, 2, 1]);
let tree6 = createTreeFromArray([1, 1, 2]);

console.log(isSameTree(tree1, tree2)); // Expected: true (trees are the same)
console.log(isSameTree(tree3, tree4)); // Expected: false (different structures)
console.log(isSameTree(tree5, tree6)); // Expected: false (different values)
console.log(isSameTree(null, null));   // Expected: true (both trees are null)
