#pragma once
#include "clsDate.h"
class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To) {
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To) {
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To) {
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To) {
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo){
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			)
		{
			return true;
		}

		return false;

			
	}

	static int ReadIntNumber(string Message){
		int Number = 0;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumber(string Message) {
		double Number = 0;
		cin >> Number;
		while (cin.fail()) {
			// or while(!(cin >> Number))
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Message){
		int Number;
		// Number = ReadIntNumber();
		cin >> Number;
		while (Number < From || Number > To) {
			// while(!IsNumberBetween(Number, From, To))
			cout << Message;
			// Number = ReadIntNumber();
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message) {
		double Number;
		cin >> Number;
		while (Number < From || Number > To) {
			cout << Message;
			cin >> Number;
		}
		return Number;
	}

	static bool IsValidateDate(clsDate Date){
		return clsDate::IsValidDate(Date);
	}
};

