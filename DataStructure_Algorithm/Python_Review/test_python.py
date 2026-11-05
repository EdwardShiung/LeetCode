import os,sys
def add(x, y):
    return x + y


def subtract(x, y):
    return x - y


def multiply(x, y):
    result = x * y
    return result


def divide(x, y):
    if y == 0:
        return None
    return x / y


class calculator:
    def __init__(self):
        pass

    def calculate(self, x, y, op):
        if op == "+":
            return add(x, y)
        elif op == "-":
            return subtract(x, y)
        elif op == "*":
            return multiply(x, y)
        elif op == "/":
            return divide(x, y)
        else:
            print("Invalid operation")


calc = calculator()
print(calc.calculate(10, 5, "+"))
print(calc.calculate(10, 5, "/"))
print(calc.calculate(10, 0, "/"))
print(calc.calculate(10, 5, "^"))
