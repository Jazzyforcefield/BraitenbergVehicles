#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
	random_date_1 = Date(2003, 9, 21);
	random_date_2 = Date(2007, 3, 2);
	epoch_date_1 = Date(0);
	epoch_date_2 = Date(100000000);
	new_years = Date(2018, 1, 1);
	christmas = Date(2018, 12, 25);
	valentines = Date(2018, 2, 14);
	valentines_2 = Date(2016, 2, 14);
	march_lion = Date(2016, 3, 1);
	
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date default_date;			// current date
	Date random_date_1;
	Date random_date_2;
	Date epoch_date_1;		// unix start date
	Date epoch_date_2;			// 100000000 seconds after unix start date
	Date new_years;
	Date christmas;
	Date valentines;
	Date valentines_2;
	Date march_lion;
	
};


TEST_F(DateTest, ConstructorDateTests) {	
	std::string expected_out_1 = "2019-02-12";
	std::string expected_out_2 = "02-12-2019";
	std::string expected_out_3 = "2003-09-21";
	std::string expected_out_4 = "09-21-2003";
	std::string expected_out_5 = "2007-03-02";
	std::string expected_out_6 = "03-02-2007";
	std::string expected_out_7 = "1970-01-01";
	std::string expected_out_8 = "01-01-1970";
	std::string expected_out_9 = "1973-03-03";
	std::string expected_out_10 = "03-03-1973";
	
	EXPECT_EQ(default_date.GetDate(), expected_out_1);
	EXPECT_EQ(default_date.GetUsDate(),expected_out_2);
	
	EXPECT_EQ(random_date_1.GetDate(), expected_out_3);
	EXPECT_EQ(random_date_1.GetUsDate(), expected_out_4);
	
	EXPECT_EQ(random_date_2.GetDate(), expected_out_5);
	EXPECT_EQ(random_date_2.GetUsDate(), expected_out_6);
	
	EXPECT_EQ(epoch_date_1.GetDate(), expected_out_7);
	EXPECT_EQ(epoch_date_1.GetUsDate(), expected_out_8);
	
	EXPECT_EQ(epoch_date_2.GetDate(), expected_out_9);
	EXPECT_EQ(epoch_date_2.GetUsDate(), expected_out_10);

}

TEST_F(DateTest, DateLengthTest) {
	std::string expected_out_1 = new_years.GetDate();
	EXPECT_EQ(expected_out_1.length(), 10);
	
}

TEST_F(DateTest, OverloadedAdditionDateTests) {
	Date feb_test = valentines + 15;
	Date new_years_test = christmas + 7;
	Date random_test = random_date_2 + 20;
  
  std::string expected_out_1 = "2018-03-01";
	std::string expected_out_2 = "2019-01-01";
	std::string expected_out_3 = "2007-03-22";
	
	EXPECT_EQ(feb_test.GetDate(), expected_out_1);
	EXPECT_EQ(new_years_test.GetDate(), expected_out_2);	
	EXPECT_EQ(random_test.GetDate(), expected_out_3);

}

TEST_F(DateTest, OverloadedSubtractionDateTests) {
  Date feb_test = valentines - 14;
	Date new_years_test = new_years - 1;
	Date random_test = random_date_2 - 1;
  
  std::string expected_out_1 = "2018-01-31";
	std::string expected_out_2 = "2017-12-31";
	std::string expected_out_3 = "2007-03-01";
	
	EXPECT_EQ(feb_test.GetDate(), expected_out_1);
	EXPECT_EQ(new_years_test.GetDate(), expected_out_2);	
	EXPECT_EQ(random_test.GetDate(), expected_out_3);

}


TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, DaysBetweenTests) {
	Date feb_date = valentines_2 + 15;

  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

	EXPECT_EQ(feb_date.GetDate(), "2016-02-29") << "Leap years not setup properly";
	EXPECT_EQ(valentines_2.GetDate(), "2016-02-14") << "Valentines not setup properly";
	EXPECT_EQ(march_lion.GetDate(), "2016-03-01") << "march_lion not setup properly";
	EXPECT_EQ(valentines_2.DaysBetween(march_lion), 16) << "Days between not calculated properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
