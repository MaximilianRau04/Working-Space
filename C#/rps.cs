using System;

namespace MyApp;

class Program3 {
    public static void rps() {
        
        Random random = new Random();
        string[] choices = { "rock", "paper", "scissors" };
        bool playAgain = true;

        while (playAgain) {
            Console.WriteLine("------------------------------------------");
            Console.WriteLine("Welcome to the Rock, Paper, Scissors Game!");
            Console.WriteLine("------------------------------------------");

            Console.WriteLine("Enter rock, paper or scissors:");
            string userChoice = Console.ReadLine().ToLower();

            if (Array.Exists(choices, element => element == userChoice)) {
                string computerChoice = choices[random.Next(choices.Length)];
                Console.WriteLine($"Computer chose: {computerChoice}");

                if (userChoice == computerChoice) {
                    Console.WriteLine("It's a tie!");
                } else if ((userChoice == "rock" && computerChoice == "scissors") ||
                           (userChoice == "paper" && computerChoice == "rock") ||
                           (userChoice == "scissors" && computerChoice == "paper")) {
                    Console.WriteLine("You win!");
                } else {
                    Console.WriteLine("You lose!");
                }
            } else {
                Console.WriteLine("Invalid choice. Please try again.");
            }

            Console.WriteLine("Do you want to play again? (yes/no)");
            string response = Console.ReadLine().ToLower();
            playAgain = response == "yes";
        }
    }
}
