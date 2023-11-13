#include "pch.h"
#include "CppUnitTest.h"
#include "..\Application1\date.h"
#include "..\Application1\pressure.h"
#include<sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pressureTest
{
	TEST_CLASS(pressureTest)
	{
	public:
		
		TEST_METHOD(correctValueTest)
		{
			
			//std::stringstream a;
			
			Pressure x;

			x.CorrectValue(32, 5);
		}
		TEST_METHOD(correctDateTest)
		{
			DateStruct date;

			std::string d = "12.03.22";

			date.CorrectDate(d);
		}

		TEST_METHOD(correctDateReadTest) {
			DateStruct date;
			
			std::string d = "12.03.22";

			date.readDate(d);
		}

		TEST_METHOD(correctDatePrintTest) {
			DateStruct date;
			
			date.setDD(12);
			date.setMM(12);
			date.setYY(21);
			
			std::string d = "Дата: 12.12.21";

			std::stringstream x;
			date.printDate(x);
			Assert::AreEqual(x.str(), d);
		}

		TEST_METHOD(correctPressureReadTest) {
			Pressure pr;

			std::stringstream f("");

			std::vector<Pressure> pvec;
			
			try {
				pr.readPressure(f, pvec);
			}
			catch(const std::runtime_error &message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(correctPressurePrintTest) {
			Pressure pr;
			DateStruct date;
			std::vector<Pressure> pvec;

			date.setDD(12);
			date.setMM(12);
			date.setYY(21);
			
			pr.setDate(date);
			
			pr.setHigh(33.3);
			pr.setValue(45);

			std::string d = "Дата: 12.12.21 Высота: 33.3 Значение:  45\n";
			
			std::stringstream x;
			pr.print(x);
			Assert::AreEqual(x.str(), d);
		}

		TEST_METHOD(invalidValueTest)
		{

			try {
				Pressure x;
				x.CorrectValue(-32.06, 5.2);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidDateTest)
		{
			try {
				DateStruct date;

				std::string d = "92.23.22";

				date.CorrectDate(d);
			}
			catch (const std::runtime_error& message) {
				return;
			}
			
			Assert::Fail();
		}

		TEST_METHOD(invalidDateReadTest) {
			DateStruct date;

			std::string d = "12.12.13";

			date.readDate(d);
		}

		TEST_METHOD(invalidDatePrintTest) {
			DateStruct date;
			date.setDD(13);
			date.setMM(12);
			date.setYY(21);

			std::string d = "Дата: 12.12.21";

			std::stringstream x;
			date.printDate(x);
			Assert::AreNotEqual(x.str(), d);
		}

		TEST_METHOD(invalidPressurePrintTest) {
			Pressure pr;
			DateStruct date;
			std::vector<Pressure> pvec;


			date.setDD(13);
			date.setMM(12);
			date.setYY(21);
			
			pr.setDate(date);

			pr.setHigh(33.3);
			pr.setValue(45);

			std::string d = "Дата: 12.12.21 Высота: 33.3 Значение:  45\n";

			std::stringstream x;
			pr.print(x);
			Assert::AreNotEqual(x.str(), d);
		}

	};
}
