var clockdiv = document.getElementById("clock");

const fillChar = "&#9632;";
const emptyChar = " ";
const delimiterChar = "  &#183;  ";
const paddingDigit = 2;

const line = [
  parseInt("10110111110000000000000000000000", 2) >> 0,
  parseInt("11111001110000000000000000000000", 2) >> 0,
  parseInt("11011111110000000000000000000000", 2) >> 0,
  parseInt("10110110110000000000000000000000", 2) >> 0,
  parseInt("10100010100000000000000000000000", 2) >> 0,
  parseInt("10001110110000000000000000000000", 2) >> 0,
  parseInt("00111110110000000000000000000000", 2) >> 0
]

var t = setInterval(clock, 1000);

function clock(){
  let currentdate = new Date();
  let time = ('0' + currentdate.getHours()).slice(-2) + ":" + ('0' + currentdate.getMinutes()).slice(-2) + ":" + ('0' + currentdate.getSeconds()).slice(-2);
  clockdiv.innerHTML = ""

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 8; j++) {
      if (time[j] != ":") {
        let digit = parseInt(time[j], 10)
        if (i % 4 == 0) {
          if (line[!i ? 0 : 3 * (3 - Math.floor(i / 4))] << digit < 0) {
            clockdiv.innerHTML += emptyChar + fillChar.repeat(3) + emptyChar;
          } else {
            clockdiv.innerHTML += emptyChar.repeat(5);
          }
        } else {
          if (line[5 - Math.floor(i / 4)] << digit < 0) {
            clockdiv.innerHTML += fillChar + emptyChar.repeat(3);
          } else {
            clockdiv.innerHTML += emptyChar.repeat(4);
          }
          if (line[1 + Math.floor(i / 4)] << digit < 0) {
            clockdiv.innerHTML += fillChar;
          } else {
            clockdiv.innerHTML += emptyChar;
          }
        }
        if (j < 7) {
          clockdiv.innerHTML += emptyChar.repeat(paddingDigit);
        }

      } else {
        clockdiv.innerHTML += delimiterChar;
      }
    }
    clockdiv.innerHTML += "<BR>"
  }
}
