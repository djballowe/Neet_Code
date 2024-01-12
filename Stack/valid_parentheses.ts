const valid = (s: string): boolean => {
    const stack = [s[0]]
    for (let i = 1; i < s.length; i++) {
        if (s[i] === ')' && stack[stack.length - 1] ! === '(') {
            return false
        } else if (s[i] === '}' && stack[stack.length - 1] ! === '{') {
            return false
        } else if (s[i] === ']' && stack[stack.length - 1] ! === '[') {
            return false
        } else {
            stack.push(s[i])
        }
    }
    return true
}

// (())
// (
