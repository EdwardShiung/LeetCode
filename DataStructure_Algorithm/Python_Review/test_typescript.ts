let thin = 1

function add(a: number, b: number) {
    return a + b
}

function subtract(a: number, b: number) {
    return a - b;
}

const multiply = function(a: number, b: number) => {
    return a * b
};

const divide = (a: number, b: number): number | null => {
    if (b === 0) { return null }
    return a / b;
}
class calculator {
    name: string

    constructor(name: string) {
        this.name = name
    }

    calculate(a: number, b: number, op: string) {
        if (op == '+') return add(a, b);
        else
        if (op == '-') return subtract(a, b);
        else if (op == '*') { return multiply(a, b) }
        else if (op == '/') return divide(a, b)
        else
        console.log("Invalid op")
    }
}

colet thin = 1

function add(a: number, b: number) {
    return a + b
}

function subtract(a: number, b: number) {
    return a - b;
}

const multiply = function(a: number, b: number) => {
    return a * b
};

const divide = (a: number, b: number): number | null => {
    if (b === 0) { return null }
    return a / b;
}

class calculator {
    name: string

    constructor(name: string) {
        this.name = name
    }

    calculate(a: number, b: number, op: string) {
        if (op == '+') return add(a, b);
        else
        if (op == '-') return subtract(a, b);
        else if (op == '*') { return multiply(a, b) }
        else if (op == '/') return divide(a, b)
        else
        console.log("Invalid op")
    }
}

const calc = new calculator("MyCalc")
console.log(calc.calculate(10, 5, "+"))
console.log(calc.calculate(10, 0, "/"));
console.log(calc.calculate(10, 5, "^"))nst calc = new calculator("MyCalc")
console.log(calc.calculate(10, 5, "+"))
console.log(calc.calculate(10, 0, "/"));
console.log(calc.calculate(10, 5, "^"))
