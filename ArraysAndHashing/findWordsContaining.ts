function findWordsContaining(words: string[], x: string): number[] {
    return words.map((w, i) => w.includes(x) ? i : -1).filter((x) => x !== -1)
}
