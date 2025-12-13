

function accountsMerge(accounts: string[][]): string[][] {
    const n = accounts.length;
    const mailtonode: Map<string, number> = new Map();
    const par = Array(n);
    for(let i = 0 ; i < n ; i++) par[i] = i;
    function find(i: number): number {
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }
    function union(i:number, j: number) {
        const ipar = find(i);
        const jpar = find(j);
        if(ipar == jpar) return;
        par[ipar] = jpar;
    }
    for(let i = 0 ; i < n ; i++) {
        for(let j = 1 ; j < accounts[i].length ; j++) {
            if(mailtonode.has(accounts[i][j])) union(i, mailtonode.get(accounts[i][j])!);
            else mailtonode.set(accounts[i][j], i);
        }
    }
    const nodetomails: Map<number, Set<string>> = new Map();
    for(let i = 0 ; i < n ; i++) nodetomails.set(i, new Set());
    for(let [mail, node] of mailtonode) {
        let p = find(node);
        nodetomails.get(p)!.add(mail);
    }
    const ans: string[][] = [];
    for(let [key, val] of nodetomails) {
        if(val.size < 1) continue;
        const sorted = [...val].sort();
        ans.push([accounts[key][0], ...sorted]);
    }
    return ans;
};

