#include <iostream>
#include "functions.h"
#include <iomanip>
#include <math.h>


void distance_calculator() { //this function will calculate the distance in time intervals that the ball travels as it falls
	//PURPOSE: Calculates the distance in time intervals that a ball dropped from a height travels as it falls towards Earth
	//INPUT: Inputted double value from user which is the value of the height that the drone drops the ball from
	//OUTPUT: Outputs the total distance travelled by the falling ball in time increments, outputs the distance travelled between time increments, 
	//and outputs the time increments
	double input; //declare input variable
	bool repeat = true; //set a boolean repeat variable to true, so it goes through the while loop at least once
	while (repeat == true) {//this while loop repeats until "repeat" is false
		std::cout << "Enter a distance in metres that the drone will drop your ball from, and this calculator will tell you where the ball is at every 1 second increment.\n";
		std::cin >> input; //user enters an input for the distance the ball will be dropped from
		if (input > 100000) { //this will run if the value of the input is greater than 100000 km
			std::cout << "Whoa! You've reached the edge of space. I don't think your ball will survive a fall from that height. Try again.\n";
			repeat = true; //sets the repeat value to true, causing the while loop to repeat, and the user to input another value
		}
		if (input < 0) { //checks if the distance the ball is being dropped is less than 0
			std::cout << "Sorry, this drone does not have tunnel-boring capabilites. It must drop your ball from a height greater than 0.\n";
			repeat = true; //sets the repeat value to true
		}
		if (input == 0) { //checks if the input distance is 0
			std::cout << "The ball is already at the ground... It can't fall!\n";
			repeat = true;
		}
		if (input > 0 && input <= 100000) { //if the input is between 0 and 100000, then this while loop is exited
			repeat = false; //sets repeat to false
		}
	}

	const double GRAVITY = 9.80665; //g constant (m/s^2)
	double seconds = 1; 
	//declare seconds variable to keep track of the inputted seconds into the equation. 
	//Start at 1 second, because it is already known that after 0 seconds, every value will be 0
	double distance = 0; //declare distance variable to keep track of total distance
	double current_distance = 0; //declare current_distance variable to keep track of the distance between "seconds" increments
	const double ERROR_BAR = 10; //ERROR_BAR variable declared, which is when the ball is 10 metres from the ground, the increment will change to 0.1 seconds
	std::cout.setf(std::ios::fixed); //set decimal precision to 4
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(3);
	std::cout << "Time (s)" << "	Current distance (m)" << "	Total distance (m)\n"; //display the time, current distance and total distance in a column format
	std::cout << "0" << "		0" << "			0\n";
	
	while (distance < input) { //this loop runs until the distance the ball has travelled exceeds the initial input
	
		distance = 0.5 * GRAVITY * seconds * seconds; //the distance the ball has travelled is calculated by this formula
		if (distance > input) { //if the distance is greater than the input, this code is run
			distance = 0; //temporarily setting distance to 0 until it is recalculated in the next step
			seconds--; //seconds is deincremented by 1, to before the distance was greater than the input
			break; //the while loop is exited
		}
		current_distance = (0.5 * GRAVITY * seconds * seconds) - (0.5 * GRAVITY * (seconds - 1) * (seconds - 1)); 
		//the current distance is calculated by subtracting the previous distance (by taking the seconds - 1 term) from the current distance
		std::cout << seconds << "		" << current_distance << "			" << distance << std::endl; //the seconds, current and total distance are printed to console
		seconds++; //seconds are incremented by 1
	} 
	while (distance < input) { //this loop runs while the distance is less than the input
		seconds += 0.1; //incremented by 0.1 now
		distance = 0.5 * GRAVITY * seconds * seconds; //distance is calculated
		if (distance > input) { //this runs when the distance exceeds the input
			distance = 0; //temporarily setting distance to 0 until it is recalculated in the next step
			seconds -= 0.1; //seconds is deincremented by 0.1, to before the distance was greater than the input
			break; //the while loop is exited
		}
		current_distance = (0.5 * GRAVITY * seconds * seconds) - (0.5 * GRAVITY * (seconds - 0.1) * (seconds - 0.1)); 
		//now the seconds - 0.1 term is used, because that is what seconds is being incremented by
		std::cout << seconds << "		" << current_distance << "			" << distance << std::endl;
		
	}
	while (distance < input) {
		seconds += 0.01; //incremented by 0.01 now
		distance = 0.5 * GRAVITY * seconds * seconds;
		if (distance > input) {
			seconds -= 0.01; //seconds is deincremented by 0.01, to before the distance was greater than the input
			break; //the while loop is exited
		}
		current_distance = (0.5 * GRAVITY * seconds * seconds) - (0.5 * GRAVITY * (seconds - 0.01) * (seconds - 0.01)); 
		//now the seconds - 0.01 term is used, because that is what seconds is being incremented by
		std::cout << seconds << "		" << current_distance << "			" << distance << std::endl;
	}
	distance = distance = 0.5 * GRAVITY * seconds * seconds; //distance is recalculated to be less than the input value
	seconds = sqrt((2 * input) / GRAVITY); //finds how many total seconds it takes for the ball to hit the ground
	std::cout << seconds << "		" << input - distance << "	    		" << input << std::endl; 
	//the final time, current distance and total distance is printed to console
	

}
