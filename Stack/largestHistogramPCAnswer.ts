type StackNode = {
    val: number;
    index: number;
};

function largestRectangleArea(heights: number[]): number {
    let stack: StackNode[] = [];
    let area: number = 0;

    for (let i = 0; i < heights.length; i++) {
        if (heights[i] < heights[i - 1] || !heights[i]) {
            let stop = heights[i];
            let unit: StackNode = stack[stack.length - 1];
            let j = 0;
            while (stack.length) {
                let currArea = 0;
                unit = stack[stack.length - 1] as StackNode;
                if (stop > unit.val) {
                    break;
                }
                stack.pop();
                currArea = unit.val * (i - unit.index);
                area = Math.max(currArea, area);
                j = unit.index;
            }
            stack.push({ val: heights[i], index: j });
        } else {
            stack.push({ val: heights[i], index: i });
        }
    }
    return area;
}
