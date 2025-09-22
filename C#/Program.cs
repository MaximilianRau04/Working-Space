using System;

namespace MyApp;

class Program {
    static void Main(string[] args) {
        
        /**
        Console.WriteLine("Enter your name: ");
        String name = Console.ReadLine();

        Console.WriteLine("What is your age? ");
        int age = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Hello, " + name + "!");
        Console.WriteLine("You are " + age + " years old.");
        */

        Random random = new Random();
        int randomNumber = random.Next(1, 101);
        double num = random.NextDouble() * 100;

        Console.WriteLine("Your random number is: " + randomNumber);
        Console.WriteLine("Your random double is: " + num);

        Console.WriteLine("What day is today? ");
        string day = Console.ReadLine();
        
        switch (day.ToLower()) {
            case "monday":
                Console.WriteLine("It's Monday!");
                break;
            case "tuesday":
                Console.WriteLine("It's Tuesday!");
                break;
            case "wednesday":
                Console.WriteLine("It's Wednesday!");
                break;
            case "thursday":
                Console.WriteLine("It's Thursday!");
                break;
            case "friday":
                Console.WriteLine("It's Friday!");
                break;
            case "saturday":
                Console.WriteLine("It's Saturday!");
                break;
            case "sunday":
                Console.WriteLine("It's Sunday!");
                break;
            default:
                Console.WriteLine("That's not a valid day.");
                break;
        }

    }
}
