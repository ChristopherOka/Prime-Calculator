#include "functions.h"
#include <iostream>
#include <windows.h>

void prime_calculator() {
	//PURPOSE: Calculate prime numbers from 1 to the inputted value. Also calculate whether a prime is palindromic and if the sum of its digits is prime
	//INPUT: User inputted unsigned long long value which is used in the prime calculation process
	//OUTPUT: All primes from 1 to the inputted value, the palindromic primes, and primes with an odd sum of digits are printed
	unsigned long long input = 0; //declares and initializes input value to 0. This is the variable that will be used to accept the user's input
	std::cout << "Hey! Enter any number between 1 and 18,446,744,073,709,551,615 and this calculator will find every prime from 0 to your number.\n";
	std::cout << "It will also tell you if the number is a palindrome (for primes ranging from 1-10,000) and if the sum of its digits are odd " 
		<< "(for primes ranging from 1-100000).\n";
	std::cout << "Keep in mind, it will take some time to compute, depending on how many primes you want returned.\n";
	while (input < 1) { //repeat loop until number entered is greater than or equal to 1
		std::cout << "Please enter your number now: ";
		std::cin >> input;	//user enters the input value	
	}
	std::cout << "All the primes from 1 to " << input << " are as follows. Are you ready?\n";
	Sleep(3000); //program pauses for effect
	std::cout << "3\n";
	Sleep(600);
	std::cout << "2\n";
	Sleep(600);
	std::cout << "1\n";
	Sleep(600);
	for (unsigned long long i = 1; i <= input; i++) { //loop goes until all numbers from 1 - input are checked to be prime 
		if (i == 2) { //2 as a prime is hardcoded into the program. 2 is a fringe case that makes it difficult to create a program around
			std::cout << "\n" << i << ", "; //2 is printed to the console
		}
		for (unsigned long long int j = i - 1; j > 1; j--) { //for loop goes until j has deincremented from the input value back to 1. j is declared to be i - 1, 
			//because the for loop will run one time without deincrementing j, so subtracting 1 makes the loop only run for all the values of 1 to the input 
				bool prime = true; //prime value set to true. If it never gets turned false, this "i" number is a prime
				if (i % j == 0) { //checks if the current i number is divisible by the current j number
					prime = false; //if it is divisible, it is not prime, so the prime value is set to false 
					break; //the program jumps out of this if statement
				}
				if (j == 2 && prime == true) { //if the program has checked the final iteration of what the number can be divisible by, and prime still equals true
					std::cout << "\n" << i << ", "; //i is a prime number is displayed to console
					unsigned long long palindrome = 0; //variable palindrome declared which is used to store the reversed "i" number
					unsigned long long added_digit; //this variable will be used in the palidrome-finding process for building the reversed number
					unsigned long long placeholder_number = i; //this variable is declared to use the value of i, but not change it 
					if (i < 10000) { //this only runs if i < 10000
						while (placeholder_number > 0) { //repeats while the i value is still above 0 (it will eventually deincrement to 0)
							added_digit = placeholder_number % 10; //this checks what the final digit in the "i" number is
							palindrome = palindrome * 10 + added_digit;
							//palindrome is multiplied by 10 each time to add a new ones place, the added_digit is added into the ones place
							//this effectively builds the number back up, but backwards
							placeholder_number = placeholder_number / 10; //i is divided by 10 to remove a ones place each time, deincrementing towards 0
						}
						if (palindrome == i) { //checks if the forward number is equal to the backwards number
							std::cout << "<- This number is a palindrome!"; //prints this to console
						}
					}
					if (i < 100000) { //only runs if i < 100000
						//similar to the palindrome calculator, these variables are declared to help with finding each individual digit in a number
						unsigned long long new_placeholder = i; //this variable is declared and initialized to use the "i" value, but not alter it
						unsigned long long new_added_digit; //this variable will be used to keep track of the current ones digit
						int sum = 0; //this variable will be used to store the total sum of all the digits
						while (new_placeholder > 0) { //runs while new_placeholder is greater than 0. After all the digits are summed, new_placeholder = 0
							new_added_digit = new_placeholder % 10; //this gives the ones digit of the current new_placeholder number
							sum = sum + new_added_digit; //this adds the current digit to the total sum value
							new_placeholder = new_placeholder / 10; //this removes a ones digit from the current new_placeholder number, until it hits 0

						}
						if (sum % 2 != 0) { //this checks if the sum of the digits is an odd number
							std::cout << " <- This number has an odd sum of digits!"; //if it is odd, this is printed to the console
					}
					
					}
				}
			}
	}
}
