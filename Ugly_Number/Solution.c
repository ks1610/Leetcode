#include <stdio.h>
#include <stdbool.h>

bool isUgly(int n) {
    if(n <= 0)
        return false;
    while(n % 2 == 0)
        n /= 2;
    while(n % 3 == 0)
        n /= 3;
    while(n % 5 == 0)
        n /= 5;
    return n == 1;
}

int main() {
    int nums[] = {6, 8, 14, 1, 0, -5};
    int size = sizeof(nums)/sizeof(nums[0]);

    for(int i = 0; i < size; i++) {
        printf("%d -> %s\n", nums[i], isUgly(nums[i]) ? "True" : "False");
    }

    return 0;
}
