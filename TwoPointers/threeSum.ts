function threeSum(nums: number[]): number[][] {
    let sortNums = nums.sort((a, b) => a - b);
    let trip: number[][] = [];
    for (let i = 0; i < sortNums.length - 1; i++) {
        let y = i + 1;
        let z = sortNums.length - 1;
        if (i > 0 && sortNums[i] === sortNums[i - 1]) {
            continue;
        }
        while (y < z) {
            let sum = sortNums[i] + sortNums[y] + sortNums[z];
            if (sum === 0) {
                trip.push([sortNums[i], sortNums[y], sortNums[z]]);
                y++;
                while (nums[y] !== nums[y - 1] && y < z) {
                    y++;
                }
            } else {
                sum < 0 ? y++ : z--;
            }
        }
    }
    return trip;
}
