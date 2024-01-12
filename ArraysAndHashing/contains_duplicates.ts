function containsDuplicate(nums: number[]): boolean {
    let hash = {}
    for (let i = 0; i < nums.length; i++) {
        if (hash[nums[i]]) {
            return true
        }
        hash[nums[i]] = 0;
    }
    return false
}
