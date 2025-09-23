using System;

namespace MyApp;

class Program4 {
    public static void calculator() {
        
        double num1, num2;
        char operation;

        Console.WriteLine("--------------------------");
        Console.WriteLine("Welcome to the Calculator!");
        Console.WriteLine("--------------------------");

        Console.WriteLine("Enter first number: ");
        num1 = Convert.ToDouble(Console.ReadLine());
        Console.WriteLine("Enter an operator (+, -, *, /, !, ^, %, s (sqrt)): ");
        operation = Convert.ToChar(Console.ReadLine());
        if(operation == 's') {
            Console.WriteLine("Square root of " + num1 + " is: " + sqrt(num1));
            return;
        } else if (operation == '!') {
            Console.WriteLine("Factorial of " + (int)num1 + " is: " + factorial((int)num1));
            return;
        }
        Console.WriteLine("Enter second number: ");
        num2 = Convert.ToDouble(Console.ReadLine());

        switch (operation) {
            case '+':
                Console.WriteLine($"{num1} + {num2} = " + add((int)num1, (int)num2));
                break;
            case '-':
                Console.WriteLine($"{num1} - {num2} = " + subtract((int)num1, (int)num2));
                break;
            case '*':
                Console.WriteLine($"{num1} * {num2} = " + multiply((int)num1, (int)num2));
                break;
            case '/':
                Console.WriteLine($"{num1} / {num2} = " + divide((int)num1, (int)num2));
                break;
            case '^':
                Console.WriteLine($"{num1} ^ {num2} = " + power((int)num1, (int)num2));
                break;
            case '%':
                Console.WriteLine($"{num1} % {num2} = " + mod((int)num1, (int)num2));
                break;
            default:
                Console.WriteLine("Invalid operator.");
                break;
        }
    }

    public static int add(int a, int b) {
        return a + b;
    }

    public static int subtract(int a, int b) {
        return a - b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }

    public static double divide(int a, int b) {
        if (b == 0) {
            Console.WriteLine("Error: Division by zero.");
            return double.NaN;
        }
        return (double)a / b;
    }

    public static int factorial(int n) {
        if (n < 0) {
            Console.WriteLine("Error: Factorial of a negative number.");
            return -1;
        }
        if (n == 0 || n == 1) {
            return 1;
        }

        int result = 1;

        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static int power(int baseNum, int exponent) {
        if (exponent < 0) {
            Console.WriteLine("Error: Negative exponent not supported.");
            return -1;
        }

        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= baseNum;
        }
        return result;
    }

    public static int mod(int a, int b) {
        if (b == 0) {
            Console.WriteLine("Error: Modulus by zero.");
            return -1;
        }
        return a % b;
    }

    public static double sqrt(double x) {
        if (x < 0) {
            Console.WriteLine("Error: Square root of a negative number.");
            return double.NaN;
        }
        double left = 0, right = x, mid = 0;

        while (right - left > 1e-10) {
            mid = (left + right) / 2;
            if (mid * mid < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return mid;
    }
}
