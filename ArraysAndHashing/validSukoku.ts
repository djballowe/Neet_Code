function isValidSudoku(board: string[][]): boolean {
    let hash = new Map()
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
            let num = parseInt(board[i][j])
            if (num) {
               let col =  hash.set(`col ${j} value ${num}`, num)
               let row = hash.set(`row ${i} value ${num}`, num)
               let box = hash.set(`box${3 * Math.floor(j / 3) + Math.floor(i / 3)} value ${num}`, num)
               if (hash.has(col) || hash.has(row) || hash.has(box)) {
                   return false
               }
               hash.set(col, num)
               hash.set(row, num)
               hash.set(box, num)
            }
        }
    }
    return true
}
