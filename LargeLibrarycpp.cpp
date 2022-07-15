#include "LargeLibrary.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;






#pragma region readInt Functions
int readInt()
{
	int userInt;
	cin >> userInt;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Value must be a whole number! Please try again: " << endl;
		cin >> userInt;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return userInt;
}

int readInt(string instructions)
{
	cout << instructions << endl;
	return readInt();
}

int readInt(int min, int max)
{
	int toReturn;
	cout << "Please enter a number between " << min << " and " << max << endl;
	toReturn = readInt();
	while (toReturn < min || toReturn > max)
	{
		cout << "Error: number was outside limits. Try again: ";
		toReturn = readInt();
	};
	return toReturn;
}

int readInt(int min, int max, string instructions)
{
	cout << instructions << endl;
	return readInt(min, max);
}
#pragma endregion

#pragma region readDouble Functions
double readDouble()
{
	double userDouble;
	cin >> userDouble;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Value must be a real number! Please try again: " << endl;
		cin >> userDouble;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return userDouble;
}

double readDouble(string instructions)
{
	cout << instructions << endl;
	return readDouble();
}

double readDouble(double min, double max)
{
	double userDouble;
	cout << "Please enter a number between " << min << " and " << max << endl;
	userDouble = readDouble();
	while (userDouble < min || userDouble > max)
	{
		cout << "Error: number was outside limits. Try again: ";
		userDouble = readDouble();
	};
	return userDouble;
}

double readDouble(double min, double max, string instructions)
{
	cout << instructions << endl;
	return readDouble(min, max);
}
#pragma endregion

#pragma region readChar Functions
char readChar()
{
	char userChar;
	cin >> userChar;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return userChar;
}
char readChar(string instructions)
{
	cout << instructions << endl;
	return readChar();
}
#pragma endregion

#pragma region readString Functions
string readWord()
{
	string userString;
	cin >> userString;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return userString;
}
string readWord(string instructions)
{
	cout << instructions << endl;
	return readWord();
}
string readLine()
{
	string userString;
	getline(cin, userString);
	return userString;
}
string readLine(string instructions)
{
	cout << instructions << endl;
	return readLine();
}
#pragma endregion

#pragma region readBool Functions
bool readBool()
{
	return readInt(0, 1, "1 for yes, 0 for no");
}
bool readBool(string instructions)
{
	cout << instructions << endl;
	return readBool();
}
#pragma endregion

// Static

const string ConsoleMenu::separator = "-------------------------";

std::string ConsoleMenu::getSeparator()
{
	return separator;
}

// Instance

ConsoleMenu::ConsoleMenu(std::string title, std::string message, std::vector<std::string> options)
{
	this->title = title;
	this->message = message;
	this->options = options;
}

string ConsoleMenu::getTitle()
{
	return title;
}

string ConsoleMenu::getMessage()
{
	return message;
}

string ConsoleMenu::getOption(int index)
{
	if (index >= 0 && index < options.size())
		return options[index];
	else
		return string();
}

int ConsoleMenu::getSize()
{
	return options.size();
}

void ConsoleMenu::setTitle(string title)
{
	this->title = title;
}

void ConsoleMenu::setMessage(string message)
{
	this->message = message;
}

void ConsoleMenu::setOptions(std::vector<std::string> options)
{
	this->options = options;
}

void ConsoleMenu::displayTitle()
{
	if (title.length() > 0)
		cout << title << endl << endl;
}

void ConsoleMenu::displayMessage()
{
	if (message.length() > 0)
		cout << message << endl << endl;
}

void ConsoleMenu::displaySeparator()
{
	cout << separator << endl;
}

void ConsoleMenu::displayOptions()
{
	for (int i = 0; i < options.size(); i++)
		cout << "    " << (i + 1) << " - " << options[i] << endl;
	cout << endl;
}

int ConsoleMenu::displayAndGetSelection()
{
	displaySeparator();
	displayTitle();
	displayOptions();

	int min = 1;
	int max = options.size();

	int userInt;
	if (message.length() > 0)
		userInt = readInt(min, max, message);
	else
		userInt = readInt(min, max);

	// return option number (one-based numbering)
	return userInt;
}

int ConsoleMenu::displayAndGetSelectionIndex()
{
	// return option index (zero-based numbering)
	return displayAndGetSelection() - 1;
}



Date::Date(int year, int month, int day)
{
	this->year = year;
	if (month < 1)
		month = 1;
	if (month > 12)
		month = 12;
	this->month = month;
	if (day < 1)
		month = 1;
	if (day > getNumOfDaysInMonth())
		day = getNumOfDaysInMonth();
	this->day = day;
}

Date::Date()
	:Date(2000, 1, 1)
{}

int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}


std::string Date::getMonthString()
{
	switch (month)
	{
	case 1: return "January";
	case 2: return "Febuary";
	case 3: return "March";
	case 4: return "April";
	case 5: return "May";
	case 6: return "Jun";
	case 7: return "July";
	case 8: return "August";
	case 9: return "September";
	case 10: return "Octomber";
	case 11: return "November";
	case 12: return "December";
	default: return "Date Error";
	}
}


int Date::getNumOfDaysInMonth()
{
	switch (month)
	{
	case 1: return 31;
	case 2: return (isLeapYear() ? 29 : 28);
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	default: return 1;
	}
}
bool Date::isLeapYear()
{

	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

	/*if (year % 4 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 400 == 0)
		return true;
	else
		return true;*/
}

int Date::getYearUntil(Date other)
{
	return getMonthUntil(other) / 12;
}
int Date::getMonthUntil(Date other)
{
	return getDayUntil(other) / 30;

}
int Date::getDayUntil(Date other)
{
	int yearsDifference = year - other.year;
	int monthsDifference = month - other.month;
	int trueMonthDifference = (yearsDifference * 12) + monthsDifference;
	int daysBetween = day - other.day;
	int trueDaysDifference = (trueMonthDifference * 30) + daysBetween;
	return trueMonthDifference;
}



std::string Date::toString()
{
	return getMonthString() + " " + to_string(day) + " ," + to_string(year);
}
void Date::display()
{
	std::cout << toString() << std::endl;
}




StreetAddress::StreetAddress(int streetNumber, string streetName, string city, string country)
{

	this->streetNumber = streetNumber;
	this->streetName = streetName;
	this->city = city;
	this->country = country;

}

StreetAddress::StreetAddress()
	:StreetAddress(4001, "Eduoard", "Montreal", "Canada")
{

}

int StreetAddress::getStreetNumber()
{
	return streetNumber;
}
string StreetAddress::getStreetName()
{
	return streetName;
}
string StreetAddress::getCity()
{
	return city;
}
string StreetAddress::getCountry()
{
	return country;
}


bool StreetAddress::isStreetNumberEven()
{
	if (getStreetNumber() % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int StreetAddress::getStreetNameLength()
{
	return getStreetName().length();
}
char StreetAddress::getCityInitialLetter()
{
	return getCity().front();
}
string StreetAddress::getCountryCode()
{
	return getCountry().substr(0, 3);
}



std::string StreetAddress::toString()
{
	return  to_string(streetNumber) + ", " + getStreetName() + " " + getCity() + " " + getCountry();
}

void StreetAddress::display()
{
	std::cout << toString() << std::endl;
}

void StreetAddress::display1()
{
	std::cout << getCityInitialLetter();
}

void StreetAddress::display2()
{
	std::cout << getCountryCode();
}

void StreetAddress::display3()
{
	std::cout << getStreetNameLength();
}



Passport::Passport(string firstName, string lastName, double height, Date dateOfBirth, StreetAddress address)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->height = height;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}
Passport::Passport()
	:Passport("Reedham", "Patel", 1.4, Date::Date(), StreetAddress::StreetAddress())
{

}

int Passport::getId()
{
	return id;
}
int Passport::nextId = 0;
int Passport::getNextId()
{
	id = ++nextId;
	return id;
}
string Passport::getfirstName()
{
	return firstName;
}
string Passport::getLastName()
{
	return lastName;
}
double Passport::GetHeight()
{
	return height;
}
string Passport::setFullName()
{
	return this->fullName = this->lastName + this->firstName;
}
string Passport::getFullName()
{
	return getfirstName() + " " + getLastName();
}
int Passport::getAgeInYears(Date d)
{
	return d.getYearUntil(Date());
}
int Passport::getAgeInMonths(Date d)
{
	return d.getMonthUntil(Date());
}
int Passport::getAgeInDays(Date d)
{
	return d.getDayUntil(Date());
}

bool Passport::isYouth(Date d)
{

	if (getAgeInYears(d) < LEGAL_ADULT_AGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Passport::isWorkingAge(Date d)
{
	if (getAgeInYears(d) > LEGAL_ADULT_AGE && getAgeInYears(d) < SENIOR_CITIZEN_AGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Passport::isSeniorCitizen(Date d)
{
	if (getAgeInYears(d) >= SENIOR_CITIZEN_AGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Passport::canVote(Date d)
{
	if (getAgeInYears(d) >= LEGAL_ADULT_AGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const double  Passport::AVERAGE_HEIGHT = 1.7;
double Passport::getHeightAboveAverage()
{
	return GetHeight() - AVERAGE_HEIGHT;
}
std::string Passport::toPassPassPortString(Date d1, StreetAddress s1)
{


	return getFullName() + ": " + "Height = " + to_string(height) + " meters, Date of Birth = " + d1.toString() + "\n Address = " + s1.toString();
}

void Passport::display(Date d1, StreetAddress s1)
{

	std::cout << toPassPassPortString(d1, s1);
}

//static:Function 
Date Date::getToday()
{
	struct tm now;
	time_t nowTime = time(0);
	localtime_s(&now, &nowTime);
	Date today = Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
	return today;
}