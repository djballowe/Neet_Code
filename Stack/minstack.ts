class MinStack {
  stack: number[];
  minStack: number[];
  min: number;
  head: number;
  new: number;

  constructor() {
    this.stack = [];
    this.minStack = [Infinity];
    this.head = this.stack[this.stack.length - 1];
  }

  push(val: number): void {
    let peak = this.minStack.length - 1;
    if (this.minStack[peak] > val || this.minStack[peak] === val) {
      this.minStack.push(val);
    }
    this.stack.push(val);
    this.head = val;
    console.log(this.minStack);
  }

  pop(): void {
    let pop = this.stack.pop();
    if (pop === this.minStack[this.minStack.length - 1]) {
      this.minStack.pop();
    }

    this.head = this.stack[this.stack.length - 1];
  }

  top(): number {
    return this.head;
  }

  getMin(): number {
    return this.minStack[this.minStack.length - 1];
  }
}
