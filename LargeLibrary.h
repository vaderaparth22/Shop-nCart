#include<iostream>
#include<string>
#include <vector>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::getline;

int readInt();
int readInt(string instructions);
int readInt(int min, int max);
int readInt(int min, int max, string instructions);

double readDouble();
double readDouble(string instructions);
double readDouble(double min, double max);
double readDouble(double min, double max, string instructions);

char readChar();
char readChar(string instructions);

string readWord();
string readWord(string instructions);

string readLine();
string readLine(string instructions);

bool readBool();
bool readBool(string instructions);




class ConsoleMenu
{
private:
	static const std::string separator;
public:
	static std::string getSeparator();

private:
	std::string title;
	std::string message;
	std::vector<std::string> options;

public:
	ConsoleMenu(std::string title, std::string message, std::vector<std::string> options);

	std::string getTitle();
	std::string getMessage();
	std::string getOption(int index);
	int getSize();

	void setTitle(std::string title);
	void setMessage(std::string message);
	void setOptions(std::vector<std::string> options);

	void displayTitle();
	void displayMessage();
	void displaySeparator();
	void displayOptions();

	int displayAndGetSelection();
	int displayAndGetSelectionIndex();
};

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int year, int month, int day);
	Date();

	int getYear();
	int getMonth();
	int getDay();

	std::string getMonthString();
	int getNumOfDaysInMonth();
	bool isLeapYear();

	int getYearUntil(Date other);
	int getMonthUntil(Date other);
	int getDayUntil(Date other);



	std::string toString();
	void display();
	//static function 
	static Date getToday();
};
class StreetAddress
{
private:
	int streetNumber;
	string streetName;
	string city;
	string country;

public:
	StreetAddress(int streetNumber, string streetName, string city, string country);
	StreetAddress();
	int getStreetNumber();
	string getStreetName();
	string getCity();
	string getCountry();

	bool isStreetNumberEven();
	int getStreetNameLength();
	char getCityInitialLetter();
	string getCountryCode();



	string toString();
	void display();

	void display1();
	void display2();
	void display3();

};
class Passport
{
public:
	static int const LEGAL_ADULT_AGE = 18;
	static int const SENIOR_CITIZEN_AGE = 65;
	static const double  AVERAGE_HEIGHT;
private:
	static int nextId;
	int id = 0;
	string firstName;
	string lastName;
	string fullName;
	double height;
	Date dateOfBirth;
	StreetAddress address;
public:
	Passport(string firstName, string lastName, double height, Date dateOfBirth, StreetAddress address);
	Passport();
	int getId();
	int getNextId();
	string getfirstName();
	string getLastName();
	double GetHeight();
	string getFullName();
	string setFullName();
	int getAgeInYears(Date d);
	int getAgeInMonths(Date d);
	int getAgeInDays(Date d);
	bool isYouth(Date d);
	bool isWorkingAge(Date d);


	bool isSeniorCitizen(Date d);
	bool canVote(Date d);
	double getHeightAboveAverage();
	string toPassPassPortString(Date d1, StreetAddress s1);
	void display(Date d1, StreetAddress s1);
};
