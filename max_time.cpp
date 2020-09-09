/**
 * Maximum time in train/flight format. Fill '?' in given string to make it max time.
 * https://leetcode.com/discuss/interview-question/396769/
 */

#include <iostream>
#include <string>

using namespace std;

void updateHour(string &missingTime)
{
	if (missingTime[0] == '?')
	{
		missingTime[0] = '2';

		if (missingTime[1] == '?')
			missingTime[1] = '3';
		else if (! (missingTime[1] >= '0' && missingTime[1] <= '3'))
			missingTime[0] = '1';
	}
	else
	{
		if (missingTime[1] == '?')
		{
			missingTime[1] = '3';

			if (missingTime[0] == '0' || missingTime[0] == '1')
				missingTime[1] = '9'; //09, 19
		}
	}
}

void updateMinute(string &missingTime)
{
	if (missingTime[3] == '?')
		missingTime[3] = '5';

	if (missingTime[4] == '?')
		missingTime[4] = '9';
}

string const maxTime(string missingTime)
{
	updateHour(missingTime);
	updateMinute(missingTime);

	return missingTime;
}

int main()
{
	cout << maxTime("?4:5?") << endl;
	cout << maxTime("23:5?") << endl;
	cout << maxTime("2?:22") << endl;
	cout << maxTime("0?:??") << endl;
	cout << maxTime("??:??") << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

