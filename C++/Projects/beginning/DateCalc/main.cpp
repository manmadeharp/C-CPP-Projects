#include<mutex>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
std::vector<std::string> Months{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
				"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

std::vector<int> Days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

std::mutex mtx;

void fileHandling(int days, std::string title, std::string date, std::string endDate)
{
	std::cout << '\n' << days << '\t' << title << '\t' << date << '\t' << endDate;

	std::fstream fs;
	fs.open ("dateStore.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fs << title << ',' << date << ',' << endDate << ',' << days;
	fs.close();
	
}

int intConcatenate(std::vector<int> intVec)
{
	return ((intVec.size() < 4) ? ((intVec[0] * 10) + intVec[1])
				     : ((intVec[0] * 1000) + (intVec[1] * 100) +
					(intVec[2] * 10) + intVec[3]));
	//(intVec[0]*10)+intVec[1]);

}

int vecIndex(std::vector<int> intVec, int n)
{
	for (int i = 0; i < intVec.size(); i++) {
		if (n == intVec[i]) {
			return i;
		}
	}
	return 0;
}

int DaysBetCalc(int startMonth, int startDay, int endMonth, int endDay, int nYears)
{
	int days = Days[startMonth - 1] - startDay;
	if (startMonth == endMonth)	{
		days += nYears*365;
		return (days += endDay - startDay);
	}
	//std::cout << '\n' << startMonth << '\t' << startDay << '\t' << endMonth << '\n';

	for(int i = 0; i < (endMonth - startMonth - 1); i++)	{
		//std::cout << Days[startDay + i] << '\t';
		days += Days[startMonth + i];
	}
	days += endDay;
	days += nYears*365;

	return days;
}

int DateParser(std::string date, std::string endDate)
{
	std::vector<int> startDay, startMonth, startYear;
	std::vector<int> endDay, endMonth, endYear;
	int daysBetw;
	for (int i = 0; i < date.size(); i++) 
	{
		if (static_cast<int>(date[i]) >= 47) {
			if (static_cast<int>(date[i]) <= 57) {
				if (i <= 1) {
					startDay.push_back(
					    static_cast<int>(date[i]) - 48);
				}
				if (i == 2) {
					if (date[2] != 47) {
						startDay.clear();
						std::cout
						    << "\nformat is wrong\n";
						break;
					}
				}
				if (i > 2 && i < 5) {
					startMonth.push_back(
					    static_cast<int>(date[i]) - 48);
				}
				if (i == 5) {
					if (date[5] != 47) {
						startDay.clear();
						startMonth.clear();
						std::cout
						    << "\nformat is wrong\n";
						break;
					}
				}
				if (i > 5 && i < 10) {
					startYear.push_back(
					    static_cast<int>(date[i]) - 48);
				}
				if (i > 10) {
					startDay.clear();
					startMonth.clear();
					startYear.clear();
					std::cout << "\nformat is wrong\n";
					break;
				}
			}
			else {
				std::cout << "That date is not valid please "
					     "enter a number"
					  << '\n';
				break;
			}
		}
		else {
			std::cout << "That date is not valid" << '\n';
			break;
		}
	}
	for (int i = 0; i < date.size(); i++) 
	{
		if (static_cast<int>(date[i]) >= 47) {
			if (static_cast<int>(date[i]) <= 57) {
				if (i <= 1) {
					endDay.push_back(
					    static_cast<int>(endDate[i]) - 48);
				}
				if (i == 2) {
					if (date[2] != 47) {
						endDay.clear();
						std::cout
						    << "\nformat is wrong\n";
						break;
					}
				}
				if (i > 2 && i < 5) {
					endMonth.push_back(
					    static_cast<int>(endDate[i]) - 48);
				}
				if (i == 5) {
					if (date[5] != 47) {
						endDay.clear();
						endMonth.clear();
						std::cout
						    << "\nformat is wrong\n";
						break;
					}
				}
				if (i > 5 && i < 10) {
					endYear.push_back(
					    static_cast<int>(endDate[i]) - 48);
				}
				if (i > 10) {
					endDay.clear();
					endMonth.clear();
					endYear.clear();
					std::cout << "\nformat is wrong\n";
					break;
				}
			}
			else {
				std::cout << "That date is not valid please "
					     "enter a number"
					  << '\n';
				break;
			}
		}
		else {
			std::cout << "That date is not valid" << '\n';
			break;
		}
	}

	// for(int i = 0; i < startYear.size(); i++)	{
	//	std::cout << startYear[i] << '\n';
	//}
	// std::cout << startDay.size() << '\t' <<startMonth.size() << '\t' <<
	// startYear.size(); std::cout << intConcatenate(startDay) << '\t' <<
	// intConcatenate(startMonth) << '\t' << intConcatenate(startYear) <<
	// '\n';

	/*
	I need to add up the days from each date
	to do this I need to:
	-> add the current months days - the days in startdate
	-> add up the days of each month up to the final month +
	`-> (endYear - startYear)*365.
	-> add up the number of days in endDate
	->
	*/

	
	// Calculating Days Betweens.
//	std::cout << startYear.size() << '\t' << endYear.size();
//	std::cout << intConcatenate(startYear) << '\t' << intConcatenate(endYear) << '\n';
	daysBetw = DaysBetCalc(intConcatenate(startMonth), intConcatenate(startDay), intConcatenate(endMonth), intConcatenate(endDay), (intConcatenate(endYear) - intConcatenate(startYear)));
	//std::cout << daysLeftinMonth << '\n';
	
	//std::cout << Days[intConcatenate(startMonth) - 1] << '\t' << intConcatenate(startDay) << '\n';
	

	std::cout << "Thanks for Correct Dates!" << '\n';
	return daysBetw;
}

int main()
{
	std::string answer;
	std::string date;
	std::string endDate;
	std::string save;
	std::string title;


	std::cout << "Would you like to create a new entry \n";
	std::cin >> answer;

	while (answer == "y" && "Y") {
		std::cout << "\nPlease enter a valid start date in the format "
			     "of DD/MM/YYYY \n";
		std::cin >> date;

		std::cout << "\nPlease enter a valid end date in the format of "
			     "DD/MM/YYYY \n";
		std::cin >> endDate;
		
		std::cout << "\nWould you like to save? (y/n)\n";
		std::cin >> save;

		if(save == "y" || save == "Y")	{
			std::cout << "What would you like to call the save? ";
			std::cin >> title;
			fileHandling(DateParser(date, endDate), title, date, endDate);
		} else	{
			DateParser(date, endDate);
		}

		std::cout << "\nWould you like to create a new entry \n";
		std::cin >> answer;
	}

	for (int i = 0; i < Days.size() && Months.size(); i++) {
		std::cout << "Month: " << Months[i] << " - ";
		std::cout << "Days in Month: " << Days[i] << '\n';
	}
}
