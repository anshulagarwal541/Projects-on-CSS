let choice = document.querySelector('#number');
let one = document.querySelector('#one');
let two = document.querySelector('#two');
let reset = document.querySelector('#reset');
let countOne = 0;
let countTwo = 0;
let point1 = document.querySelector('#player1');
let point2 = document.querySelector('#player2');
let isGameOver = false;
let limit = 1;
choice.addEventListener('change', function () {
    limit=parseInt(this.value);
    again();
})
one.addEventListener('click', function () {
    if(!isGameOver)
    {
        countOne+=1;
        if(countOne===limit)
        {
            isGameOver=true;
            point1.classList.add('green');
            point2.classList.add('red');
        }
        point1.textContent=countOne;
    }
})
two.addEventListener('click', function () {
    if(!isGameOver)
    {
        countTwo+=1;
        if(countTwo===limit)
        {
            isGameOver=true;
            point2.classList.add('green');
            point1.classList.add('red');
        }
        point2.textContent=countTwo;
    }
})

reset.addEventListener('click', again);

function again() {
    countOne = 0;
    countTwo = 0;
    isGameOver = false;
    point1.textContent = 0;
    point2.textContent = 0;
    point2.classList.remove('green', 'red');
    point1.classList.remove('green', 'red');
}