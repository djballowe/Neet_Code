function dailyTemperatures(temperatures: number[]): number[] {
    let stack: number[][] = [];
    let ans: number[] = new Array(temperatures.length).fill(0);
    for (let i = 0; i < temperatures.length; i++) {
        while (stack.length && stack[stack.length - 1][0] < temperatures[i]) {
            let node = stack.pop() as number[];
            let index = node[1];
            ans[index] = i - index;
        }
        stack.push([temperatures[i], i]);
    }
    return ans;
}
