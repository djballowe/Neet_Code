function generateParenthesis(n: number): string[] {
    let stack: string[] = [];
    let ans: string[] = [];

    const backTrack = (open: number, closed: number) => {
        if (open === n && closed === n) {
            ans.push(stack.join(''));
            return;
        }
        if (open < n) {
            stack.push('(');
            backTrack(open + 1, closed);
            stack.pop()
        }
        if (open > closed) {
            stack.push(')');
            backTrack(open, closed + 1);
            stack.pop()
        }
    }
    backTrack(0, 0);
    return ans;
}
