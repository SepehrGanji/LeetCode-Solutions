const a_char = "a".charCodeAt(0);

function canConstruct(ransomNote: string, magazine: string): boolean {
    const ran_cnt: number[] = Array(26).fill(0);
    const mg_cnt: number[] = Array(26).fill(0);
    for(let char of ransomNote) {
        ran_cnt[char.charCodeAt(0) - a_char]++;
    }
    for(let char of magazine) {
        mg_cnt[char.charCodeAt(0) - a_char]++;
    }
    for(let i = 0 ; i < 26 ; i++) if(ran_cnt[i] > mg_cnt[i]) return false;
    return true;
};

