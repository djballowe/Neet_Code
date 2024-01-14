function largestRectangleArea(heights: number[]): number {
    let splitHeights: number[][] = [heights];
    let set: Set<number> = new Set();
    for (let i = 0; i < heights.length; i++) {
        set.add(heights[i]);
    }
    let stack: number[] = [...set].sort((a, b) => b - a);
    let area: number = stack[stack.length - 1] * heights.length;
    while (stack.length || !splitHeights.length) {
        let low = stack.pop() as number;
        let temp: number[][] = [];
        let found = false;
        for (let i = 0; i < splitHeights.length; i++) {
            for (let j = 0; j < splitHeights[i].length; j++) {
                if (
                    (splitHeights[i][j - 1] === low || j === 0) &&
                    splitHeights[i][j] !== low
                ) {
                    let sequence = fracture(j, splitHeights[i], low);
                    if (sequence.largest * sequence.section.length > area) {
                        temp.push(sequence.section);
                    }
                    found = true;
                }
            }
            if (!found && splitHeights[i].length) {
                temp.push(splitHeights[i]);
            }
            found = false;
        }
        for (let i = 0; i < temp.length; i++) {
            let segArea = getSeg(temp[i]);
            area = Math.max(area, segArea);
        }
        splitHeights = temp;
    }
    return area;
}

const getSeg = (seg: number[]): number => {
    return Math.min(...seg) * seg.length;
};

const fracture = (
    j: number,
    height: number[],
    low: number,
): { section: number[]; largest: number } => {
    let section: number[] = [];
    let largest = 0;
    while (height[j] !== low && j <= height.length - 1) {
        largest = Math.max(largest, height[j]);
        section.push(height[j++]);
    }
    return { section, largest };
};

let heights = [2, 1, 5, 6, 2, 3];
largestRectangleArea(heights);

// [2,2,6,2,2,3,3,4,5,7,3,6,2,3,3,4,5,6,3,3,2,3,15,17,18,20,8,3,9,3,2,3,3,1,5,6,7,20,20,3,3,4,2]
// [2,2,6,2,2,3,3,4,5,7,3,6,2,3,3,4,5,6,3,3]
// [2,1,5,6,2,3,3,5,6,7,2,2,2,3,3,3,7,8,9]
