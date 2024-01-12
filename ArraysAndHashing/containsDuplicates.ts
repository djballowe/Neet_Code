function containsNearbyDuplicate(nums: number[], k: number): boolean {
    let hash = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (hash.has(nums[i]) && Math.abs(hash.get(nums[i]) - k)) {
            return true;
        } else {
            hash.set(nums[i], i);
        }
    }
    return false;
}
