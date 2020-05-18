#include <check.h>

START_TEST(test_tap_successful)
{
	ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_tap_fails)
{
	ck_assert_int_ne(0, 0);
}
END_TEST

static Suite *
suite_tap_new()
{
	Suite *suite_tap = suite_create("suite_tap");
	TCase *case_tap = tcase_create("test_tap");

	tcase_add_test(case_tap, test_tap_successful);
	tcase_add_test(case_tap, test_tap_fails);

	suite_add_tcase(suite_tap, case_tap);
	return suite_tap;
}

int
main()
{
	Suite *suite_tap;
	SRunner *runner_tap;
	int failed;

	suite_tap = suite_tap_new();
	runner_tap = srunner_create(suite_tap);
	srunner_set_tap(runner_tap, "tap.tap");

	srunner_run_all(runner_tap, CK_NORMAL);
	failed = srunner_ntests_failed(runner_tap);

	srunner_free(runner_tap);
	return failed;
}
