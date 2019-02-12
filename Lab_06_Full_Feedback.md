### Feedback for Lab 06

Run on February 12, 01:39:06 AM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab06_google_tests" exists.

+ Pass: Make directory "Lab06_Testing".

+ Pass: Change into directory "Lab06_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab06_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab06 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Pass: Check that make compiles.



+ Pass: Check that file "date_unittest" exists.

+ Pass: Get all google tests.
    3 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithoutNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.DaysBetweenTests.



+ Pass: 100% of the tests passed.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Dates constructed with epoch are about 70 years in the future


#### Testing Mutant 2 for failure

+ Pass: At least one test failed for Mutant 2


#### Testing Mutant 3 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Dates from GetDate are missing a character


#### Testing Mutant 4 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Today's date month off by one


#### Testing Mutant 5 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59


#### Testing Mutant 6 for failure

+ Pass: At least one test failed for Mutant 6


#### Testing Mutant 7 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - operator-: Probably a copy paste error


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9

