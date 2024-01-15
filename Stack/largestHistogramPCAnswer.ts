type StackNode = {
    val: number;
    index: number;
};

function largestRectangleArea(heights: number[]): number {
    let stack: StackNode[] = [];
    let area: number = 0;

    for (let i = 0; i < heights.length; i++) {
        let currArea = 0;
        if (heights[i] < heights[i - 1]) {
            let unit = stack.pop() as StackNode;
            let val = unit.val;
            let j = i;
            while (val > heights[i - 1] && stack.length) {
                currArea += heights[j - 1] * (j - j) + 1;
                unit = stack.pop() as StackNode;
                val = unit.val as number;
                j = unit.index as number;
            }
            stack.push({ val: heights[i], index: j });
            console.log('newStack', stack);
            return 0;
        } else {
            stack.push({ val: heights[i], index: i });
        }
        console.log('stack', stack);
    }
    return 0;
}
