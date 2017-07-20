echo "\033[0;31mStarting Test run\033[m\n"

echo "\033[0;32mTESTING FAIL CASES\033[m"

echo "\033[0;34mSyntax check\033[m"
./AbstractVM testcases/invalidTestCases/syntaxCheck.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"

echo "\033[0;34mTesting Overflow files\033[m"
./AbstractVM testcases/invalidTestCases/Overflow_push8.avm
./AbstractVM testcases/invalidTestCases/Overflow_push16.avm
./AbstractVM testcases/invalidTestCases/Overflow_push32.avm
./AbstractVM testcases/invalidTestCases/Overflow_pushfloat.avm
./AbstractVM testcases/invalidTestCases/Overflow_pushdouble.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"

echo "\033[0;34mTesting Underflow files\033[m"
./AbstractVM testcases/invalidTestCases/Underflow_push8.avm
./AbstractVM testcases/invalidTestCases/Underflow_push16.avm
./AbstractVM testcases/invalidTestCases/Underflow_push32.avm
./AbstractVM testcases/invalidTestCases/Underflow_float.avm
./AbstractVM testcases/invalidTestCases/Underflow_double.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"

echo "\033[0;34mTesting files\033[m"
echo "\n\033[0;31mNo file\033[m"
./AbstractVM pewpewpewp
echo "\n\033[0;31mEmpty file\033[m"
./AbstractVM testcases/invalidTestCases/EmptyFile.avm
echo "\n\033[0;31mFile with comment\033[m"
./AbstractVM testcases/invalidTestCases/FileWithComment.avm
echo "\n\033[0;31mFile with no exit\033[m"
./AbstractVM testcases/invalidTestCases/NoExit.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"

echo "\033[0;34mInvalid math usage\033[m"
echo "\033[0;31mdiv by 0\033[m"
./AbstractVM  testcases/invalidTestCases/div0.avm
echo "\033[0;31mmod by 0\033[m"
./AbstractVM testcases/invalidTestCases/mod0.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"

echo "\033[0;34mInvalid operand usage\033[m"
echo "\033[0;31mTest: add\033[m"
./AbstractVM testcases/invalidTestCases/fail_add.avm
echo "\033[0;31m\nTest: sub\033[m"
./AbstractVM testcases/invalidTestCases/fail_sub.avm
echo "\033[0;31m\nTest: mul\033[m"
./AbstractVM testcases/invalidTestCases/fail_mul.avm
echo "\033[0;31m\nTest: div\033[m"
./AbstractVM testcases/invalidTestCases/fail_div.avm
echo "\033[0;31m\nTest: mod\033[m"
./AbstractVM testcases/invalidTestCases/fail_mod.avm

echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"
echo "\033[0;32mCOMPLETED FAIL CASES\033[m\n\n"

echo "\033[0;32mSTARTING VALID TESTS\033[m"
./AbstractVM testcases/valid_tests/all_test.avm
echo "\033[0;32m-----------------------------------------------\033[m"
echo "\nEnding\n\n"