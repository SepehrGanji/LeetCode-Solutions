/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */
 
function deserialize(s: string): NestedInteger {
    let i = 0;
    return parse();
    
    function parse(): NestedInteger {
        // Case 1: integer
        if (s[i] !== '[') {
            let sign = 1;
            if (s[i] === '-') {
                sign = -1;
                i++;
            }

            let num = 0;
            while (i < s.length && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i].charCodeAt(0) - 48);
                i++;
            }

            return new NestedInteger(sign * num);
        }

        // Case 2: list
        i++; // skip '['
        const ni = new NestedInteger();

        while (s[i] !== ']') {
            ni.add(parse());
            if (s[i] === ',') i++; // skip comma
        }

        i++; // skip ']'
        return ni;
    }
}



