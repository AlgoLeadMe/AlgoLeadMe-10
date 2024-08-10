const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).toString().trim().split('\n');

let answer ="";
for(let i = 2; i < input.length; i += 2) {
    answer += calc(i) + "\n";
}
console.log(answer);

function calc(i){
    let stockFlow = input[i].split(' ').map(Number);
    let profit = 0;
    let maxPrice = 0;
    for(let j = stockFlow.length - 1; j >= 0; j--) {
        if (stockFlow[j] > maxPrice) {
            maxPrice = stockFlow[j];
        }
        profit += maxPrice - stockFlow[j];
    }
    return profit;
}