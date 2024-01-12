function twoSum(numbers: number[], target: number): number[] {
        let h = numbers.length
        let l = 0
        while (h > l) {
            if (numbers[l] + numbers[h] > target) {
                h--;
            } else {
                l++
            }
        }
        return [l, h]
};
