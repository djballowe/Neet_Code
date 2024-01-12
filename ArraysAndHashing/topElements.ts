// right child 2 * i + 1
// left child 2 * i

type HeapNode = {
  num: number;
  freq: number;
};

class Heap {
  heap: any[];
  constructor() {
    this.heap = [0];
  }
  insert(node: HeapNode) {
    this.heap.push(node);
    let i = this.heap.length - 1;
    while (this.heap[i].freq > this.heap[Math.floor(i / 2)].freq) {
      let temp = this.heap[i];
      this.heap[i] = this.heap[Math.floor(i / 2)];
      this.heap[Math.floor(i / 2)] = temp;
      i = Math.floor(i / 2);
    }
  }
  pop() {
    if (this.heap.length === 2) return this.heap.pop();
    let ans = this.heap[1];
    this.heap[1] = this.heap.pop() as HeapNode;
    let i = 1;
    while (2 * i < this.heap.length) {
      if (
        i * 2 + 1 < this.heap.length &&
        this.heap[i * 2 + 1].freq > this.heap[i * 2].freq &&
        this.heap[i].freq < this.heap[i * 2 + 1].freq
      ) {
        let temp = this.heap[i];
        this.heap[i] = this.heap[i * 2 + 1];
        this.heap[i * 2 + 1] = temp;
        i = i * 2 + 1;
      } else if (this.heap[i].freq < this.heap[i * 2].freq) {
        let temp = this.heap[i];
        this.heap[i] = this.heap[i * 2];
        this.heap[i * 2] = temp;
        i = i * 2;
      } else {
        break;
      }
    }
    return ans;
  }
}

function topKFrequent(nums: number[], k: number): number[] {
  let hash = {};
  let ans: number[] = [];
  for (let i = 0; i < nums.length; i++) {
    hash[nums[i]] ? (hash[nums[i]] += 1) : (hash[nums[i]] = 1);
  }
  let heap = new Heap();
  for (let key in hash) {
    heap.insert({ num: parseInt(key), freq: hash[key] });
  }
    for (let i = 0; i < k; i++) {
        ans.push(heap.pop().num)
    }
    return ans;
}
