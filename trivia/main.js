/*
 * For part 1
 */
// TODO: Add code to check answers to questionn
const corrDisplayMsg = document.querySelector("#correctMsg");
const incorrDisplayMsg = document.querySelector("#incorrectMsg");
let answered = false;
const wrongButtons = document.querySelectorAll('#wrong');
wrongButtons.forEach(element => {
    element.addEventListener('click', () => {
        // can only answer once
        if (answered == false) {
            element.style.backgroundColor = 'red';
            // element.textContent = "Incorrect";
            answered = true;
            incorrDisplayMsg.style.display = "block";
        }
    })
});
const correctButton = document.querySelector("#correct");
correctButton.addEventListener('click', function () {
    // can only answer once
    if (answered == false) {
        correctButton.style.backgroundColor = 'green';
        // correctButton.textContent = "Correct";
        answered = true;
        corrDisplayMsg.style.display = "block"
    }
});

/*
 * For part 2
 */
submitBtn = document.querySelector("#submit");
inputField = document.querySelector("input");
submitBtn.addEventListener('click', () => {
    if (inputField.value !== "" && inputField.value === "Rhubarb") {
        inputField.style.backgroundColor = 'green';
        document.getElementById("part2CorrectMsg").style.display = "block";
        document.getElementById("part2IncorrectMsg").style.display = "none";
    } else {
        document.getElementById("part2CorrectMsg").style.display = "none";
        document.getElementById("part2IncorrectMsg").style.display = "block";
        inputField.style.backgroundColor = "red"
    }
})