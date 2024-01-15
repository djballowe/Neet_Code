class TreeNode {
    val: string;
    r: TreeNode | null;
    l: TreeNode | null;
    constructor(val: string) {
        this.val = val;
        this.r = null;
        this.l = null;
    }
}

class Tree {
    root: TreeNode | null;
    constructor() {
        this.root = null;
    }
    insert(node: TreeNode) {
        if (!this.root) {
            this.root = node;
        } else {
            let currNode = this.root;
            let count = 1;
            while (count !== currNode.val.length - 1) {
                if (node.val[count] === '(') {
                    currNode = currNode.l as TreeNode
                } else {
                    currNode = currNode.r as TreeNode
                }
                count++;
            }
            direction === 'l' ? currNode.l = node : currNode.r = node 
        }
        return node;
    }
}

function generateParenthesis(n: number): string[] {
    let tree = new Tree();
    let l: string[] = [];
    let r: string[] = [];
    for (let i = 0; i < n; i++) {
        l.push('(');
        r.push(')');
    }
    tree.insert({ prevNode: l.pop() as string, r: null, l: null });
    const fillTree = (l: string[], r: string[]) => {
        if (l.length) {
            l.pop();
            fillTree(l, r);
        } else if (r.length) {
            r.pop();
            fillTree(l, r);
        }
        return;
    };
    return ['hi'];
}
