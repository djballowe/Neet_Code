function longestConsecutive(nums: number[]): number {
    if (!nums.length) return 0;
    let hash = {};
    for (let i = 0; i < nums.length; i++) {
        hash[nums[i]] = i;
    }
    let count = 1;
    let largest = 1;
    for (let i = 0; i < nums.length; i++) {
        if (!(nums[i] - 1 in hash)) {
            let j = i;
            while ((nums[j] + 1) in hash) {
                j = hash[nums[j] + 1]
                count++;
            }
        }
        largest = Math.max(largest, count);
        count = 1;
    }
    return largest;
};
