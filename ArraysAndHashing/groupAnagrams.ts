function groupAnagrams(strs: string[]): string[][] {
    let ans = []
    let hash = {}
    for (let i = 0; i < strs.length; i++) {
        let sort = strs[i].split('').sort().join('')
        hash[sort] ? hash[sort].push(strs[i]) : hash[sort] = [strs[i]]
    }

    for (let key in hash) {
        ans.push(hash[key as keyof typeof hash])
    }
    return ans
}
