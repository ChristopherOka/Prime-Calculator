#include <iostream>
#include "a2_q2_functions.h"
#include <iomanip>
#include <math.h>

/*
Program steps:
1. Accept a user inputted distance
2. Calcuate the distance travelled from 0 to 1 second of falling, then 1 to 2 and onwards until the ball hits the ground (displacement = 0)
3. Increase the time increment as the ball nears the ground. (0.9, 0.8...)
4. Increment further as necessary (0.09, 0.08...)
4. Output all these values
*/
/*
This program will work for all values from 0 - 100000.
Tested values (using a calculator):
100 <- works
1234 <- works
Output for 15000 (which also works): 
Time (s)        Current distance (m)    Total distance (m)
0               0                       0
1.000           4.903                   4.903
2.000           14.710                  19.613
3.000           24.517                  44.130
4.000           34.323                  78.453
5.000           44.130                  122.583
6.000           53.937                  176.520
7.000           63.743                  240.263
8.000           73.550                  313.813
9.000           83.357                  397.169
10.000          93.163                  490.332
11.000          102.970                 593.302
12.000          112.776                 706.079
13.000          122.583                 828.662
14.000          132.390                 961.052
15.000          142.196                 1103.248
16.000          152.003                 1255.251
17.000          161.810                 1417.061
18.000          171.616                 1588.677
19.000          181.423                 1770.100
20.000          191.230                 1961.330
21.000          201.036                 2162.366
22.000          210.843                 2373.209
23.000          220.650                 2593.859
24.000          230.456                 2824.315
25.000          240.263                 3064.578
26.000          250.070                 3314.648
27.000          259.876                 3574.524
28.000          269.683                 3844.207
29.000          279.490                 4123.696
30.000          289.296                 4412.993
31.000          299.103                 4712.095
32.000          308.909                 5021.005
33.000          318.716                 5339.721
34.000          328.523                 5668.244
35.000          338.329                 6006.573
36.000          348.136                 6354.709
37.000          357.943                 6712.652
38.000          367.749                 7080.401
39.000          377.556                 7457.957
40.000          387.363                 7845.320
41.000          397.169                 8242.489
42.000          406.976                 8649.465
43.000          416.783                 9066.248
44.000          426.589                 9492.837
45.000          436.396                 9929.233
46.000          446.203                 10375.436
47.000          456.009                 10831.445
48.000          465.816                 11297.261
49.000          475.623                 11772.883
50.000          485.429                 12258.313
51.000          495.236                 12753.548
52.000          505.042                 13258.591
53.000          514.849                 13773.440
54.000          524.656                 14298.096
55.000          534.462                 14832.558
55.000          53.888                  14832.558
55.100          53.986                  14886.544
55.200          54.084                  14940.627
55.300          54.182                  14994.809
55.310          5.191                   15000.000

*/

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