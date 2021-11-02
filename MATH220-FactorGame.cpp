/*

	Step 1: Create a dynamically allocated array with values 1-49
	Step 2: Randomly pick number from array
	Step 3: Find factors of randomly chosen number and sum them
	Step 4: Assign summed value to opposing player
	Step 5: Remove factors from array
	Step 6: Repeat steps until no numbers remain
	Step 7: Determine winner by who has the most points

	Repeat

	*/


	// Keep track of total score
	// Keep track of order in which numbers are chosen 



#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>

const int MAX = 49; 

using namespace std;

int sum(int); 

int main()
{
	int player1 = 1,     // player 1 
		player2 = 2,     // player 2 
		randoNum = 0,    // holds randomly chosen number 
		total = 0;       // holds sum of factors 

	char choice = 'Y'; 
	
	

	do
	{
		srand(time(NULL));

		randoNum = rand() % 49 + 1;   // generating a random number 

		cout << "Random number: " << randoNum << endl;   // displaying random number 

		cout << endl << "Factors: ";

		for (int i = 1; i <= randoNum; i++)    // finding the factors of random number 
		{
			if (randoNum % i == 0)
			{
				cout << i << " ";     // displaying factors 
			}
		}

		cout << endl;
		cout << "Sum of factors: " << sum(randoNum) << endl;

	
		cout << endl << "Again? (Y/N):";
		cin >> choice;

		cout << endl; 

	} while (choice != tolower('N'));


	return 0; 
}

int sum(int num)
{
	cout << endl; 
	int result = 0; 

	if (num == 1)
	{
		return 1;
	}

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			if (i == (num / i))
			{
				result += i;
			}
			else
			{
				result += (i + num / i);
			}
		}
	}

	return (result + num + 1);
}
