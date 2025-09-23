using System;

namespace MyApp;

class Program2 {
    public static void guess() {
        
        Random random = new Random();
        bool playAgain = true;
        int min = 1;
        int max = 100;
        int guess;
        int number;
        int guesses;

        while (playAgain) {
            Console.WriteLine("------------------------------------");
            Console.WriteLine("Welcome to the Number Guessing Game!");
            Console.WriteLine("------------------------------------");
            
            number = random.Next(min, max + 1);
            guess = 0;
            guesses = 0;

            Console.WriteLine($"Guess a number between {min} and {max}:");

            while (guess != number) {
                string input = Console.ReadLine();
                if (int.TryParse(input, out guess)) {
                    guesses++;
                    if (guess < number) {
                        Console.WriteLine("Too low! Try again:");
                    } else if (guess > number) {
                        Console.WriteLine("Too high! Try again:");
                    } else {
                        Console.WriteLine($"Congratulations! You've guessed the number {number} in {guesses} attempts.");
                    }
                } else {
                    Console.WriteLine("Please enter a valid number:");
                }
            }

            Console.WriteLine("Do you want to play again? (yes/no)");
            string response = Console.ReadLine().ToLower();
            playAgain = response == "yes";
        }

    }
}
