let operands: { [key: string]: string } = {
    '*': '*',
    '/': '/',
    '+': '+',
    '-': '-',
};

function evalRPN(tokens: string[]): number {
    let stack: string[] = [];
    for (let i = 0; i < tokens.length; i++) {
        if (!operands[tokens[i]]) {
            stack.push(tokens[i]);
        } else {
            let x: number = parseInt(stack.pop() as string);
            let y: number = parseInt(stack.pop() as string);
            let z: number = 1;
            switch (tokens[i]) {
                case '+':
                    z = x + y;
                    break;
                case '-':
                    z = x - y;
                    break;
                case '*':
                    z = x * y;
                    break;
                case '/':
                    z = Math.trunc(x / y);
                default:
                    break;
            }
            stack.push(z.toString());
        }
    }
    return parseInt(stack[0]);
}
