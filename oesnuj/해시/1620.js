const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');

const N = +input[0].split(' ')[0];
const pokemonList = input.slice(1, 1 + N);
const testList = input.slice(1 + N);

// 이름을 키로 하고 번호를 값으로 하는 단일 Map 객체 생성
const pokemonMap = new Map();
pokemonList.forEach((pokemon, index) => {
    const number = index + 1;
    pokemonMap.set(pokemon, number);
});

let result = '';
testList.forEach(test => {
    if (!isNaN(test)) {
        // 테스트 값이 번호인 경우
        result += pokemonList[test - 1] + '\n'; // 번호에 해당하는 Pokémon 이름 추가
    } else {
        // 테스트 값이 이름인 경우
        result += pokemonMap.get(test) + '\n'; // 이름에 해당하는 Pokémon 번호 추가
    }
});
console.log(result);