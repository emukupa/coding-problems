const array = [1, 2, 3, 4, 5, 6, 7, 8, 9];
console.log(array); // before zig zag
// start with a flag of true
// if flag is true then expected array[i] > array[i -1]
// else if flag false, we expect array[i] < array[i -1]
// otherwise swap

let flag = true;

for (let i = 1; i < array.length; i++) {
  if (flag === true && array[i] < array[i - 1]) {
    [array[i], array[i - 1]] = [array[i - 1], array[i]];
  } else if (flag === false && array[i] > array[i - 1]) {
    [array[i], array[i - 1]] = [array[i - 1], array[i]];
  }
  flag = !flag;
}

console.log(array); // after zig zag
