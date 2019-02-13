### Feedback for Lab 06

Run on February 13, 05:11:27 AM.


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
    7 tests found.




#### Results

+ Fail: Check that a GoogleTest test passes.
    fails the test: DateTest.ConstructorDateTests.
<pre>
[ RUN      ] DateTest.ConstructorDateTests
./date_unittest.cc:56: Failure
      Expected: default_date.GetDate()
      Which is: "2019-02-13"
To be equal to: expected_out_1
      Which is: "2019-02-12"
./date_unittest.cc:57: Failure
      Expected: default_date.GetUsDate()
      Which is: "02-13-2019"
To be equal to: expected_out_2
      Which is: "02-12-2019"</pre>



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.DateLengthTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.OverloadedAdditionDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.OverloadedSubtractionDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithoutNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.DaysBetweenTests.



+ Fail: 85.71% of the tests passed, but the target is 100%.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Dates constructed with epoch are about 70 years in the future


#### Testing Mutant 2 for failure

+ Pass: At least one test failed for Mutant 2


#### Testing Mutant 3 for failure

+ Pass: At least one test failed for Mutant 3


#### Testing Mutant 4 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Today's date month off by one


#### Testing Mutant 5 for failure

+ Pass: At least one test failed for Mutant 5


#### Testing Mutant 6 for failure

+ Pass: At least one test failed for Mutant 6


#### Testing Mutant 7 for failure

+ Pass: At least one test failed for Mutant 7


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9

