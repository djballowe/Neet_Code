const calPoints = (operations: string[]): number => {
    const stack = [];
    for (let i = 0; i < operations.length; i++) {
        let op = operations[i];
        if (typeof(op) === 'number') {
            stack.push(op)
        } else {
            switch (op) {
                case 'D':
                    stack[stack.length - 1] *= 2;
                case '+':
                    let n = stack.pop()
                    let m = stack.pop()
                    stack.push(m + n);
                case 'C':
                    stack.pop()
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < stack.length; i++) {
        ans += stack[i];
    }
    return ans;
}
