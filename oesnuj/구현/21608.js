const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
//입력 데이터 정리
const N = +input.shift();
const students = input.map(x => {
	const [num, ...likes] = x.trim().split(' ').map(Number);
	return { num, likes };
});

let board = Array.from({ length: N }, () => Array(N).fill(0));

const dr = [-1, 1, 0, 0];
const dc = [0, 0, -1, 1];

main();

function main(){
	for(let i=0; i< N**2; i++){
		if(i == 0){
			board[1][1] = students[i].num; //첫학생은 1,1에 무조건 앉는다.
			continue;
		}
		choiceSeat(students[i].num); //학생을 조건에 맞게 앉히기
	}
	console.log(calcSatisfy()); //모두 앉은 후 만족도 계산하기
}

// 최적의 자리 선택 및 학생 배치 함수
function choiceSeat(studentNum){
	const neighborInfos = []; //인접 자리 정보를 모으는 배열
	for(let i = 0; i<N; i++){
		for(let j =0; j<N; j++){
			if(board[i][j] !== 0) continue; //이미 차있는 자리 패스
			neighborInfos.push(getSeatInfo(i, j, studentNum));
		}
	}
	neighborInfos.sort((a, b) => {
		if (a.match !== b.match) {
			return b.match - a.match; // match 기준 내림차순 정렬
		} else if (a.empty !== b.empty) {
			return b.empty - a.empty; // empty 기준 내림차순 정렬
		} else if (a.r !== b.r) {
			return a.r - b.r; // r 기준 오름차순 정렬
		} else {
			return a.c - b.c; // c 기준 오름차순 정렬
		}
	});
	board[neighborInfos[0].r][neighborInfos[0].c] = studentNum; //최적의 위치에 앉히기
}

// 특정 자리의 인접 정보 계산 함수
function getSeatInfo(r, c, studentNum){
	let empty = 0;
	let match = 0;
	// 학생 번호에 맞는 좋아하는 학생들 찾기
	let studentLikes = students.find(student => student.num === studentNum)?.likes || [];
	for(let i = 0; i< 4; i++){
		nr = r + dr[i];
		nc= c + dc[i];
		if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (board[nr][nc] == 0) empty++;
		else if(studentLikes.includes(board[nr][nc])) match++
	}
	return { r: r, c: c, empty: empty, match: match };
}

//만족도 처리
function calcSatisfy(){
	let result = 0;
	for(let i = 0; i<N; i++){ //남아있는 모든 자리의 정보를 수집
		for(let j =0; j<N; j++){
			result += Math.floor(10 ** (getSeatInfo(i, j ,board[i][j]).match-1));
		}
	}
	return result;
}