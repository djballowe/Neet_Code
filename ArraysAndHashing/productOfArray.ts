function productExceptSelf(nums: number[]): number[] {
  let ans: number[] = [];
  let product = 1;
  for (let i = 0; i < nums.length; i++) {
    product *= nums[i];
    ans.push(product);
  }
  let post = 1;
  for (let i = nums.length - 1; i >= 0; i--) {
    let pointer = i + 1 > nums.length - 1 ? 1 : nums[i + 1];
    post *= pointer;
    let pre = i - 1 < 0 ? 1 : ans[i - 1];
    ans[i] = pre * post;
  }
  return ans;
}
