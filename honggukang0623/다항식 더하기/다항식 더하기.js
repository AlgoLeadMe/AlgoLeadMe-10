function solution(polynomial) {
    const values = polynomial.split(' + ');
    console.log("values : ", values);
    let x = 0;
    let c = 0;
    for(let i=0;i<values.length;i++) {
        const item = values[i];
        if(item[item.length-1] !== 'x') {
            c += Number(item);
        }
        else {
            // x일때
            const num = item.split('x')[0];
            if(num === '') {
                x += 1;
            } else {
                x += Number(num)
            }
        }
    }
    let answer = '';
    if(x === 1) {
        answer += 'x';
    }
    if(x > 1) {
        answer += `${x}x`;
    }
    
    if(x === 0 && c > 0) {
        answer += c;
    }
    else if(c > 0) {
        answer += ` + ${c}`;
    }
    return answer;
}
